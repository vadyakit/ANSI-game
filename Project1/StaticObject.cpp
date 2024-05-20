#include "StaticObject.h"

StaticObject::StaticObject()
{

}

void StaticObject::SetPosition(unsigned x, unsigned y) 
{
	if (x < 0) 
	{
		Position.x = 0;
	}
	else if (y < 0) 
	{
		Position.y = 0;
	}
	else 
	{
		Position.x = x;
		Position.y = y;
	}
}

void StaticObject::SetSprites(std::string name, std::vector<unsigned> indexes)
{
	SpritePackName = name;
	SpritesIndexes = indexes;
}
void StaticObject::SetNextSprite()
{
	CurrentSprite == SpritesIndexes.end() - 1 ? CurrentSprite = SpritesIndexes.begin() : CurrentSprite++;
}
std::string StaticObject::GetCurrentSprite()
{
	return SpritePack::GetSprite(SpritePackName, *CurrentSprite);
}
StaticObject::~StaticObject()
{

}