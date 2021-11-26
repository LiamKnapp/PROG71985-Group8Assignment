#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
#define MAXROOMS 12

typedef struct {
	char   roomid[MAXROOMS];
	char  available[MAXSIZE];
	char  firstname[MAXSIZE];
	char  lastname[MAXSIZE];
} Room;
