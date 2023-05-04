#include <biblioteca_cpp.h>

// clear && gcc combat_status.c -o combat_status && ./combat_status < pub.in > out.txt

bool hasDied(string fileInput, string enemyName, fstream& fileIn) {
	int totalDmgTaken = 0;
	string lastDamager;

	while (fileInput.substr(0, 17) == "Damage Taken from") {
		// Soma o dano levado entre todos os attackers
		totalDmgTaken += stoi(fileInput.substr(fileInput.find("\" - ") + 4));
		lastDamager = fileInput.substr(19, fileInput.substr(19).find("\""));

		getline(fileIn, fileInput);
	}

	if (lastDamager == enemyName && totalDmgTaken >= 100) {
		return true;
	}

	return false;
}

bool hasKilled(string fileInput, string enemyName, fstream& fileIn) {

	string aux = fileInput.substr(0, 16) + "\"" + enemyName + "\"";

	while (fileInput.substr(0, aux.length()) == aux) {
		if (stoi(fileInput.substr(aux.length() + 3)) >= 100) {
			return true;
		}
		getline(fileIn, fileInput);
	}

	return false;
}

void printResults(int totalKills, int totalDeaths) {
	int totalInteractions = totalKills + totalDeaths;

	cout << "Total kills: " << totalKills << endl;
	cout << "Total deaths: " << totalDeaths << endl;
	cout << "Total interactions: " << totalInteractions;

	fstream fileOut;
	fileOut.open("out.txt", ios::out);

	fileOut << "Total kills: " << totalKills << endl;
	fileOut << "Total deaths: " << totalDeaths << endl;
	fileOut << "Total interactions: " << totalInteractions;
}

int main() {

	string fileInput, enemyName;
	int totalKills = 0, totalDeaths = 0;

	fstream fileIn;
	fileIn.open("in.txt", ios::in);

	fileIn >> enemyName; // Skips the first line, the name of the enemy.

	while (!fileIn.eof()) {

		// Checking if enemy changed name
		string enemyChangedName = "* " + enemyName + " changed name to";

		if (fileInput.substr(0, 18 + enemyName.length()) == enemyChangedName) {
			enemyName = fileInput.substr(19 + enemyName.length());
		}

		if (fileInput.substr(0, 15) == "Damage Given to") {
			// Reading Damage Given
			if (hasKilled(fileInput, enemyName, fileIn)) totalKills++;
		} else if (fileInput.substr(0, 17) == "Damage Taken from") {
			// Reading Damage Taken
			if (hasDied(fileInput, enemyName, fileIn)) totalDeaths++;
		}

		getline(fileIn, fileInput);
	}

	fileIn.close();

	printResults(totalKills, totalDeaths);

	cout << "\n\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}