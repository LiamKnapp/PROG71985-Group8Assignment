// Group Assignment - Calendar/ appointment manager
// PROG71985 - F21
// Liam Knapp, Andrew Stanley - Group 8 - Dec 2021

#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void menuFunction(char Monthchoice[], P_CALENDAR date)			//WORKED TOGETHER
{
	char Select = "";
	int count = 0;
	int maxDays = setMaxDays(Monthchoice);

	FILE* fp = fopen(Monthchoice, "r"); // read the file with saved data
	do
	{
		if  ((fp == NULL) && (strcmp(Monthchoice, "Exit.txt") != 0)) { // if error close
			printf("\nImproper month name entered\n\n");
			return;
		}

		if (strcmp(Monthchoice, "Exit.txt") == 0)
			exit(0);

		while (fscanf(fp, "%d %s %d %s %[^\n]s", &date[count].day, date[count].month, &date[count].year, date[count].available, date[count].appointment) != EOF) {
			count++; // save the file information into the struct
		}

		fclose(fp);

		display();

		scanf("%c", &Select); // get the user selection

		if (Select == 'a') // Add a new appt
			addappointment(date, maxDays);

		else if (Select == 'b') // Delete an existing appt
			deleteappointment(date, maxDays);

		else if (Select == 'c') //  Update and existing appt
			updateappointment(date, maxDays);

		else if (Select == 'd') // Display single appt
			SingleAppt(date, maxDays);

		else if (Select == 'e') //Display range appt
			RangeAppt(date, maxDays);

		else if (Select == 'f') // Display all appt
			AllAppt(date, maxDays);

		else if (Select == 'g') // Search for appt
			searchappointment(date, maxDays);

	} while (Select != 'h');

	fp = fopen(Monthchoice, "w+"); // open the file again for saving
	if (fp == NULL) { // if error close
		printf("ERROR");
		exit(ABORT);
	}
	for (count = 0; count < maxDays; count++) { // print new information into the file for saving
		fprintf(fp, "%d %s %d %s %s\n", count + LINENUM, date[count].month, date[count].year, date[count].available, date[count].appointment);
	}
	fclose(fp); // save file by closeing
}

void display() { // print the display
	printf("\nTo choose a function, enter its letter label: \n");
	printf("a) Add a new appointment \n");
	printf("b) Delete an existing appointment \n");
	printf("c) Update an existing appointment \n");
	printf("d) Display a single day's appointment \n");
	printf("e) Display a range of days' appointments \n");
	printf("f) Display all appointments \n");
	printf("g) Search for an appointment \n");
	printf("h) Return to menu \n");
}