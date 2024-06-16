#ifndef DATE_UTILS_H
#define DATE_UTILS_H

#include <stdbool.h>

#define ANO_ATUAL 2024

typedef struct {
	int dia, mes, ano;
} Date;

bool isLeapYear(int year);
bool isValidDate(int day, int month, int year);
bool isValidFormat(char *date);
Date getDateInput();

#endif