#include "StaticObject.h"
#include <vector>
#include <array>
#include <functional>

#pragma once

typedef struct Point vec2;

class CollisionDetector
{
	bool finish;

	bool SingleCollisionDetect(std::vector<Point> vertices1, std::vector<Point> vertices2);
	std::vector<int*> MultiCollisionDetect(std::vector<std::vector<Point>> polygons);

private:
	//std::function<void(std::vector<int[2]>)> collisionCallback;
	vec2 tripleProduct(vec2 a, vec2 b, vec2 c);
	vec2 averagePoint(std::vector<vec2> vertices);

	size_t indexOfFurthestPoint(std::vector<vec2> vertices, vec2 d);
	vec2 support(std::vector<vec2> vertices1, std::vector<vec2> vertices2, vec2 d);
	bool gjk(std::vector<vec2> vertices1, std::vector<vec2> vertices2);

};

