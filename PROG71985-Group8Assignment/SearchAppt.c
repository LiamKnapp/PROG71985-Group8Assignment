#define _CRT_SECURE_NO_WARNINGS

#include "SearchAppt.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

//Liam Knapp, Andrew Stanley
//PROG71985
//Group Assignment
//Group 8

char searchappointment(P_CALENDAR date, int maxDays) {
    fseek(stdin, 0, SEEK_END);
    char apptsearch[MAXSIZE];
    bool apptFound = false;

    printf("Please enter the appointment you would like to find the day for: ");
    scanf("%[^\n]s", &apptsearch); // get the appointment the user is searching for
    fseek(stdin, 0, SEEK_END);
    printf("\n");

    for (int count = 0; count < maxDays; count++) {
        

        //if the user search is in the list
        if ((strcmp(date[count].appointment, formatWordProperly(apptsearch)) == 0) && (strcmp(date[count].available, "Unavailable") == 0))
        {
            printf("This appointment is on: \n");
            printf("%d, %s, %d\n", date[count].year, date[count].month, date[count].day);
            apptFound = true;
        }

        //if the user list is not in the list
        if ((strcmp(date[count].appointment, formatWordProperly(apptsearch)) != 0) && (count == maxDays - 1) && (apptFound == false))
        {
            printf("There is no matching appointment for this month. \n");
        }
    }

	return 0;
}