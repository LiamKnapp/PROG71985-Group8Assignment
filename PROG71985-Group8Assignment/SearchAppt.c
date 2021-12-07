#define _CRT_SECURE_NO_WARNINGS
#include "Data.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LINENUM 1
#define ABORT 0
#define MAXDAYSINMONTH 30

char searchappointment(P_CALENDAR date) {

    char apptsearch[MAXSIZE];

    printf("Please enter the appointment you would like to find the day for: ");
    scanf("%s", &apptsearch); // get the appointment the user is searching for
    fseek(stdin, 0, SEEK_END);
    printf("\n");

    for (int count = 0; count < MAXDAYSINMONTH; count++) {
        if ((strcmp(date[count].appointment, apptsearch) == 0) && (strcmp(date[count].available, "Unavailable") == 0)) // compare the file with the search the user input
        {
            printf("This appointment is on: \n");
            printf("%d, %s, %d\n", date[count].year, date[count].month, date[count].day);
        }
        if ((strcmp(date[count].appointment, apptsearch) != 0) && (count == MAXDAYSINMONTH - 1)) {
            printf("There is no matching appointment for this month. \n");
        }
    }

    return 0;
}