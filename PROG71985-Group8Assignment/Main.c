#define _CRT_SECURE_NO_WARNINGS

#include "Data.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LINENUM 1
#define ABORT 0
#define MAXDAYSINMONTH 30

int main(void) {
	char Monthchoice[MAXSIZE], txt[MAXSIZE] = ".txt";

	bool continueprogram = true;// loop for the program
	CALENDAR date[MAXSIZE];

	do
	{
		printf("What month to add/look/change information to?\nRemember capital letters matter: \n");
		scanf("%s", Monthchoice); // get the user month choice
		fseek(stdin, 0, SEEK_END);

		strcat(Monthchoice, txt); // add '.txt' to the end of the user monthchoice

		menuFunction(Monthchoice, date);
	} while (Monthchoice == 'Exit');
}

void menuFunction(char Monthchoice[], P_CALENDAR date)
{
	char Select = "";
	int count = 0;

	FILE* fp = fopen(Monthchoice, "r"); // read the file with saved data
	if (fp == NULL) { // if error close
		printf("ERROR");
		exit(ABORT);
	}

	while (fscanf(fp, "%d %s %d %s %s", &date[count].day, date[count].month, &date[count].year, date[count].available, date[count].appointment) != EOF) {
		count++; // save the file information into the struct
	}


	fclose(fp);
	do
	{

		display();

		scanf("%c", &Select); // get the user selection

		if (Select == 'a') // Add a new appt
			addappointment(date);

		if (Select == 'b') // Delete an existing appt
			deleteappointment(date);

		if (Select == 'c') //  Update and existing appt
			updateappointment(date);

		if (Select == 'd') // Display single appt
			SingleAppt(date);

		if (Select == 'e') //Display range appt
			RangeAppt(date);

		if (Select == 'f') // Display all appt
			AllAppt(date);

		if (Select == 'g') // Search for appt
			searchappointment(date);

	} while (Select != 'h');

	fp = fopen("calendar.txt", "w+"); // open the file again for saving
	if (fp == NULL) { // if error close
		printf("ERROR");
		exit(ABORT);
	}
	for (count = 0; count < MAXDAYSINMONTH; count++) { // print new information into the file for saving
		fprintf(fp, "%d %s %d %s %s\n", count + LINENUM, date[count].month, &date[count].year, date[count].available, date[count].appointment);
	}
	fclose(fp); // save file by closeing
}

void display() { // print the display
	printf("\nTo choose a function, enter its letter label: \n");
	printf("a) Add a new appt \n");
	printf("b) Delete an existing appt \n");
	printf("c) Update and existing appt \n");
	printf("d) Display single appt \n");
	printf("e) Display range appt \n");
	printf("f) Display all appt \n");
	printf("g) Search for appt \n");
	printf("h) Exit \n");
}