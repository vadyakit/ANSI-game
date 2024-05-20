#pragma once
#include "StaticObject.h"

enum class Directions
{
	up,
	down,
	right,
	left,
	none
};

class DynamicObject :
	public StaticObject
{
	unsigned speed;

	Point direction;
public:
	DynamicObject();
	void SetDirection(Directions dir);
	void Move();
	void Move(Directions dir);
	void Move(Directions dir, unsigned speed);
	void SetSpeed(unsigned speed);
};

