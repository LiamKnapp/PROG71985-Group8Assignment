#pragma once
#define MAXSIZE 100

typedef struct calendar {
	int day;
	char  month[MAXSIZE];
	int year;
	char  available[MAXSIZE];
	char  appointment[MAXSIZE];
} CALENDAR, *P_CALENDAR;

//operation functions
char addappointment(P_CALENDAR date);
char deleteappointment(P_CALENDAR date);
char updateappointment(P_CALENDAR date);
char searchappointment(P_CALENDAR date);

//display functions
void display();
char AllAppt(P_CALENDAR date);
char RangeAppt(P_CALENDAR date);
char SingleAppt(P_CALENDAR date);