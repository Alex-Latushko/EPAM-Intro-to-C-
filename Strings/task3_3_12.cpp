#include <stdio.h>
#include <string.h>

#define SIZE 100
#define WORD_SIZE 20

int count_word(char str[], char word[]){
	int amount_of_word = 0;
	for (char* pchar = strstr(str, word); pchar != NULL; pchar = strstr(pchar, word)){
			++amount_of_word;
			++pchar;
		}
	return amount_of_word;
}

int main() {
	char str[SIZE] = {0};
	char word[WORD_SIZE] = {0};

	puts("Enter sentence");
	fgets(str, SIZE - 2, stdin);

	puts("Enter word");
	fgets(word, WORD_SIZE - 2, stdin);
	word[strlen(word)-1] = '\0';


	printf("Amount of word in sentence is: %d\n", count_word(str, word));
	return 0;
}
