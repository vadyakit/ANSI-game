#include "StaticObject.h"

StaticObject::StaticObject()
{

}

void StaticObject::SetPosition(unsigned x, unsigned y) 
{
		Position.x = x;
		Position.y = y;
}

int Point::scalarProduct(const Point& a) { return x * a.x + y * a.y; }
int Point::lengthSquared() { return x * x + y * y; }
Point Point::perpendicular() const { return Point(y, -x); }
Point Point::operator - (const Point& a) const { return Point(x - a.x, y - a.y); }
Point Point::operator - (const int& a) const { return Point(x - a, y - a); }
Point Point::operator + (const Point& a) const { return Point(x + a.x, y + a.y); }
Point Point::operator + (const int& a) const { return Point(x + a, y + a); }
Point Point::operator * (const int& a) const { return Point(x*a,y*a); }