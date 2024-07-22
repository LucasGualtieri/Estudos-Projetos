#include <cmath>
#include <iostream>
#include "utils.hpp"
#include "Matrix.hpp"

// clear && g++ minesweeper.cc -std=c++20 && ./a.out

using namespace std;

/* UNKNOWN tiles are the ones the user can click, but are not BOMBS */
#define UNKNOWN 0
#define BOMB -1
#define CLEAR -2 /* CLEAN tiles are the ones with no ajacent bombs */
#define FLAG -3

bool isBomb(int i, int j, Matrix<int> board) {
    return (board.inBounds(i, j)) && board[i][j] == BOMB;
}

void placeBombs(Matrix<int>& m) {

	int bombCount = m.width;

	int i, j;
	while (bombCount > 0) {

		i = randomInt(0, m.height - 1);
		j = randomInt(0, m.width - 1);

		if (m[i][j] != BOMB) {
			m[i][j] = BOMB;
			bombCount--;
		}
	}
}

void generateAdjacencyValues(Matrix<int>& board) {


    for (int i = 0; i < board.height; i++) {
        for (int j = 0; j < board.width; j++) {

            int& tile = board[i][j];

            if (tile != BOMB) {

                tile = 0; // Making sure the value was 0 before starting incrementing

                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 && l == 0) continue;
                        if (isBomb(i + k, j + l, board)) {
                            tile++;
                        }
                    }
                }
            }
        }
    }
}


void revealArea(int i, int j, Matrix<int>& board, Matrix<bool>& visited);

void foo(int i, int j, Matrix<int>& board, Matrix<bool>& visited) {
    revealArea(i - 1, j, board, visited);
    revealArea(i - 1, j - 1, board, visited);
    revealArea(i - 1, j + 1, board, visited);
    revealArea(i + 1, j, board, visited);
    revealArea(i + 1, j - 1, board, visited);
    revealArea(i + 1, j + 1, board, visited);
    revealArea(i, j - 1, board, visited);
    revealArea(i, j + 1, board, visited);
}

void revealArea(int i, int j, Matrix<int>& board, Matrix<bool>& visited) {

	if (board.notInBounds(i, j) || visited[i][j]) return;

	visited[i][j] = true;

	if (board[i][j] == UNKNOWN) board[i][j] = CLEAR;
    // Nem algo no range de 0 a 10 que está sendo um problema.
	if (board[i][j] > 0 && board[i][j] < 10) board[i][j] *= 10;

	else foo(i, j, board, visited);
}

void repositionBomb(int i, int j, Matrix<int>& m) {

	m[i][j] = UNKNOWN;

	srand(time(nullptr));

	int newI, newJ;

	do {
		newI = randomInt(0, m.height - 1);
		newJ = randomInt(0, m.width - 1);
	} while (m.notInBounds(newI, newJ) || m[newI][newJ] == BOMB);

	m[newI][newJ] = BOMB;

	generateAdjacencyValues(m);
}

void removeAdjacentBombs(int i, int j, Matrix<int>& m) {

	// Problema: Uma bomba pode ser colocada no lugar de uma bomba antiga

    if (isBomb(i + 1, j - 1, m)) repositionBomb(i + 1, j - 1, m);
    if (isBomb(i + 1, j + 1, m)) repositionBomb(i + 1, j + 1, m);
	if (isBomb(i + 1, j, m)) repositionBomb(i + 1, j, m);
	if (isBomb(i - 1, j - 1, m)) repositionBomb(i - 1, j - 1, m);
	if (isBomb(i - 1, j, m)) repositionBomb(i - 1, j, m);
	if (isBomb(i - 1, j + 1, m)) repositionBomb(i - 1, j + 1, m);
	if (isBomb(i, j - 1, m)) repositionBomb(i, j - 1, m);
    if (isBomb(i, j + 1, m)) repositionBomb(i, j + 1, m);

	// atribuirOsNumeros(m);
}

// This lambda tests if there are any ajacent bombs
auto isExposed = [](int tile) { return tile > 0; };

void defineInitialSafeArea(int i, int j, Matrix<int>& board) {

	if (board[i][j] == BOMB) repositionBomb(i, j, board);

    // This is necessary to ensure that the first click is on a "clean" tile
	if (isExposed(board[i][j])) removeAdjacentBombs(i, j, board);
    cout << "NEVER GETS HERE" << endl;

	Matrix<bool> visited(board.height, board.width);

	visited[i][j] = true;
	board[i][j] = CLEAR;

    foo(i, j, board, visited);
}

void cliqueDoUsuario(int i, int j, int& tilesToWin, Matrix<int>& board) {

    int& tile = board[i][j];

	if (tile == UNKNOWN) {

		Matrix<bool> visited(board.height, board.width);
		visited[i][j] = true;

        tile = CLEAR;

        foo(i, j, board, visited);
	}

	else if (tile == BOMB) {

        clearScreen();
        cout << board << endl;

		cout << "FIM DE JOGO, VOCÊ PERDEU" << endl;
		exit(0);
	}

    else if (tile < 10) tile *= 10;

    // preciso decrementar os tiles também na função foo (eu acredito).
    tilesToWin--;
}

Matrix<int> initializeBoard(int height, int width) {

    Matrix<int> matrix(height, width);

    placeBombs(matrix);
    generateAdjacencyValues(matrix);

    return matrix;
}

int main() {

	Matrix<int> board = initializeBoard(7, 7);

	int i, j, tilesToWin = board.width * board.height - board.height;

	cout << board.toString(true) << endl;

	// O problema com a leitura "não foi possivel indexar -1" acontece mesmo quando os valores de i e j são lidos corretamente

	try {
        cout << "Digite as coordenadas (i, j): ";

		cin >> i >> j;

		defineInitialSafeArea(i, j, board);
		clearScreen();

		while (true) {
			cout << board.toString(true) << endl;
			// cout << m << endl;
			cout << "Colocar banderinha: 1 - Clicar: 2" << endl;
			cout << "Escolha umas das opções: ";
			int escolha;
			cin >> escolha;

			cout << "Digite as coordenadas (i, j): ";
			cin >> i >> j;

			if (escolha == 1) {

                if (board[i][j] >= 100 || board[i][j] == -1) {
                    board[i][j] -= 100;
                }
                else board[i][j] += 100;
            }

			else cliqueDoUsuario(i, j, tilesToWin, board);

			clearScreen();

            if (tilesToWin == 0) {
                cout << "Você ganhou, parabéns!!!" << endl;
                break;
            }
		}
	}

    #define finally catch(...)

	catch (const string& e) {
		cerr << "Caught exception: " << e << endl;
	} catch (const exception& e) {
		cerr << "Caught standard exception: " << e.what() << endl;
	} finally {
		cerr << "Caught unknown exception" << endl;
	}

	cout << board << endl;

	return 0;
}
