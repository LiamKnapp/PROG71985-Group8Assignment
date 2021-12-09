#define _CRT_SECURE_NO_WARNINGS

#include "UpdateAppt.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Liam Knapp, Andrew Stanley
//PROG71985
//Group Assignment
//Group 8

char updateappointment(P_CALENDAR date, int maxDays) {
	int count, input = 0;
	char appt[MAXSIZE];

	for (count = 0; count < maxDays; count++) { //  displays all current days that have no appointment
		if (strcmp(date[count].available, "Unavailable") == 0) {
			printf("\nDays with appointments are:\n%d, %s", date[count].day, formatWordProperly(date[count].appointment));
		}
	}


	do
	{
		fseek(stdin, 0, SEEK_END);
		printf("\nWhat day would you like to update an appointment for? type 0 to abort: \n");
	} while ((scanf("%d", &input) != 1) || (input < 0) || (input > maxDays));
	fseek(stdin, 0, SEEK_END);

	if (input == ABORT) {// abort if user pressed 0
		fseek(stdin, 0, SEEK_END);
		return 0;
	}

	printf("\nPlease enter your appointment: \n"); // gather the appointment info
	scanf("%[^\n]s", appt);
	fseek(stdin, 0, SEEK_END);

	formatWordProperly(appt);

	strcpy(date[input - LINENUM].appointment, &appt); // update the appointment
	printf("\nAppointment updated\n");

	return 0;
}