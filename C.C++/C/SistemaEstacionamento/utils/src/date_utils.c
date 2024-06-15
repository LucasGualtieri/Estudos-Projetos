#include "date_utils.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// Definição das funções conforme o código fornecido anteriormente

int isLeapYear(int year) {
    if (year % 400 == 0) {
        return 1;
    } else if (year % 100 == 0) {
        return 0;
    } else if (year % 4 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int isValidDate(int day, int month, int year) {
    if (year < 0 || month < 1 || month > 12 || day < 1) {
        return 0;
    }

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (isLeapYear(year) && month == 2) {
        daysInMonth[1] = 29;
    }

    if (day > daysInMonth[month - 1]) {
        return 0;
    }

    return 1;
}

int isDigit(char c) {
    return c >= '0' && c <= '9';
}

int isValidFormat(char *date) {
    if (strlen(date) != 10) {
        return 0;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) {
            if (date[i] != '/') {
                return 0;
            }
        } else {
            if (!isDigit(date[i])) {
                return 0;
            }
        }
    }

    return 1;
}

void getDateInput(char *date) {
    while (1) {
        printf("Digite uma data (dd/mm/yyyy): ");
        scanf("%s", date);

        if (isValidFormat(date)) {
            int day = atoi(date);
            int month = atoi(date + 3);
            int year = atoi(date + 6);

            if (isValidDate(day, month, year)) {
                printf("Data válida: %02d/%02d/%04d\n", day, month, year);
                break;
            } else {
                printf("Data inválida. Por favor, tente novamente.\n");
            }
        } else {
            printf("Formato inválido. Por favor, tente novamente.\n");
        }
    }
}
