#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

struct FireParticle {
    RectangleShape shape;
    Vector2f velocity;
    float lifetime;
};

class Fire {
public:
    Fire(Texture* texture, Vector2f position);
    void update(float deltaTime);
    void draw(RenderWindow& window);

private:
    std::vector<FireParticle> particles;
    Texture* texture;
    void spawnFireParticles(Vector2f position);
};
