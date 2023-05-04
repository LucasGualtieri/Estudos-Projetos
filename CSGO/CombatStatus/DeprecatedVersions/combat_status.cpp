#include "D:\Lucas\PUC\AED\workspace\C.CPP\Bibliotecas\biblioteca_cpp.h"

int DmgTaken(string String) {
	for (int i = 0; i < String.length(); i++) {
		if (String.at(i) >= '0' && String.at(i) <= '9') {
			// cout << String.substr(i, i + 2) << endl;
			try {
				// cout << stoi(String.substr(i, i + 2)) << endl;
				return stoi(String.substr(i, i + 2));
			} catch (exception& e) { }
		}
	}
	return 0;
}

string CurrentDamager(string String) {

	int enemyNameLength = 2;

	for (int i = 0; String.at(i + 19) != '"'; i++) {
		enemyNameLength++;
	}

	// cout << String.substr(18, enemyNameLength) << endl;

	return String.substr(18, enemyNameLength);
}

int main() {
	SetConsoleOutputCP(65001);

	fstream fileIn;
	fileIn.open("in.txt", ios::in);

	string str;
	string enemyName;
	string strGiven = "Damage Given to";
	string strTaken = "Damage Taken from";
	int totalKills = 0;
	int totalDeaths = 0;
	int totalDmgTaken = 0;

	fileIn >> enemyName; // Skips the first line, the name of the target.
	strGiven.append(" ").append(enemyName);
	strTaken.append(" ").append(enemyName);

	getline(fileIn, str), getline(fileIn, str); // Skips the big line.

	string lastDamager;

	while (!fileIn.eof()) {

		// Reading Damage Given
		if (!str.compare(0, strGiven.length(), strGiven)) {
			if (stoi(str.substr(strGiven.length() + 3)) >= 100) {
				totalKills++;
			}
		}

		// Reading Damage Taken
		if (!str.substr(0, strTaken.length() - enemyName.length()).compare(strTaken.substr(0, strTaken.length() - enemyName.length()))) {
			// Soma o dano levado entre todos os attackers
			totalDmgTaken += DmgTaken(str.substr(str.length() - 14, str.length()));

			if (str.compare(strTaken.length() - enemyName.length(), strTaken.length(), enemyName)) {
				lastDamager = CurrentDamager(str);
			}

			if (!str.compare(0, strTaken.length(), strTaken)) { // Dmg Taken form Enemy
				if (stoi(str.substr(strTaken.length() + 3)) >= 100) {
					totalDeaths++;
				} else if (lastDamager == enemyName && totalDmgTaken >= 100) {
					totalDeaths++;
				}
			}
		}

		getline(fileIn, str);

		if (str == "-------------------------") {
			totalDmgTaken = 0;
		}
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