#include <list>
#include <algorithm>
#pragma once

class Item;
class Switcher;

class Switcher
{
public:
	std::list<Item*> items;
};

class Item
{
private:
	Switcher* switcher;
	bool state;

private:
	Item() = default;
public:
	Item(Switcher& switcher, bool switchOn = false);
	void switchOn();
	bool getState() const;
	~Item();
};

