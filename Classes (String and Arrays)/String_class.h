#pragma once
#include <iostream>
#include <string.h>

class String{
	private:
	char* str;
	int length;

	public:
	String();
	String(const char* str2);
	String(const String& str2);

	void set_str(const char* str2);
	const char* get_str(void) const;
	int len() const;
	void show() const;

	String& operator=(const char* str2);
	String& operator=(const String& str2);

	String& operator+=(const char* str2);
	String& operator+=(const String& str2);

	bool operator==(const char* str2) const;
	bool operator==(const String& str2) const;

	bool operator!=(const char* str2) const;
	bool operator!=(const String& str2) const;

	bool operator<(const char* str2) const;
	bool operator<(const String& str2) const;

	bool operator>(const char* str2) const;
	bool operator>(const String& str2) const;

	~String();
};

template <typename T>
void free_p(T** p);
