#ifndef DATE_UTILS_H
#define DATE_UTILS_H

int isLeapYear(int year);
int isValidDate(int day, int month, int year);
int isValidFormat(char *date);
void getDateInput(char *date);

#endif // DATE_UTILS_H
