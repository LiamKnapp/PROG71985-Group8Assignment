#include <stdio.h>
#include <string.h>
#define MAXSIZE 100

typedef struct {
	char  day[MAXSIZE];
	char  month[MAXSIZE];
	char  year[MAXSIZE];
	char  available[MAXSIZE];
	char  appointment[MAXSIZE];
} Calendar;
