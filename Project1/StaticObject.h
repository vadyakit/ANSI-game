#include <vector>
#include <string>
#include <functional>
#include <iterator>
#include "Timer.h"
#include "SpritePack.h"

#pragma once

struct Point 
{
	Point(unsigned x = 0, unsigned y = 0) {this->x = x; this->y = y;}

	void SetXY(unsigned x, unsigned y) {this->x = x; this->y = y;}
	
	unsigned x;
	unsigned y;
};

class StaticObject
{
public:
	Point Position;
	Point RectangleVector;
	std::string SpritePackName;
	std::vector<unsigned> SpritesIndexes;
	std::vector<unsigned>::iterator CurrentSprite = SpritesIndexes.begin();

	StaticObject();
	void SetPosition(unsigned x, unsigned y);
	void SetSprites(std::string name, std::vector<unsigned> indexes);
	void SetNextSprite();
	std::string GetCurrentSprite();
	void Update();
	~StaticObject();
};

