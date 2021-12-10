#pragma once
// Group Assignment - Calendar/ appointment manager
// PROG71985 - F21
// Liam Knapp, Andrew Stanley - Group 8 - Dec 2021
#define MAXSIZE 100
#define LINENUM 1
#define ABORT 0

typedef struct calendar {
	int day;
	char  month[MAXSIZE];
	int year;
	char  available[MAXSIZE];
	char  appointment[MAXSIZE];
} CALENDAR, *P_CALENDAR;