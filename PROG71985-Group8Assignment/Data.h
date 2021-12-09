#pragma once
#define MAXSIZE 100
#define LINENUM 1
#define ABORT 0
#define MAXDAYSINMONTH 31

typedef struct calendar {
	int day;
	char  month[MAXSIZE];
	int year;
	char  available[MAXSIZE];
	char  appointment[MAXSIZE];
} CALENDAR, *P_CALENDAR;

//operation functions
char addappointment(P_CALENDAR date, int);
char deleteappointment(P_CALENDAR date, int);
char updateappointment(P_CALENDAR date, int);
char searchappointment(P_CALENDAR date, int);

//display functions
void display();
void menuFunction(char Monthchoice[], P_CALENDAR date);
char AllAppt(P_CALENDAR date, int);
char RangeAppt(P_CALENDAR date, int);
char SingleAppt(P_CALENDAR date, int);

//clean text functions
char* formatWordProperly(char word[]);

//Setting days in month
int setMaxDays(char Monthchoice[]);