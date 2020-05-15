#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 20

const char* decades[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const char* value[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
	"Ten", "Eleven", "Twelve", "Thirteen" "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const char* powers[4] = {" ", " Thousands ", " Millions ", " Billions "};

void str_to_number(char str[], long long& number, char split){
	int i = 0;
	for (i = 0; str[i] != split && str[i] != '\0'; ++i ){
		if ( (str[i] >= '0') && (str[i] <= '9') ){
			number *= 10;
			number += str[i] - '0';
		}
	}
}

void number_to_words(char* result, int number){
	int temp = 0;
	temp = number/100;
	if (temp != 0){
		strncat(result, value[temp], SIZE);
		if (temp == 1){
			strncat(result, " Hundred ", SIZE);
		} else {
			strncat(result, " Hundreds ", SIZE);
		}
	}

	temp = number%100;
	if (temp < 20){
		result = strncat(result, value[temp], SIZE);
	} else {
		result = strncat(result, decades[temp/10], SIZE);
		result = strncat(result, " ", 2);
		result = strncat(result,value[temp%10], SIZE);
	}
}

int main() {
	char str_number[SIZE] = {0};
	char add_str[5 * SIZE] = {0};
	char result_str[15 * SIZE] = {0};
	long long number = 0;

	printf("Enter number (from 0 to 999 999 999 999):");
	scanf("%s", str_number);
	str_to_number(str_number, number, '\0');

	if ((number < 0) || (number > 999999999999)){
		puts("Out of range!");
		exit(1);
	}

	int power = strlen(str_number) - 1;
	do{
		number_to_words(add_str, number / pow(10, power - ( power % 3 )));
		strncat(result_str, add_str, 5 * SIZE);
		strncat(result_str, powers[power / 3], SIZE);
		number = number % (int)pow(10, power - ( power % 3 ));
		power = ( power - 3 >= 0 ) ? power - 3 : 0;
		add_str[0] = 0; // to clean the add_str
	} while (number > 0);

	printf("\n%s\n", result_str);

	return 0;
}
