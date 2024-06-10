#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "Matrix.hpp"

// clear && g++ minesweeper.cc -std=c++20 && ./a.out

using namespace std;

// Bombas = -1
// Vazio desconhecido = 0
// Vazio conhecido = -2
// bandeirinha = -3

#define BOMB -1

int randomInt(int min, int max) {
	int random = rand();
	return (rand() % ((max + 1) - min)) + min;
}

void posicionarBombas(Matrix<int>& m) {

	// srand(0);
	srand(time(nullptr));

	int bombas = m.width;

	int i, j;
	while (bombas > 0) {

		i = randomInt(0, m.height - 1);
		j = randomInt(0, m.width - 1);

		if (m[i][j] != BOMB) {
			m[i][j] = BOMB;
			bombas--;
		}
	}
}

// int atribuirValor(int i, int j, Matrix<int>& m) {
// 	return (!m.inBounds(i, j) || m[i][j] == BOMB) ? 1 : 0;
// }

int atribuirValor(int i, int j, Matrix<int>& m) {
	if (!m.inBounds(i, j)) return 0;
	return m[i][j] == BOMB ? 1 : 0;
}

void atribuirOsNumeros(Matrix<int>& m) {
	for (int i = 0; i < m.height; i++) {
		for (int j = 0; j < m.width; j++) {
			// Otimizar isso com um for?
			if (m[i][j] != BOMB) {
				m[i][j] = 0;
				m[i][j] += atribuirValor(i - 1, j - 1, m);
				m[i][j] += atribuirValor(i - 1, j, m);
				m[i][j] += atribuirValor(i - 1, j + 1, m);
				m[i][j] += atribuirValor(i + 1, j - 1, m);
				m[i][j] += atribuirValor(i + 1, j, m);
				m[i][j] += atribuirValor(i + 1, j + 1, m);
				m[i][j] += atribuirValor(i, j - 1, m);
				m[i][j] += atribuirValor(i, j + 1, m);
			}
		}
	}
}

void floodFill(int i, int j, Matrix<int>& m, Matrix<bool>& visitados) {

	if (!m.inBounds(i, j) || visitados[i][j]) return;

	visitados[i][j] = true;

	if (m[i][j] == 0) m[i][j] = -2;
	if (m[i][j] > 0) m[i][j] *= 10;

	else {
		floodFill(i - 1, j, m, visitados);
		floodFill(i - 1, j - 1, m, visitados);
		floodFill(i - 1, j + 1, m, visitados);
		floodFill(i + 1, j, m, visitados);
		floodFill(i + 1, j - 1, m, visitados);
		floodFill(i + 1, j + 1, m, visitados);
		floodFill(i, j - 1, m, visitados);
		floodFill(i, j + 1, m, visitados);
	}
}

void reposicionarBomba(int i, int j, Matrix<int>& m) {

	m[i][j] = 0;

	srand(time(nullptr));

	int newI, newJ;
	do {
		newI = randomInt(0, m.height - 1);
		newJ = randomInt(0, m.width - 1);
	} while (!m.inBounds(newI, newJ) || m[newI][newJ] == BOMB);

	m[newI][newJ] = BOMB;

	atribuirOsNumeros(m);
}

void removerBombasAdjacentes(int i, int j, Matrix<int>& m) {

	// Problema: Uma bomba pode ser colocada no lugar de uma bomba antiga

	if (m[i + 1][j - 1] == BOMB) reposicionarBomba(i + 1, j - 1, m);
	if (m[i + 1][j] == BOMB) reposicionarBomba(i + 1, j, m);
	if (m[i + 1][j + 1] == BOMB) reposicionarBomba(i + 1, j + 1, m);
	if (m[i - 1][j - 1] == BOMB) reposicionarBomba(i - 1, j - 1, m);
	if (m[i - 1][j] == BOMB) reposicionarBomba(i - 1, j, m);
	if (m[i - 1][j + 1] == BOMB) reposicionarBomba(i - 1, j + 1, m);
	if (m[i][j - 1] == BOMB) reposicionarBomba(i, j - 1, m);
	if (m[i][j + 1] == BOMB) reposicionarBomba(i, j + 1, m);

	// atribuirOsNumeros(m);
}

void definirAreaSegura(int i, int j, Matrix<int>& m) {

	if (m[i][j] == BOMB) reposicionarBomba(i, j, m);

	// cout << m << endl;

	if (m[i][j] > 0) removerBombasAdjacentes(i, j, m);

	// cout << m << endl;

	Matrix<bool> visitados(m.height, m.width);

	visitados[i][j] = true;
	m[i][j] = -2;

	floodFill(i - 1, j, m, visitados);
	floodFill(i - 1, j - 1, m, visitados);
	floodFill(i - 1, j + 1, m, visitados);
	floodFill(i + 1, j, m, visitados);
	floodFill(i + 1, j - 1, m, visitados);
	floodFill(i + 1, j + 1, m, visitados);
	floodFill(i, j - 1, m, visitados);
	floodFill(i, j + 1, m, visitados);
}

void cliqueDoUsuario(int i, int j, Matrix<int>& m) {

	if (m[i][j] == 0) {

		Matrix<bool> visitados(m.height, m.width);
		visitados[i][j] = true;

		floodFill(i - 1, j, m, visitados);
		floodFill(i - 1, j - 1, m, visitados);
		floodFill(i - 1, j + 1, m, visitados);
		floodFill(i + 1, j, m, visitados);
		floodFill(i + 1, j - 1, m, visitados);
		floodFill(i + 1, j + 1, m, visitados);
		floodFill(i, j - 1, m, visitados);
		floodFill(i, j + 1, m, visitados);
	}

	else if (m[i][j] == BOMB) {
		cout << "FIM DE JOGO" << endl;
		exit(0);
	}

	else {
		if (abs(m[i][j]) >= 100) m[i][j] /= 100;
		else m[i][j] *= 10;
	}
}

void clearScreen() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif defined(__unix__) || defined(__APPLE__) || defined(__linux__)
        system("clear");
    #else
        cout << "Clear screen not supported on this OS" << endl;
    #endif
}

int main() {

	Matrix<int> m(10, 10);

	posicionarBombas(m);

	atribuirOsNumeros(m);

	int i, j;

	cout << m.toString(true) << endl;

	// O problema com a leitura "não foi possivel indexar -1" acontece mesmo quando os valores de i e j são lidos corretamente

	try {
		cout << "Digite as coordenadas (i, j): ";
		cin >> i >> j;
		definirAreaSegura(i, j, m);
		clearScreen();

		while (true) {
			cout << m.toString(true) << endl;
			// cout << m << endl;
			cout << "Colocar banderinha: 1 - Clicar: 2" << endl;
			cout << "Escolha umas das opções: ";
			int escolha;
			cin >> escolha;

			cout << "Digite as coordenadas (i, j): ";
			cin >> i >> j;

			if (escolha == 1) m[i][j] *= 100;

			else cliqueDoUsuario(i, j, m);
			
			clearScreen();
		}
	}
	
	catch (const string& e) {
		cerr << "Caught exception: " << e << endl;
	} catch (const exception& e) {
		cerr << "Caught standard exception: " << e.what() << endl;
	} catch (...) {
		cerr << "Caught unknown exception" << endl;
	}


	// cout << m << endl;

	return 0;
}