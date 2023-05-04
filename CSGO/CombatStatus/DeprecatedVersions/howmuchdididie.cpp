#include "D:\Lucas\PUC\AED\workspace\C.CPP\Bibliotecas\biblioteca_cpp.h"

int main() {
	SetConsoleOutputCP(65001);

	fstream fileIn;
	fileIn.open("in.txt", ios::in);

	string str;
	string enemyName;
	string dmgGiven = "Damage Given to";
	string dmgTaken = "Damage Taken from";
	string dmgGivenTarget;
	string dmgTakenTarget;
	int totalKills = 0;
	int totalDeaths = 0;

	fileIn >> enemyName; // Skips the first line, the name of the target.
	dmgGivenTarget.append(dmgGiven).append(" ").append(enemyName);
	dmgTakenTarget.append(dmgTaken).append(" ").append(enemyName);

	getline(fileIn, str), getline(fileIn, str); // Skips the big line.

	while (!fileIn.eof()) {
		int totalDmgTaken = 0;
		string lastDamager;

		getline(fileIn, str); // Skips the big line.

		// Reading damage given
		// cout << "------ Reading Damage Given ------" << endl;
		while (!fileIn.eof()) {
			// cout << str << endl;

			if (!str.compare(0, dmgGivenTarget.length(), dmgGivenTarget)) {
				if (stoi(str.substr(dmgGivenTarget.length() + 3)) >= 100) {
					// cout << "Killing Target" << endl;
					totalKills++;
				}
			}

			if (str == "-------------------------") {
				fileIn >> str;
				break;
			}

			getline(fileIn, str);
			// Sleep(1000);
		}

		// Reading damage taken
		// cout << "------ Reading Damage Taken ------" << endl;
		while (str != "-------------------------" && !fileIn.eof()) {
			cout << str << endl;

			// Testa os nomes dos attackers
			try {
				if (str.at(0) == '"') {
					if (str != "\"cl_crosshairsize\"" && str != "\"999\"" && str != "\"5\"") {
						lastDamager = str;
					}
				}
			} catch (exception& e) {
				if (fileIn.eof()) break;
			}

			// Soma o dano levado entre todos os attackers
			try {
				totalDmgTaken += stoi(str);
				getline(fileIn, str);
			} catch (exception& e) {
				fileIn >> str;
			}

			// if (str != "Player:") continue;
			// Essa verificação só pode acontecer se o último damager for o target
			if (lastDamager == enemyName && totalDmgTaken >= 100) {
				totalDeaths++;
				getline(fileIn, str), getline(fileIn, str);
				break;
			}
			// Sleep(500);
		}

		// cout << "TotalDmTaken: " << totalDmgTaken << endl;
		// exit(0);
	}

	fileIn.close();

	int totalInteractions = totalKills + totalDeaths;

	cout << "Total confirmed kills: " << totalKills << endl;
	cout << "Total confirmed deaths: " << totalDeaths << endl;
	cout << "Total interactions: " << totalInteractions << endl;

	fstream fileOut;
	fileOut.open("out.txt", ios::out);

	fileOut << "Total confirmed kills: " << totalKills << endl;
	fileOut << "Total confirmed deaths: " << totalDeaths << endl;
	fileOut << "Total interactions: " << totalInteractions << endl;

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}