#ifndef _STRING_

#define _STRING_

#include "String.h"
#include <iostream>
#include <cctype>
#include <limits.h>
#include "string.h"

//	Constructors and Destructor--------------------------------------

String::String()
//	Default constructor.
{
	str = nullptr;
	length = 0;
	capacity = 0;
};

String::String(const char* _str)
//	Constructor takes a pointer to a C-Style string.
{
	length = strlen(_str);
	capacity = length + 1;
	str = new char[capacity];
	strcpy_s(str, capacity, _str);
};

String::String(const String& _other)
//	Copy Constructor.
{
	length = _other.length;
	capacity = _other.capacity;
	str = new char[capacity];
	strcpy_s(str, capacity, _other.str);
};

String::~String()
//	Destructor.
{
	delete[] str;
};

//	Methods/Functions-------------------------------------------------

size_t String::Length() const
//	Returns the number of Char in the String.
{
	return length;
};

char& String::CharacterAt(size_t _index)
//	Returns a reference to the char at index "_index" of the 
//	string, starting at 0.
{
	if (_index < 0 || _index > length)
	{
		static char nullChar = '\0';
		return nullChar;
	}
	else
	{
		return str[_index];
	}
};

const char& String::CharacterAt(size_t _index) const
//	Returns a reference to the char at index "_index" of the 
//	string, starting at 0.
{
	if (_index < 0 || _index > length)
	{
		static char nullChar = '\0';
		return nullChar;
	}
	else
	{
		return str[_index];
	}
};

bool String::EqualTo(const String& _other) const
//	Returns true if all char values in the char array pointer
//	*str are the same, returns true. Otherwise returns false.
{
	if (strcmp(str, _other.str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
};

bool String::EqualTo(char *_str) const
//	Returns true if all char values in the char array pointer
//	*str are the same, returns true. Otherwise returns false.
{
	for (int i = 0; i < length; i++)
	{
		if (_str[i] != str[i])
		{
			return false;
		}
	}
	
	return true;
	
};


String& String::Append(const String& _str)
//	Appends the argument string to the called string.
{
	length += _str.Length();

	if ((length + 1) > capacity)
	{

		char* newStr = new char[length + 1];
		strcpy_s(newStr, length + 1, str);
		delete[] str;

		capacity = (_str.length + length + 1);
		str = new char[capacity + 1];
		strcpy_s(str, capacity, newStr);
		delete[] newStr;
	}

	strcat_s(str, capacity, _str.str);

	return *this;

}

String& String::Prepend(const String& _str)
//	Prepends the argument string to the called string.
{
	length += _str.Length();
	if ((length + 1) > capacity)
	{
		char* newStr = new char[length + 1];
		strcpy_s(newStr, length + 1, str);
		delete[] str;

		capacity = (_str.length + length + 1);
		str = new char[capacity + 1];
		strcpy_s(str, capacity, newStr);
		delete[] newStr;
	}

	char* strHolder = new char[length + 1];
	strcpy_s(strHolder, length + 1, str);

	strcpy_s(str, capacity, _str.str);
	Append(strHolder);
	delete[] strHolder;

	return *this;
}

const char* String::CStr() const
//	Returns the char value at the first index of *str.
{
	return str;
};


String& String::ToLower()
//	Converts the string to lower case.
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i] = std::tolower(str[i]);
	}

	return *this;

};

String& String::ToUpper()
//	Converts the string to upper case.
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i] = std::toupper(str[i]);
	}

	return *this;

};

int String::Find(const String& _str)
/*
	Function attempts to locate _str inside str, and if sucessful
	returns the index there the sub-string is found. If uncessful,
	returns "-1".
*/
{
	return Find(0, _str);
};

int String::Find(size_t _startIndex, const String& _str)
/*
	Function attempts to locate _str inside str, and if sucessful
	returns the index there the sub-string is found. If uncessful,
	returns "-1".

	Nope that this function originally returned a size_t var
	which cannot be signed (+/-), however it has been altered
	to retun a int var so that "-1" can be returned as an error
	code.

	This should not affect functinality unless an str array of
	size 2147483647, which is accounted for in the for-loop
	below.
*/
{
	size_t _len_t = _str.Length();

	int _len = static_cast<int>(_len_t);

	if (_len > length)
	{
		return -1;
	}
	else
	{
		for (
			size_t i = _startIndex;
			i < length - (_str.length - 1) && i < INT_MAX;
			i++)
		{
			if (strncmp(str + i, _str.str, _str.length) == 0)
			{
				return i;
			}
		}
	}

	return -1;

};


