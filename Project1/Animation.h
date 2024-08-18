#include "AnimationObject.h"
#include "Timer.h"

#pragma once
class Animation
{
	Animation(std::vector<ansiImage> frames, double duration);
	std::vector<ansiImage*> frames;
	timerId timer;
	GraphicObject* graphicObject;
};

