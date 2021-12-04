#define _CRT_SECURE_NO_WARNINGS
#include "Data.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LINENUM 1
#define ABORT 0
#define MAXDAYSINMONTH 30

char AllAppt(P_CALENDAR date) { // displays all appointments
	
	fseek(stdin, 0, SEEK_END);

	
		for (int count = 0; count < MAXDAYSINMONTH; count++) {
			if (strcmp(date[count].available, "Unavailable") == 0) { // if day has the tag as Unavailable 
				printf("%d, %s, %d: %s\n", &date[count].year, date[count].month, &date[count].day, date[count].appointment);
			}
		}

	return 0;
}

char RangeAppt(P_CALENDAR date) { // displays all appointments

	
	return 0;
}

char SingleAppt(P_CALENDAR date) { // displays all appointments

	

	return 0;
}