#define _CRT_SECURE_NO_WARNINGS
#include "Data.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LINENUM 1
#define ABORT 0
#define MAXDAYSINMONTH 30

char AllAppt(P_CALENDAR date) { // displays all appointments
	char monthchoice[100];

	printf("What Month would you like to display the appointment for? \n"); // gather what month to add an appointment to
	printf("Type your month now. Remember Capital letters matter: \n");
	printf("so far we only have November\n");
	scanf("%s", &monthchoice);
	fseek(stdin, 0, SEEK_END);

	if (strcmp(monthchoice, "November") == 0) {
		for (int count = 0; count < MAXDAYSINMONTH; count++) {
			if (strcmp(date[count].available, "Unavailable") == 0) { // if day has the tag as Unavailable 
				printf("%s, %s, %s: %s\n", date[count].year, date[count].month, date[count].day, date[count].appointment);
			}
		}
	}

	return 0;
}

char RangeAppt(P_CALENDAR date) { // displays all appointments

	
	return 0;
}

char SingleAppt(P_CALENDAR date) { // displays all appointments

	

	return 0;
}