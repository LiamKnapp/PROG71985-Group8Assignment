// Group Assignment - Calendar/ appointment manager
// PROG71985 - F21
// Liam Knapp, Andrew Stanley - Group 8 - Dec 2021

#define _CRT_SECURE_NO_WARNINGS

#include "DisplayAppts.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char AllAppt(P_CALENDAR date, int maxDays) { // Displays all appointments			ANDREW STANLEY	

	fseek(stdin, 0, SEEK_END);
	bool firstRun = true;

	for (int count = 0; count < maxDays; count++) {
		if (strcmp(date[count].available, "Unavailable") == 0) { // if the day has an appointment
			if (firstRun)
			{
				printf("\nDays with appointments are: \n");
				firstRun = false;
			}
			printf("%d, %s, %d: %s\n", date[count].year, date[count].month, date[count].day, formatWordProperly(date[count].appointment));
		}
	}
	if (firstRun)	 //If it has made it here with no change on firstRun's status, there were no appointments in the month
		printf("\nThere are no appointments schdeduled in this month.\n");

	return 0;
}

char RangeAppt(P_CALENDAR date, int maxDays) { // displays a range of appointments

	int firstDay = 0;
	int lastDay = 0;

	do
	{
		fseek(stdin, 0, SEEK_END);
		printf("Please enter the first day of the range (type 0 to abort): ");
	} while ((scanf("%d", &firstDay) != 1) || (firstDay < ABORT) || (firstDay > maxDays));
	fseek(stdin, 0, SEEK_END);

	if (firstDay == ABORT) {// abort if user pressed 0
		fseek(stdin, 0, SEEK_END);
		return;
	}

	do
	{
		fseek(stdin, 0, SEEK_END);
		printf("Please enter the last day of the range (type 0 to abort): ");
	} while ((scanf("%d", &lastDay) != 1) || (lastDay < ABORT) || (lastDay > maxDays));
	fseek(stdin, 0, SEEK_END);
	printf("\n");

	if (lastDay == ABORT) {// abort if user pressed 0
		fseek(stdin, 0, SEEK_END);
		return;
	}

	if (firstDay > lastDay)
	{
		printf("The first day of the range must be lower than the last day of the range.\n ");
		return;
	}

	for (int count = 0; count < maxDays; count++) {
		if (((count + 1 >= firstDay) && (count + 1 <= lastDay)) && (strcmp(date[count].available, "Unavailable") == 0))
			printf("%d, %s, %d: %s\n", date[count].year, date[count].month, date[count].day, formatWordProperly(date[count].appointment));
	}

	return 0;
}

char SingleAppt(P_CALENDAR date, int maxDays) { // displays a chosen appointment

	int dayChoice = 0;
	do
	{
		fseek(stdin, 0, SEEK_END);
		printf("Please enter the number of the day you would like the appointment displayed for (type 0 to abort): ");
	} while ((scanf("%d", &dayChoice) != 1) || (dayChoice < ABORT) || (dayChoice > maxDays));
	fseek(stdin, 0, SEEK_END);
	printf("\n");

	if (dayChoice == ABORT) {// abort if user pressed 0
		fseek(stdin, 0, SEEK_END);
		return 0;
	}

	for (int count = 0; count < maxDays; count++) {
		if ((dayChoice == count + 1) && (strcmp(date[count].available, "Available") == 0)) // if day has the tag as Unavailable 
			printf("There are no appointments booked on that day.\n");
		else if ((dayChoice == count + 1) && (strcmp(date[count].available, "Unavailable") == 0))
		{
			printf("The appointment for this day is: \n");
			printf("%d, %s, %d: %s\n", date[count].year, date[count].month, date[count].day, formatWordProperly(date[count].appointment));
		}
	}
	return 0;
}