String& String::Replace(const String& _find, const String& _replace)
{
	/*
		Function finds and replaces a sub-string within *str with
		a new substring. Replaces all instances of this substring.

		Note that this function does not account for characters that
		are represented in more than one substring, for example, the
		sub-string "ABAB" could conceptually be identified in the
		string "ABABAB" either twice at index 0 and 2, or only once
		at index 0. This function would use the latter definition
		when replacing sub-strings.
	*/

	// Define Vars

	int numberOfInstances = 0;
	int loc = -1;
	int prevLoc = -1;
	int count = 0;

	size_t repLen = _replace.Length();
	size_t finLen = _find.Length();

	// Determines how many sub-strings need to be replaced.

	while (Find(count, _find) != -1)
	{
		loc = Find(count, _find);

		if (loc != prevLoc)
		{
			numberOfInstances++;
			prevLoc = loc;
		}
		count += repLen;
	}

	//	Calculates the new size of the str array and updates values.

	length += (numberOfInstances * (repLen - finLen));
	capacity = length + 1;
	char* nStr = new char[capacity];

	//	Writes updated string into temporary pointer array.

	size_t j = 0;
	for (size_t i = 0; i < length; i++)
	{
		loc = Find(j, _find);

		if (j != loc)
		{
			nStr[i] = str[j];
		}
		else {
			for (size_t k = 0; k < repLen; k++)
			{
				nStr[i] = _replace.str[k];
				i++;
			}
			i--;
			j = j + _find.Length() - 1;
		}
		j++;
	}
	nStr[length] = '\0';

	//	Replaces old str with new str and mannages memmory.

	delete str;
	str = new char[capacity];
	strcpy_s(str, capacity, nStr);
	delete[] nStr;

	return *this;

};

String& String::ReadFromConsole()
{
	/*
		Reads a stream of input from console and converts that
		into a String.

		Note, this is unable to take strings longer than 63 char
		long.
	*/

	char* inStr = new char[64];

	std::cout << "Type new string into command line: ";
	std::cin >> inStr;

	length = strlen(inStr);
	if (capacity < length + 1)
	{
		capacity = length + 1;
		delete str;
		str = new char[capacity];
	}
	strcpy_s(str, capacity, inStr);
	delete[] inStr;

	return *this;

};

String& String::WriteToConsole()
//	Writes the contents of *str to console
{
	std::cout << str;

	return *this;

};

//	Operator Overloads -----------------------------------------------

bool String::operator==(const String& _other)
//	Overloads the == operator to return true if lhs and rhs objects
//	char arrays contain the same values.
{
	return EqualTo(_other);
};

bool String::operator!=(const String& _other)
//	Overloads the != operator to return true if lhs and rhs objects
//	char arrays do not contain the same values.
{
	return !EqualTo(_other);
};

String& String::operator=(const String& _str)
//	Overloads the = operator to copy the rhs object to the lhs object.
{
	length = _str.length;
	capacity = _str.capacity;

	delete str;
	str = new char[capacity];
	//strcpy_s(str, capacity, _str.str);

	//
	for (int i = 0; i < length; i++)
	{
		str[i] = _str[i];
	}
	str[length] = '\0';

	return *this;

};

char& String::operator[](size_t _index)
//	Overloads the [] operator to return the char at the index entered
//	into the square brackets.
{
	return str[_index];
};

const char& String::operator[](size_t _index) const
//	Overloads the [] operator to return the char at the index entered
//	into the square brackets as a const.
{
	return str[_index];
};

//	Optional Functionality-------------------------------------------

String String::operator+(const String& _rhs)
//	Overloads + to return a new string created by appending the lhs with 
//	the rhs.
{
	size_t rLen = _rhs.Length();
	size_t j = 0;

	char* newPtr = new char[rLen + length + 1];

	for (size_t i = 0; i < length; i++)
	{
		newPtr[j] = str[i];
		j++;
	}

	for (size_t i = 0; i < rLen; i++)
	{
		newPtr[j] = _rhs.str[i];
		j++;
	}

	newPtr[length + rLen] = '\0';

	String outputString(newPtr);
	delete[] newPtr;

	return outputString;
}

String& String::operator+=(const String& _rhs)
//	Overloads += to appends the lhs with the rhs.
{
	*this = *this + _rhs;

	return *this;

}

#endif _STRING_