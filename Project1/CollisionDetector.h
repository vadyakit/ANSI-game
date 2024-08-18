#include "StaticObject.h"
#include <vector>
#include <array>
#include <functional>
#include "Event.h"
#include <Array>

#pragma once

class CollisionEventArgs : public shittEvent::EventArgs {

public:
	CollisionEventArgs(std::array<StaticObject, 2>& objectsPair);
	CollisionEventArgs(std::array<StaticObject, 2>&& objectsPair);
	std::array<StaticObject,2> objectsPair();
};


typedef struct Point vec2;

class CollisionDetector
{
	shittEvent::EventHandler OnCollision;

	bool finish;

	bool SingleCollisionDetect(const std::vector<Point>& vertices1, const std::vector<Point>& vertices2);
	void MultiCollisionDetect(std::vector<StaticObject> polygons);

private:
	vec2 tripleProduct(vec2 a, vec2 b, vec2 c);
	vec2 averagePoint(const std::vector<vec2>& vertices);

	size_t indexOfFurthestPoint(const std::vector<vec2>& vertices, vec2 d);
	vec2 support(const std::vector<vec2>& vertices1, const std::vector<vec2>& vertices2, vec2 d);
	bool gjk(const std::vector<vec2>& vertices1, const std::vector<vec2>& vertices2);

};

