#include "Drawer.h"
#include <iostream>

Drawer::Drawer() 
{
	std::cout << "\033[?25l";
}

void Drawer::SetCursor(unsigned x, unsigned y) 
{
	std::cout << "\033[" << y << ';' << x << 'H';
}

void Drawer::ClearConsole() 
{
	std::cout << "\033[2J";
}

void Drawer::SetCharColor(unsigned color_256) 
{
	std::cout << "\033[38;5;" << color_256 << "m";
}

void Drawer::SetBackgroundColor(unsigned color_256) 
{
	std::cout << "\033[48;5;" << color_256 << "m";
}

void Drawer::CursorDown(unsigned lcount)
{
	std::cout << "\033[" << lcount << "B";
}

void Drawer::CursorUp(unsigned lcount)
{
	std::cout << "\033[" << lcount << "A";
}

void Drawer::CursorRight(unsigned lcount)
{
	std::cout << "\033[" << lcount << "C";
}

void Drawer::CursorLeft(unsigned lcount)
{
	std::cout << "\033[" << lcount << "D";
}

void Drawer::Draw(unsigned x, unsigned y, std::vector<std::vector<char>>& skin)
{
	SetCursor(x, y);
	for (auto v : skin) {
		for (auto chr : v)
		{
			printf("%c", chr);
		}
		CursorLeft(static_cast<unsigned int>(v.size()));
		CursorDown(1);
	}
}

void Drawer::Draw(StaticObject& g_object)
{
	SetCursor(g_object.Position.x, g_object.Position.y);

		std::cout << g_object.GetCurrentSprite();
}