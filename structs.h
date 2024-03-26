#pragma once
#ifndef _STRUCTS_

#define _STRUCTS_

class Vector2 {
	
public:
	int a;
	int b;

	void operator=(Vector2 _input)
	{
		a = _input.a;
		b = _input.b;
	}

	void operator+=(Vector2 _input)
	{
		a = a + _input.a;
		b = b + _input.b;
	}
	
	void operator-=(Vector2 _input)
	{
		a = a - _input.a;
		b = b - _input.b;
	}
	
	Vector2 operator+(Vector2 _input)
	{
		Vector2 temp;
		temp.a = a + _input.a;
		temp.b = b + _input.b;
		return temp;
	}
	
	Vector2 operator-(Vector2 _input)
	{
		Vector2 temp;
		temp.a = a - _input.a;
		temp.b = b - _input.b;
		return temp;
	}
	
};

#endif