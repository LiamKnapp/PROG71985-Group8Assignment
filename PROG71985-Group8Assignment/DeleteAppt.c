#define _CRT_SECURE_NO_WARNINGS

#include "Data.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Liam Knapp, Andrew Stanley
//PROG71985
//Group Assignment
//Group 8

char deleteappointment(P_CALENDAR date) { // books an appointment
	int  count, input = 0;
	char appt[MAXSIZE];

	fseek(stdin, 0, SEEK_END);

	
	for (count = 0; count < MAXDAYSINMONTH; count++) { //  displays all current days that have no appointment
		if (strcmp(date[count].available, "Unavailable") == 0) {
			printf("\nDays with appointments are:\n%d", date[count].day);
			fseek(stdin, 0, SEEK_END);
		}
	}

	do
	{
		fseek(stdin, 0, SEEK_END);
		printf("\nWhat day would you like to remove an appointment from? type 0 to abort: \n");
	} while ((scanf("%d", &input) != 1) || (input < 0) || (input > MAXDAYSINMONTH));
	fseek(stdin, 0, SEEK_END);

	if (input == ABORT) {// abort if user pressed 0
		fseek(stdin, 0, SEEK_END);
		return 0;
	}

	if (strcmp(date[input - LINENUM].available, "Available") == 0)
	{
		printf("\nThat day already does not have an appointment.\n");
		return;
	}

	strcpy(date[input - LINENUM].appointment, "NA"); // remove the appointment
	strcpy(date[input - LINENUM].available, "Available"); // make day tag as available
	printf("\nBooking removed\n");

	return 0;
}