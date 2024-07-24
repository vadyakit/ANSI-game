#include <functional>
#include "Player.h"
#include "Drawer.h"

Player::Player()
{
	std::function<void(char)> f = [this](char a) {OnKeyDown(a);};
	//controller.setOnKeyDownCallback(f);
	f = [this](char a) {OnKeyUp(a);};
	//controller.setOnKeyUpCallback(f);
	//controller.StartEventMonitoring();
}

void Player::OnKeyDown(char key)
{
	switch (key)
	{
	case 'a':
	case 'd':
	case 'w':
	case 's':
		SetSpeed(1);
		Move();
		break;
	default:
		break;
	}

	switch (key)
	{
	case 'a':
		SetDirection(Directions::left);
		break;
	case 'd':
		SetDirection(Directions::right);
		break;
	case 'w':
		SetDirection(Directions::up);
		break;
	case 's':
		SetDirection(Directions::down);
		break;
	default:
		break;
	}
}

void Player::OnKeyUp(char key)
{
	switch (key)
	{
	case 'a':
	case 'd':
	case 'w':
	case 's':
		SetSpeed(0);
		break;
	default:
		break;
	}
}