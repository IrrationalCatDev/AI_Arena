#include <vector>

using namespace std;

struct Vec2
{
    float x;
    float y;
    Vec2 operator*(float d)
    {
        Vec2 next;
        next.x = x * d;
        next.y = y * d;
        return next;
    }
    Vec2 operator+=(Vec2 other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
};