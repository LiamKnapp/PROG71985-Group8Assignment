#define _CRT_SECURE_NO_WARNINGS

#include "Data.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LINENUM 1
#define ABORT 0
#define MAXDAYSINMONTH 30

//Liam Knapp, Andrew Stanley
//PROG71985
//Group Assignment
//Group 8

char updateappointment(P_CALENDAR date) {
	int count, input = 0;
	char appt[MAXSIZE];

	for (count = 0; count < MAXDAYSINMONTH; count++) { //  displays all current days that have no appointment
		if (strcmp(date[count].available, "Unavailable") == 0) {
			printf("\nDays with appointments are:\n%d, %s", date[count].day, date[count].appointment);
		}
	}


	printf("\nWhat day would you like to update a appointment for? type 0 to abort: \n");
	scanf_s("%d", &input);
	fseek(stdin, 0, SEEK_END);
	fseek(stdin, 0, SEEK_END);

	if (input == ABORT) {// abort if user pressed 0
		fseek(stdin, 0, SEEK_END);
		return 0;
	}

	printf("\nEnter your appointment: \n"); // gather the appointment info
	scanf("%s", appt);
	fseek(stdin, 0, SEEK_END);

	strcpy(date[input - LINENUM].appointment, &appt); // update the appointment
	printf("\nAppointment updated\n");

	return 0;
}