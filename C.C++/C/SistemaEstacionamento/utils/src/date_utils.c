#include "../include/date_utils.h"
#include "../include/user_input.h"

bool isAnoBissexto(int year) {

	if (year % 400 == 0) return true;

	else if (year % 100 == 0) return false;

	else if (year % 4 == 0) return true;

	else return false;
}

bool isValidDate(int day, int month, int year) {

	if (year < 0 || month < 1 || month > 12 || day < 1) return false;

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (isAnoBissexto(year) && month == 2) daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1]) return false;

	return true;
}

int isDigit(char c) {
	return c >= '0' && c <= '9';
}

bool isValidFormat(char *date) {

	if (strlen(date) != 10) return false;

	for (int i = 0; i < 10; i++) {

		if (i == 2 || i == 5) {
			if (date[i] != '/') return false;
		}

		else if (!isDigit(date[i])) return false;
	}

	return true;
}

Date getDateInput(String str) {

	String dateInput;
	Date date;

	while (true) {

		dateInput = readString(0, str);

		if (isValidFormat(dateInput)) {

			int dia = atoi(dateInput);
			int mes = atoi(dateInput + 3);
			int ano = atoi(dateInput + 6);

			if (isValidDate(dia, mes, ano)) {
				// printf("Data válida: %02d/%02d/%04d\n", day, month, year);
				date.dia = dia;
				date.mes = mes;
				date.ano = ano;

				break;
			}

			else printf("Data inválida. Por favor, tente novamente.\n");
		}

		else printf("Formato inválido. Por favor, tente novamente.\n");
	}

	return date;
}
