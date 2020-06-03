#include "String_class.h"

void String::set_str(const char str2[]){
	free_p(&str);
	str = (char*)calloc(strlen(str2) + 1, sizeof(char));
	if (str){
		strncpy(str, str2, length = strlen(str2));
	}
}

const char* String::get_str(void) const{
	return str;
}

int String::len() const{
	return length;
}

void String::show() const{
	if (str){
	std::cout << str << std::endl;
	}
}

String::String(){
	str = NULL;
	length = 0;
}

String::String(const char* str2){
	str = (char*)calloc(strlen(str2) + 1, sizeof(char));
	if (str){
		strncpy(str, str2, length = strlen(str2));
		length = strlen(str);
	}
}

String::String(const String& str2){
	str = (char*)calloc(str2.len() + 1, sizeof(char));
	if (str){
		strncpy(str, str2.str, length = str2.len());
		length = strlen(str);
	}
}

String& String::operator=(const char* str2){
	free_p(&str);
	str = (char*)calloc(strlen(str2) + 1, sizeof(char));
	if (str){
		strncpy(str, str2, length = strlen(str2));
		length = strlen(str);
	}
	return *this;
}

String& String::operator=(const String& str2){
	if (this != &str2){
		*this = str2.str;
	}
	return *this;
}

String& String::operator+=(const char* str2){
	if (str){
		str = (char*)realloc(str, (length +strlen(str2) + 1) * sizeof(char));
		if (str){
			strncat(str, str2, length = strlen(str2));
			length = strlen(str);
		}
	}else {
		*this = (str2);
	}
	return *this;
}

String& String::operator+=(const String& str2){
	*this += str2.str;
	return *this;
}


bool String::operator==(const char* str2) const{
	if (str){
		return strcmp(str, str2) == 0 ? true : false;
	}
	return false;
}

bool String::operator==(const String& str2) const{
	if (str){
		return *this == str2.str;
	}
	return false;
}


bool String::operator!=(const char* str2) const{
	return !(*this == str2);
}


bool String::operator!=(const String& str2) const{
	return !(*this == str2);
}



bool String::operator<(const char* str2) const{
	if (str){
		return strcmp(str, str2) < 0 ? true : false;
	}
	return false;
}

bool String::operator<(const String& str2) const{
	if (str){
		return *this < str2.str;
	}
	return false;
}



bool String::operator>(const char* str2) const{
	if (str){
		return strcmp(str, str2) > 0 ? true : false;
	}
	return false;
}

bool String::operator>(const String& str2) const{
	if (str){
		return *this > str2.str;
	}
	return false;
}

String::~String(){
	free_p(&str);
}

template <typename T>
void free_p(T** p){
	if (*p != NULL){
		free(*p);
		*p = NULL;
	}
}
