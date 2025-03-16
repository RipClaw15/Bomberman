#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Platform.h"
#include "Map.h"
#include "gameTile.h"
#include "gameWorld.h"
#include "Bomb.h"

using namespace std;
using namespace sf;

static const float VIEW_HEIGHT = 1024.0f;

void ResizeView(const RenderWindow& window, View& view) {
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main() {
    RenderWindow window(VideoMode(1600, 1024), "SFML Tutorial", Style::Close | Style::Resize);
    View view(Vector2f(0.0f, 0.0f), Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

    Texture playerTexture, bombTexture, explosionTexture, fireTexture;
    playerTexture.loadFromFile("images/green_alien.png");
    bombTexture.loadFromFile("images/bomb12.png");
    explosionTexture.loadFromFile("images/bomb.png");
    fireTexture.loadFromFile("images/fire.png"); // Load fire texture

    Player player(&playerTexture, Vector2u(11, 1), 0.3f, 200.0f);

    Bomb* bomb = nullptr;

    Vector2u bombImageCount(3, 1); // Example: 3 frames in the animation
    float bombSwitchTime = 0.2f; // Time to switch between frames

    GameWorld gameWorld = GameWorld();

    float deltaTime = 0.0f;
    Clock clock;

    bool spaceWasPressed = false;

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        Event evnt;
        while (window.pollEvent(evnt)) {
            switch (evnt.type) {
            case Event::Closed:
                window.close();
                break;
            case Event::Resized:
                ResizeView(window, view);
                break;
            }
        }

        player.Update(deltaTime);

        // Check if spacebar is pressed
        bool spaceIsPressed = Keyboard::isKeyPressed(Keyboard::Space);
        if (spaceIsPressed && !spaceWasPressed) {
            if (bomb == nullptr) {
                // Get the player's position and align it to the nearest grid cell
                Vector2f playerPosition = player.GetPosition();
                Vector2f gridPosition(
                    static_cast<int>((playerPosition.x + 32) / 64) * 64,
                    static_cast<int>((playerPosition.y + 32) / 64) * 64
                );
                // Spawn a bomb at the grid-aligned position
                bomb = new Bomb(&bombTexture, &explosionTexture, &fireTexture, gridPosition, bombImageCount, bombSwitchTime);
                cout << "Bomb spawned at (" << gridPosition.x << ", " << gridPosition.y << ")\n";
            }
        }
        spaceWasPressed = spaceIsPressed;

        // Update the bomb if it exists
        if (bomb != nullptr) {
            bomb->update(deltaTime);
            if (bomb->hasExploded()) {
                delete bomb;
                bomb = nullptr;
                std::cout << "Bomb deleted.\n"; // Debug statement
            }
        }

        window.clear(Color(150, 150, 150));

        // Draw the game world
        for (int i = 0; i < gameWorld.gridHeight; i++) {
            for (int j = 0; j < gameWorld.gridLength; j++) {
                if (!gameWorld.tiles[i][j]->isPassable) {
                    gameWorld.tiles[i][j]->GetCollider().CheckCollision(player.GetCollider(), 1.0f);
                }
                window.draw(gameWorld.tiles[i][j]->sprite);
            }
        }

        // Draw the player and bomb
        player.Draw(window);
        if (bomb != nullptr) {
            bomb->Draw(window);
        }

        window.display();
    }

    // Clean up dynamically allocated bomb if it exists
    delete bomb;

    return 0;
}
