#pragma once
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