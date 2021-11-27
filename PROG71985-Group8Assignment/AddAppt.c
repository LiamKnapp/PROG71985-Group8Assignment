#define _CRT_SECURE_NO_WARNINGS

#include "Data.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LINENUM 1
#define ABORT 0
#define MAXDAYSINMONTH 30

char addappointment(P_CALENDAR date) { // books an appointment
	int  count, input = 0;
	char appt[MAXSIZE];
	char monthchoice[100];

	printf("What Month would you like to set this appointment for? \n"); // gather what month to add an appointment to
	printf("type your month now. remember Capital letters matter: \n");
	printf("so far we only have November\n");
	scanf("%s", &monthchoice);
	fseek(stdin, 0, SEEK_END);

	if (strcmp(monthchoice, "November") == 0) {
		for (count = 0; count < MAXDAYSINMONTH; count++) { //  displays all current days that have no appointment
			if (strcmp(date[count].available, "Available") == 0) {
				printf("\nDays with no appointments in November are:\n%s", date[count].day);
			}
		}
	}

	printf("\nWhat day would you like to add a appointment to? type 0 to abort: \n");
	scanf("%d", &input);

	if (input == ABORT) {// abort if user pressed 0
		fseek(stdin, 0, SEEK_END);
		return;
	}

	printf("\nEnter your first appointment: \n"); // gather the appointment info
	scanf("%s", &appt);
	fseek(stdin, 0, SEEK_END);

	strcpy(date[input - LINENUM].appointment, &appt); // add appointment
	strcpy(date[input - LINENUM].available, "Unavailable"); // make date tag as Unavailable
	printf("\nbook complete\n");

	return 0;
}