#include "CollisionDetector.h"

void CollisionDetector::MultiCollisionDetect(std::vector<StaticObject> polygons)
{
    for (int i = 0; i < polygons.size(); i++) 
    {
        for (int j = i; j < polygons[i].verticles.size(); j++) 
        {
            if (SingleCollisionDetect(polygons[i].verticles, polygons[j].verticles))
                OnCollision(CollisionEventArgs(std::array<StaticObject,2>{polygons[i], polygons[i]}));
        }
    }
}

bool CollisionDetector::SingleCollisionDetect(const std::vector<Point>& vertices1, const std::vector<Point>& vertices2)
{
    return gjk(vertices1, vertices2);
}

vec2 CollisionDetector::tripleProduct(vec2 a, vec2 b, vec2 c)
{
    vec2 r;

    float ac = a.scalarProduct(c); // perform a.dot(c)
    float bc = b.scalarProduct(c); // perform b.dot(c)
    // perform b * a.dot(c) - a * b.dot(c)
    r.x = b.x * ac - a.x * bc;
    r.y = b.y * ac - a.y * bc;
    return vec2();
}
vec2 CollisionDetector::averagePoint(const std::vector<vec2>& vertices)
{
    vec2 avg;
    for (size_t i = 0; i < vertices.size(); i++) {
        avg.x += vertices[i].x;
        avg.y += vertices[i].y;
    }
    avg.x /= vertices.size();
    avg.y /= vertices.size();
    return avg;
}
size_t CollisionDetector::indexOfFurthestPoint(const std::vector<vec2>& vertices, vec2 d)
{
    int maxProduct = d.scalarProduct(vertices[0]);
    size_t index = 0;
    for (size_t i = 1; i < vertices.size(); i++) {
        float product = d.scalarProduct(vertices[i]);
        if (product > maxProduct) {
            maxProduct = product;
            index = i;
        }
    }
    return index;
}
vec2 CollisionDetector::support(const std::vector<vec2>& vertices1, const std::vector<vec2>& vertices2, vec2 d)
{
    // get furthest point of first body along an arbitrary direction
    size_t i = indexOfFurthestPoint(vertices1, d);

    // get furthest point of second body along the opposite direction
    size_t j = indexOfFurthestPoint(vertices2, d * (-1) );

    // subtract (Minkowski sum) the two points to see if bodies 'overlap'
    return vertices1[i] - vertices2[j];
}
bool CollisionDetector::gjk(const std::vector<vec2>& vertices1, const std::vector<vec2>& vertices2)
{
    size_t index = 0; // index of current vertex of simplex
    vec2 a, b, c, d, ao, ab, ac, abperp, acperp, simplex[3];

    vec2 position1 = averagePoint(vertices1); // not a CoG but
    vec2 position2 = averagePoint(vertices2); // it's ok for GJK )

    // initial direction from the center of 1st body to the center of 2nd body
    d = position1 - position2;

    // if initial direction is zero – set it to any arbitrary axis (we choose X)
    if ((d.x == 0) && (d.y == 0))
        d.x = 1.f;

    // set the first support as initial point of the new simplex
    a = simplex[0] = support(vertices1, vertices2, d);

    if (a.scalarProduct(d) <= 0)
        return 0; // no collision

    d = a * -1; // The next search direction is always towards the origin, so the next search direction is negate(a)

    while (1) {
        //iter_count++;

        a = simplex[++index] = support(vertices1, vertices2, d);

        if (a.scalarProduct(d) <= 0)
            return 0; // no collision

        ao = a * -1; // from point A to Origin is just negative A

        // simplex has 2 points (a line segment, not a triangle yet)
        if (index < 2) {
            b = simplex[0];
            ab = b - a; // from point A to B
            d = tripleProduct(ab, ao, ab); // normal to AB towards Origin
            if (d.lengthSquared() == 0)
                d = ab.perpendicular();
            continue; // skip to next iteration
        }

        b = simplex[1];
        c = simplex[0];
        ab = b - a; // from point A to B
        ac = c - a; // from point A to C

        acperp = tripleProduct(ab, ac, ac);

        if (acperp.scalarProduct(ao) >= 0) {

            d = acperp; // new direction is normal to AC towards Origin

        }
        else {

            abperp = tripleProduct(ac, ab, ab);

            if (abperp.scalarProduct(ao) < 0)
                return 1; // collision

            simplex[0] = simplex[1]; // swap first element (point C)

            d = abperp; // new direction is normal to AB towards Origin
        }

        simplex[1] = simplex[2]; // swap element in the middle (point B)
        --index;
    }

    return 0;
}

CollisionEventArgs::CollisionEventArgs(std::array<StaticObject, 2>& objectsPair) : EventArgs(decltype(args){&objectsPair})
{
    
}

CollisionEventArgs::CollisionEventArgs(std::array<StaticObject, 2>&& objectsPair) : EventArgs(decltype(args){&objectsPair})
{

}

std::array<StaticObject, 2> CollisionEventArgs::objectsPair()
{
    return std::array<StaticObject, 2> { (static_cast<StaticObject*>(args[0]))[0], (static_cast<StaticObject*>(args[0]))[1] };
}
