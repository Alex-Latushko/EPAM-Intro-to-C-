#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 20

static bool is_in_range(size_t size, size_t x){
	return ( (x >= 0) &&
			 (x <= size) );
}

void delete_char_in_str(char* str, size_t position){
	if (!is_in_range(strlen(str), position)){
		printf("Index in \"delete_char_in_str\" is out of range!\n");
		exit(1);
	}

	size_t i = 0;
	for (i = position; i < strlen(str) - 1; ++i){
		str[i] = str [i + 1];
	}
	str[i] = '\0';
}

void get_number_from_str(char str[], int& number, char split){
	int i = 0;
	for (i = 0; str[i] != split && str[i] != '\0'; ++i ){
		if ( (str[i] >= '0') && (str[i] <= '9') ){
			number *= 10;
			number += str[i] - '0';
		}
	}
	++i;
	while ( (i > 0) && (str[0] != '\0') ){
		delete_char_in_str(str, 0);
		--i;
	}
}

int main() {
	char str[SIZE] = {0};//"09/05/1945";
	char split = '/';
	const char* months[12] = {"January", "February", "March", "April", "May", "June",
						 "July", "August", "September", "October", "November", "December"};
	struct date{
		int day;
		int month;
		int year;
	} dt = {0};

	puts("Enter date in dd/mm/year format:");
	scanf("%s", str);

	get_number_from_str(str, dt.day, split);
	get_number_from_str(str, dt.month, split);
	if ( (dt.month > 12) or (dt.month == 0) ){
		puts("Invalid number of the month!");
		exit(1);
	}

	get_number_from_str(str, dt.year, split);

	printf("%dth of the %s, %d year", dt.day, months[dt.month - 1], dt.year);

	return 0;
}
