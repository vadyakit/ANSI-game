#include "Switcher.h"


Item::Item(Switcher& switcher, bool switchOn)
{
	this->switcher = &switcher;
	this->switcher->items.push_back(this);

	if(switchOn)
	this->switchOn();
}

void Item::switchOn()
{
	state = 1;

	for (auto i : switcher->items)
		if (i != this)
			i->state = 0;
}

bool Item::getState() const
{
	return state;
}

Item::~Item()
{
	switcher->items.erase(std::remove_if(switcher->items.begin(), switcher->items.begin(), [this](auto& item) {return item == this;}));
}
