#include "DynamicObject.h"
#include "KeyController.h"
#pragma once
class Player : public DynamicObject
{
	KeyController controller;
	void OnKeyDown(char key);
	void OnKeyUp(char key);
public:
	Player();
};

