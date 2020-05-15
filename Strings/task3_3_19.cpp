#include <stdio.h>
#include <string.h>

#define SIZE_OF_TEXT 1000

int main() {
	char ch;
	char amount_of_char[256] = {0};
	char text[SIZE_OF_TEXT]= {0};

	puts("Enter text:");
	fgets(text, SIZE_OF_TEXT - 2, stdin);
	text[strlen(text)-1] = '\0';

	for (size_t i = 0; i < strlen(text); ++i){
		ch = text [i];
		amount_of_char[(int)ch]++;
	}

	for (size_t i = 0; i < 256; ++i){
		if (amount_of_char[i] != 0) {
			printf ("Amount of char \'%c\' (ASCII code %d) is : %d\n", (char)i, i, amount_of_char[i]);
		}
	}
	return 0;
}
