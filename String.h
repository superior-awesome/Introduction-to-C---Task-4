#pragma once
#ifndef CUSTOM_STRING_HEADER
#define CUSTOM_STRING_HEADER
class String
{
public:
	String();
	String(const char* _str);
	String(const String& _other);
	~String();
public:
	size_t Length() const;
	char& CharacterAt(size_t _index);
	const char& CharacterAt(size_t _index) const;
	bool EqualTo(const String& _other) const;
	bool EqualTo(char* _str) const;
	String& Append(const String& _str);
	String& Prepend(const String& _str);
	const char* CStr() const;
	String& ToLower();
	String& ToUpper();
	int Find(const String& _str);
	int Find(size_t _startIndex, const String& _str);
	String& Replace(const String& _find, const String& _replace);
	String& ReadFromConsole();
	String& WriteToConsole();
public:
	bool operator==(const String& _other);
	bool operator!=(const String& _other);
	String& operator=(const String& _str);
	char& operator[](size_t _index);
	const char& operator[](size_t _index) const;

public:
	String operator+(const String& _rhs);
	String& operator+=(const String& _other);
private:
	char* str;
	size_t length;
	size_t capacity;
};
#endif