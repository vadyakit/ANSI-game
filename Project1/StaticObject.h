#include <vector>
#include <string>
#include <functional>
#include <iterator>
#include "Timer.h"
#include "SpritePack.h"

#pragma once

struct Point 
{
	Point(int x = 0, int y = 0) { SetXY(x, y); }

	void SetXY(int x, int y) {this->x = x; this->y = y;}
	
	int x;
	int y;


	int scalarProduct(const Point& a);
	int lengthSquared();
	Point perpendicular() const;
	Point operator - (const Point& a) const;
	Point operator - (const int& a) const;
	Point operator + (const Point& a) const;
	Point operator + (const int& a) const;
	Point operator * (const int& a) const;
};

class StaticObject
{
public:
	Point Position;
	std::vector<Point> verticles;
	//std::string SpritePackName;
	//std::vector<unsigned> SpritesIndexes;
	//std::vector<unsigned>::iterator CurrentSprite = SpritesIndexes.begin();

	StaticObject();
	void SetPosition(unsigned x, unsigned y);
	//void SetSprites(std::string name, std::vector<unsigned> indexes);
	//void SetNextSprite();
	//std::string GetCurrentSprite();
	//void Update();
};

