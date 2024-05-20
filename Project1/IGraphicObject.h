#include <vector>
#include "IStaticObject.h"
#pragma once
class IGraphicObject : public IStaticObject
{
public:
	std::vector<std::vector<char>> skin;
};

