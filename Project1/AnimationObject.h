

#pragma once
#include "GraphicObject.h"

class AnimationObject : public GraphicObject
{
	std::list<ansiImage*> Sprites;
	decltype(Sprites)::iterator CurrentSprite;
};

