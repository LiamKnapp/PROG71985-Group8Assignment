#define _CRT_SECURE_NO_WARNINGS

#include "Data.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LINENUM 1
#define ABORT 0
#define MAXDAYSINMONTH 30

char deleteappointment(P_CALENDAR date) { // books an appointment
	int  count, input = 0;
	char appt[MAXSIZE];

	fseek(stdin, 0, SEEK_END);

	
		for (count = 0; count < MAXDAYSINMONTH; count++) { //  displays all current days that have no appointment
			if (strcmp(date[count].available, "Unavailable") == 0) {
				printf("\nDays with appointments are:\n%s", date[count].day);
			}
		}

	printf("\nWhat day would you like to remove a appointment from? type 0 to abort: \n");
	scanf_s("%d", &input);
	fseek(stdin, 0, SEEK_END);

	if (input == ABORT) {// abort if user pressed 0
		fseek(stdin, 0, SEEK_END);
		return 0;
	}


	strcpy(date[input - LINENUM].appointment, "NA"); // remove the appointment
	strcpy(date[input - LINENUM].available, "Available"); // make day tag as available
	printf("\nBook removed\n");

	return 0;
}