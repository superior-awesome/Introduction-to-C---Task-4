#pragma once
#ifndef _STRUCTS_

#define _STRUCTS_

class Vector2 {
	
public:
	int a;
	int b;

	Vector2() = default;

	Vector2(int _a, int _b)
	{
		a = _a;
		b = _b;
	}

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

class Doors
{
public:
	bool North;
	bool South;
	bool East;
	bool West;
	int numberOfDoors;

	Doors()
	{
		North = true;
		South = true;
		East = true;
		West = true;
		CountDoors();
	};

	Doors(bool input)
	{
		North = input;
		South = input;
		East = input;
		West = input;
		CountDoors();
	};

	Doors(bool _n, bool _s, bool _e, bool _w)
	{
		North = _n;
		South = _s;
		East = _e;
		West = _w;
		CountDoors();
	};

	void CountDoors()
	{
		numberOfDoors = 0;
		if (North)
		{
			numberOfDoors++;
		}
		if (South)
		{
			numberOfDoors++;
		}
		if (East)
		{
			numberOfDoors++;
		}
		if (West)
		{
			numberOfDoors++;
		}
	}



};

#endif