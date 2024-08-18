#include <vector>
#include "GraphicObject.h"
#pragma once
 class Drawer
{
public:
	Drawer();
	static void SetCursor(unsigned x, unsigned y);
	static void ClearConsole();
	static void SetCharColor(unsigned color_256);
	static void SetBackgroundColor(unsigned color_256);
	static void CursorDown(unsigned lcount);
	static void CursorUp(unsigned lcount);
	static void CursorRight(unsigned lcount);
	static void CursorLeft(unsigned lcount);
	static void Draw(unsigned x, unsigned y, std::vector<std::vector<char>>& skin);
	static void Draw(GraphicObject& g_object);
};

