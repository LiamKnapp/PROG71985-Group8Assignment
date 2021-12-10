// Group Assignment - Calendar/ appointment manager
// PROG71985 - F21
// Liam Knapp, Andrew Stanley - Group 8 - Dec 2021

#define _CRT_SECURE_NO_WARNINGS

#include "SearchAppt.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

char searchappointment(P_CALENDAR date, int maxDays) {      //LIAM KNAPP
    fseek(stdin, 0, SEEK_END);
    char apptsearch[MAXSIZE];
    bool apptFound = false;
    bool firstRun = true;

    printf("Please enter the appointment you would like to find the day for: ");
    scanf("%[^\n]s", &apptsearch); // get the appointment the user is searching for
    fseek(stdin, 0, SEEK_END);
    printf("\n");

    for (int count = 0; count < maxDays; count++) {

        //if the user search is in the list
        if ((strcmp(date[count].appointment, formatWordProperly(apptsearch)) == 0) && (strcmp(date[count].available, "Unavailable") == 0))
        {
            if (firstRun)
            {
                printf("This appointment is on: \n");       //Only print this the first time they have this appointment (in cases of appointments with the same name on different days)
                firstRun = false;
            }
            printf("%d, %s, %d\n", date[count].year, date[count].month, date[count].day);
            apptFound = true;
        }

        //if the user search is not in the list
        if ((strcmp(date[count].appointment, formatWordProperly(apptsearch)) != 0) && (count == maxDays - 1) && (!apptFound))
        {
            printf("There is no matching appointment for this month. \n");
        }
    }

	return 0;
}