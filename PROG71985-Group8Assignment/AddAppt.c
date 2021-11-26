#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "Structure.c"

#define LINENUM 1
#define ABORT 0
#define MAXDAYSINMONTH 30

char addappointment(Calendar* date) { // books an appointment
	int  count, input = 0;
	char appt[MAXSIZE];
	for (count = 0; count < MAXDAYSINMONTH; count++) { //  displays all current days that have no appointment
		if (strcmp(date[count].available, "Available") == 0) {
			printf("\nDays with no appointments are:\n%s", date[count].day);
		}
	}

	printf("\nWhat day would you like to add a appointment to? type 0 to abort: \n");
	scanf("%d", &input);

	if (input == ABORT) {// abort if user pressed 0
		display();// print the display
		return 0;
	}

	printf("\nEnter your first appointment: \n"); // gather the appointment info
	scanf("%s", &appt);

	strcpy(date[input - LINENUM].appointment, &appt); // add appointment
	strcpy(date[input - LINENUM].available, "Unavailable"); // make date tag as Unavailable
	printf("\nbook complete\n");

	display();
	return 0;
}