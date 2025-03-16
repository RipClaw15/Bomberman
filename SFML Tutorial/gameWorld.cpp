#include "gameWorld.h"
#include <iostream>
#include "Collider.h"
#include "Platform.h"

using namespace std;

GameWorld::GameWorld() {
    // Define the dimensions of the grid
    gridLength = 25; // 24 columns
    gridHeight = 15; // 20 rows (increased for a wider map)

    // Initialize the tiles array
    tiles.resize(gridHeight);
    for (int i = 0; i < gridHeight; ++i) {
        tiles[i].resize(gridLength, nullptr);
    }

    // Set up the initial state of the game
    setUpInitialState();
    cout << "Grid length: " << gridLength << ", Grid height: " << gridHeight << endl;
}

void GameWorld::setUpInitialState() {
    // Set the position of the exit and player

    // Set up the enemy positions
    setUpEnemyPositions();

    // Set up the tiles for the game world
    setUpTiles();
}

void GameWorld::setUpEnemyPositions() {
    // Clear the vector to ensure it's empty
}

void GameWorld::setUpTiles() {
    // Loop to create tiles
    Texture brick, wall, empty;

    for (int i = 0; i < gridHeight; ++i) {
        for (int j = 0; j < gridLength; ++j) {
            string imagePath;
            bool isPassable;
            bool isExit = false;

            // Determine image path based on position
            if (i == 0 || i == gridHeight - 1 || j == 0 || j == gridLength - 1) {
                imagePath = "images/brick.png"; // Border tiles
                isPassable = false;
            }
            else if (i % 2 == 0 && j % 2 == 0) {
                imagePath = "images/wall.png"; // Wall tiles
                isPassable = false;
            }
            else {
                imagePath = "images/empty.png"; // Empty tiles
                isPassable = true;
            }


            // Create tile and assign to array
            tiles[i][j] = new GameTile(imagePath, j * 64, i * 64, Vector2f(64.0f, 64.0f), isPassable);

        }
    }
}