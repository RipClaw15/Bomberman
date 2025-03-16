#include "Fire.h"

Fire::Fire(Texture* texture, Vector2f position) : texture(texture) {
    spawnFireParticles(position);
}

void Fire::spawnFireParticles(Vector2f position) {
    const float speed = 100.0f;
    const float lifetime = 1.0f;
    const int beamLength = 3; // Length of the beam in blocks

    // Directions: up, down, left, right
    Vector2f directions[4] = {
        Vector2f(0, -1), // Up
        Vector2f(0, 1),  // Down
        Vector2f(-1, 0), // Left
        Vector2f(1, 0)   // Right
    };

    for (const auto& direction : directions) {
        for (int i = 0; i < beamLength; ++i) {
            FireParticle particle;
            particle.shape.setSize(Vector2f(64.0f, 64.0f));
            particle.shape.setOrigin(Vector2f(8.0f, 8.0f));
            particle.shape.setTexture(texture);
            particle.shape.setPosition(position + direction * 64.0f * static_cast<float>(i));
            particle.velocity = direction * speed;
            particle.lifetime = lifetime;
            particles.push_back(particle);
        }
    }
}

void Fire::update(float deltaTime) {
    for (auto& particle : particles) {
        particle.shape.move(particle.velocity * deltaTime);
        particle.lifetime -= deltaTime;
    }

    // Remove expired particles
    particles.erase(
        std::remove_if(particles.begin(), particles.end(),
            [](const FireParticle& p) { return p.lifetime <= 0; }),
        particles.end());
}

void Fire::draw(RenderWindow& window) {
    for (const auto& particle : particles) {
        window.draw(particle.shape);
    }
}
