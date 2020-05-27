#include "String_class.h"

void String::set_str(const char str2[]){
	free_p(&str);
	str = (char*)calloc(strlen(str2) + 1, sizeof(char));
	if (str){
		strncpy(str, str2, length = strlen(str2));
	}
}

char* String::get_str(void) const{
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
	}
}

String::String(const String& str2){
	str = (char*)calloc(str2.len() + 1, sizeof(char));
	if (str){
		strncpy(str, str2.str, length = str2.len());
	}
}

String& String::operator=(const String& str2){
	if (this != &str2){
		free_p(&str);

		str = (char*)calloc(str2.len() + 1, sizeof(char));
		if (str){
			strncpy(str, str2.str, length = str2.len());
		}
	}
	return *this;
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



