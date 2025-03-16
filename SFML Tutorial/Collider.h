#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Collider
{
public:
    Collider(RectangleShape& body);
    ~Collider();

    void Move(float dx, float dy) const
    {
        body.move(dx, dy);
    }

    bool CheckCollision(const Collider& other, float push) const;
    Vector2f GetPosition() const
    {
        return body.getPosition();
    }
    Vector2f GetHalfSize() const
    {
        return body.getSize() / 2.0f;
    }

private:
    RectangleShape& body;
};