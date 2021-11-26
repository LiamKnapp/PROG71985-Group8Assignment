#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "Structure.c"

#define LINENUM 1
#define ABORT 0
#define MAXDAYSINMONTH 30

char deleteappointment(Calendar* date) { // books an appointment
	int  count, input = 0;
	char appt[MAXSIZE];
	char monthchoice[100];

	printf("What Month would you like to remove the appointment from? \n"); // gather what month to add an appointment to
	printf("Type your month now. Remember Capital letters matter: \n");
	printf("so far we only have November\n");
	scanf("%s", &monthchoice);

	if (strcmp(monthchoice, "November") == 0) {
		for (count = 0; count < MAXDAYSINMONTH; count++) { //  displays all current days that have no appointment
			if (strcmp(date[count].available, "Unavailable") == 0) {
				printf("\nDays with appointments are:\n%s", date[count].day);
			}
		}
	}

	printf("\nWhat day would you like to remove a appointment from? type 0 to abort: \n");
	scanf_s("%d", &input);

	if (input == ABORT) {// abort if user pressed 0
		display();// print the display
		return 0;
	}


	strcpy(date[input - LINENUM].appointment, "NA"); // remove the appointment
	strcpy(date[input - LINENUM].available, "Available"); // make day tag as available
	printf("\nRoom Listing removed\n");

	display();
	return 0;
}