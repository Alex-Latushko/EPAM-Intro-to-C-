#include <stdio.h>
#include <string.h>

#define SIZE 20

static void getstr(char* str, char* result){
	printf("Enter %s: \n", str);
	scanf("%s", str);
	strncat(result, str, SIZE);
	strncat(result, " ", 2);
}

int main() {
	char first_name[SIZE] = "second name";
	char second_name[SIZE] = "first name";
	char fathers_name[SIZE] = "father's name";
	char result[4*SIZE] = {0};

	getstr(second_name, result);
	getstr(first_name, result);
	getstr(fathers_name, result);

	printf("Result: %s", result);
	return 0;
}
