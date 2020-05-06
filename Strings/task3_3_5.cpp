#include <stdio.h>

#define SIZE 100

int main() {
	char str[SIZE] = {0};
	int amount_of_words = 0;
	bool out_of_word = true;

	puts("Enter sentence:");
	fgets(str, SIZE -2, stdin);

	for (int i = 0; str[i] != '\n'; ++i){
		if (str[i] == ' '){
			out_of_word = true;
		} else if (out_of_word){
			++amount_of_words;
			out_of_word = false;
		}
	}

	printf("Amount_of_words: %d", amount_of_words);
	return 0;
}
