#include <stdio.h>
#include <string.h>

#define SIZE 20
int main() {
	char str[SIZE] = {0};

	puts("Enter string:");
	scanf("%s", str);

	for (size_t i = 0; i < strlen(str); ++i){
		if ( (str[i] >= '0') && (str[i] <= '9') ){
			if ((str[i] - '0') % 2 == 0){
				printf("%c\n", str[i]);
			}
		}
	}

	return 0;
}
