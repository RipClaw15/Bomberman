#include "Bomb.h"

Bomb::Bomb(Texture* texture, Texture* explosionTexture, Vector2f position, Vector2u imageCount, float switchTime)
    : bombTexture(*texture), explosionTexture(*explosionTexture), animation(texture, imageCount, switchTime), startTime(std::chrono::steady_clock::now()) {
    body.setSize(Vector2f(64.0f, 64.0f));
    body.setOrigin(Vector2f(0.0f, 0.0f));
    body.setTexture(&bombTexture);
    body.setPosition(position);
}

Bomb::~Bomb() {}

void Bomb::Draw(RenderWindow& window) {
    body.setTextureRect(animation.uvRect);
    window.draw(body);
}

void Bomb::update(float deltaTime) {
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();

    if (elapsed >= duration && !isExploding) {
        isExploding = true;
        body.setTexture(&explosionTexture);
        animation = Animation(&explosionTexture, Vector2u(3, 1), 0.1f); // Example: 3 frames for explosion
    }

    if (isExploding) {
        // Update the explosion animation
        animation.Update(0, deltaTime, true);
        body.setTextureRect(animation.uvRect);

        // Check if the explosion animation is complete
        if (animation.uvRect.left >= (animation.getImageCount().x - 1) * animation.uvRect.width) {
            hasExplodedFlag = true;
            std::cout << "Explosion animation complete.\n"; // Debug statement
        }
    }
    else {
        // Update the bomb animation
        animation.Update(0, deltaTime, true);
        body.setTextureRect(animation.uvRect);
    }
}

bool Bomb::hasExploded() const {
    return hasExplodedFlag;
}

void Bomb::printStatus() const {
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
    std::cout << "Bomb will explode in " << (duration - elapsed) << " seconds.\n";
}
