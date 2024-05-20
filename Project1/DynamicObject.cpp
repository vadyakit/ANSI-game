#include "DynamicObject.h"

DynamicObject::DynamicObject()
{
	speed = 0;
	SetDirection(Directions::none);
}

void DynamicObject::SetDirection(Directions dir) {
	switch (dir) {
	case Directions::up:
		direction.SetXY(0, -1);
		break;
	case Directions::down:
		direction.SetXY(0, 1);
		break;
	case Directions::right:
		direction.SetXY(1, 0);
		break;
	case Directions::left:
		direction.SetXY(-1, 0);
		break;
	case Directions::none:
		direction.SetXY(0, 0);
		break;
	default:
		break;
	}
}

void DynamicObject::Move()
{
	Position.x += speed * direction.x;
	Position.y += speed * direction.y;
}

void DynamicObject::Move(Directions dir)
{
	SetDirection(dir);
	Move();
}

void DynamicObject::Move(Directions dir, unsigned speed)
{
	SetSpeed(speed);
	Move(dir);
}

void DynamicObject::SetSpeed(unsigned speed)
{
	this->speed = speed;
}