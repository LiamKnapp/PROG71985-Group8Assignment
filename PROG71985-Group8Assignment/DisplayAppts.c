#define _CRT_SECURE_NO_WARNINGS
#include "Data.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LINENUM 1
#define ABORT 0
#define MAXDAYSINMONTH 30

char AllAppt(P_CALENDAR date) { // displays all appointments

	fseek(stdin, 0, SEEK_END);

	printf("Days in (this month) with appointments are: \n");
	for (int count = 0; count < MAXDAYSINMONTH; count++) {
		if (strcmp(date[count].available, "Unavailable") == 0) { // if day has the tag as Unavailable 
			printf("%d, %s, %d: %s\n", date[count].year, date[count].month, date[count].day, date[count].appointment);
		}
	}

	return 0;
}

char RangeAppt(P_CALENDAR date) { // displays all appointments

	int firstDay = 0;
	int lastDay = 0;

	printf("Please enter the first day of the range: ");
	scanf("%d", &firstDay);
	fseek(stdin, 0, SEEK_END);
	printf("Please enter the last day of the range: ");
	scanf("%d", &lastDay);
	fseek(stdin, 0, SEEK_END);
	printf("\n");

	for (int count = 0; count < MAXDAYSINMONTH; count++) {
		if (((count + 1 >= firstDay) && (count + 1 <= lastDay)) && (strcmp(date[count].available, "Unavailable") == 0))
			printf("%d, %s, %d: %s\n", date[count].year, date[count].month, date[count].day, date[count].appointment);
	}

	return 0;
}

char SingleAppt(P_CALENDAR date) { // displays all appointments

	int dayChoice = 0;
	printf("Please enter the number of the day you would like the appointment displayed for: ");
	scanf("%d", &dayChoice);
	fseek(stdin, 0, SEEK_END);
	printf("\n");

	for (int count = 0; count < MAXDAYSINMONTH; count++) {
		if ((dayChoice == count + 1) && (strcmp(date[count].available, "Available") == 0)) // if day has the tag as Unavailable 
			printf("There are no appointments booked on that day.\n");
		else if ((dayChoice == count + 1) && (strcmp(date[count].available, "Unavailable") == 0))
		{
			printf("The appointment for this day is: \n");
			printf("%d, %s, %d: %s\n", date[count].year, date[count].month, date[count].day, date[count].appointment);
		}
	}
	return 0;
}