#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int getinput(char data[], int dim, unsigned int par, unsigned int par2); //prototype of function

int main(void) {

	char str[5]; //create our string for input

	int c = 0; //create bool var for do while loop

	do {

		printf("Write an input > ");

		c = !getinput(str, sizeof str, 0, 3); //catch bool value from getinput function and store it in c var

		if (c) { //check c var and printf a message if is true (1)
			printf("Input is not valid! > Try again!\n\n");
		}

	} while(c); //cycle until c var becomes false (0)

	printf("Input is valid! > %s\n", str); //print out string

	return 1;

}

int getinput(char data[], int dim, unsigned int par, unsigned int par2) {

	char buffer[255]; //create a buffer string

	if (fgets(buffer, sizeof buffer, stdin) != NULL) { //read input using fgets
		int x = strlen(buffer); //get buffer's actual char lenght

		if (buffer[0] == '\n') { //check if only enter was entered
			return 0;
		}

		if (x > dim) { //check if buffer could be stored into data string
			return 0;
		}

		if (par > 0) { //check if buffer has minimum amount of chars
			if (x - 1 < par) {
				return 0;
			}
		}

		if (par2 > 0) { //check if par2 var is bigger than 0 and check buffer for certain requirements

			int i;

			switch (par2) {
				case 1:
					for (i = 0; i < strlen(buffer) && buffer[i] != '\n' && buffer[i] != '\0'; i++){
						if (!isalpha(buffer[i])) { //check if buffer contains only alphabetic chars
							return 0;
						}
					}
					break;
				case 2:
					for (i = 0; i < strlen(buffer) && buffer[i] != '\n' && buffer[i] != '\0'; i++){
						if (!isdigit(buffer[i])) { //check if buffer contains only number chars
							return 0;
						}
					}
					break;
				case 3:
					for (i = 0; i < strlen(buffer) && buffer[i] != '\n' && buffer[i] != '\0'; i++){
						if (!isalnum(buffer[i])) { //check if buffer contains only alphanumeric chars
							return 0;
						}
					}
					break;
				default:
					return 0;
					break;
			}
		}

		strncpy(data, buffer, dim); //if buffer pass all checks, copy buffer to data

		data[strcspn(data, "\n")] = 0; //remove newline char

		return 1;

	}
	else {
		printf("\n\nERROR!\n\n"); //print a error message if cannot get input
	}

	return 0; //and return false (0)

}
