#include <stdio.h>
#include <string.h>

#define SIZE 20

int main() {
	char word[SIZE] = {0};
	bool is_palindrom = true;


	printf("Enter word\n");
	scanf("%s", word);

	int from_end =  strlen(word) - 1;
	for (size_t from_begin = 0;
			word[from_begin] != '\0' && from_end > 0;
			++from_begin, --from_end){

		if (word[from_begin] != word[from_end]){
			is_palindrom = false;
		}
	}

	printf ("Word \"%s\" is %s.\n", word, is_palindrom ? "palindrome" : "not a palindrome");
	return 0;
}
