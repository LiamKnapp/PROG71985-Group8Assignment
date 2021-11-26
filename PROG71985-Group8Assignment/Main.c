#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "Data.h"
#include "Structure.c"
#include "AddAppt.c"
#include "DeleteAppt.c"
#include "DisplayAppts.c"
#include "SearchAppt.c"
#include "UpdateAppt.c"

#define LINENUM 1
#define ABORT 0
#define MAXDAYSINMONTH 30

bool continueprogram = true;// loop for the program
FILE* fp; // declare the file

char display() { // print the display / main menu without the option f
	printf("\nTo choose a function, enter its letter label: \n");
	printf("a) Add a new appt \n");
	printf("b) Delete an existing appt \n");
	printf("c) Update and existing appt \n");
	printf("d) Display single appt \n");
	printf("e) Display range appt \n");
	printf("f) Display all appt \n");
	printf("g) Search for appt \n");
	printf("h) Exit \n");

	return 0;
}

int main(void) {
	char Select;
	int count = 0;

	Calendar date[MAXSIZE];

	FILE* fp = fopen("calendar.txt", "r+"); // read the file with saved data
	if (fp == NULL) { // if error close
		printf("ERROR");
		exit(ABORT);
	}
	while (fscanf(fp, "%s %s %s %s %s", date[count].day, date[count].month, date[count].year,date[count].available, date[count].appointment) != EOF) {
		count++; // save the file information into my struct
	}
	fclose(fp);

	while (continueprogram == true) {
		display();

		scanf("%c", &Select); // get the user selection

		if (Select == 'a') { // Add a new appt
			addappointment(date);
		}

		if (Select == 'b') { // Delete an existing appt
			deleteappointment(date);
		}

		if (Select == 'c') { //  Update and existing appt
			
		}

		if (Select == 'd') { // Display single appt
			SingleAppt(date);
		}

		if (Select == 'e') { //Display range appt
			RangeAppt(date);
		}

		if (Select == 'f') { // Display all appt
			AllAppt(date);
		}

		if (Select == 'g') { // Search for appt
		
		}

		if (Select == 'h') { // Exit the program
			printf("\n");
			continueprogram = false;
		}

		FILE* fp = fopen("calendar.txt", "r+"); // open the file again for saving
		if (fp == NULL) { // if error close
			printf("ERROR");
			exit(ABORT);
		}
		for (count = 0; count < MAXDAYSINMONTH; count++) { // print new information into the file for saving
			fprintf(fp, "%d %s %s %s\n", count + LINENUM, &date[count].month, &date[count].year, &date[count].appointment);
		}
		fclose(fp); // save file by closeing
	}
	
}