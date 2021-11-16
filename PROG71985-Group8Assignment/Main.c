#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "Structure.c"

#define _CRT_SECURE_NO_WARNINGS
#define LINENUM 1
#define ABORT 0

bool continueprogram = true;// loop for the program
FILE* fp; // declare the file

char display() { // print the display / main menu without the option f
	printf("\nTo choose a function, enter its letter label: \n");
	printf("a)  \n");
	printf("b)  \n");
	printf("c)  \n");
	printf("d)  \n");
	printf("e) \n");

	return 0;
}
int main(void) {
	char Select;
	int count = 0;

	Room rooms[MAXSIZE];

	FILE* fp = fopen("Roominfo.txt", "r+"); // read the file with saved data
	if (fp == NULL) { // if error close
		printf("ERROR");
		exit(ABORT);
	}
	while (fscanf(fp, "%s %s %s %s ", rooms[count].roomid, rooms[count].available, rooms[count].firstname, rooms[count].lastname) != EOF) {
		count++; // save the file information into my struct
	}
	fclose(fp);

	while (continueprogram == true) {
		display();

		scanf("%c", &Select); // get the user selection

		if (Select == 'a') { // 
			
		}

		if (Select == 'b') { // 
			
		}

		if (Select == 'c') { // 
			
		}

		if (Select == 'd') { //
			
		}

		if (Select == 'e') { //
			
		}

		if (Select == 'f') { // exit the program
			printf("\n");
			continueprogram = false;
		}

		FILE* fp = fopen("Roominfo.txt", "r+"); // open the file again for saving
		if (fp == NULL) { // if error close
			printf("ERROR");
			exit(ABORT);
		}
		for (count = 0; count < MAXROOMS; count++) { // print new information into the file for saving
			fprintf(fp, "%d %s %s %s\n", count + LINENUM, &rooms[count].available, &rooms[count].firstname, &rooms[count].lastname);
		}
		fclose(fp); // save file by closeing
	}
}