#pragma once
#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Platform.h" // Include the Platform class header

using namespace sf;
using namespace std;

class Map 
{
public:
    Map(Texture* texture, int w, int h); // Constructor
    ~Map();
    void Clear();
    void Generate(Texture* texture, int x, int y); // Generate a random map
    
    sf::Vector2f getOrigin();
    sf::Vector2f mapSize = sf::Vector2f(9.0f, 9.0f);
    sf::Vector2f start = sf::Vector2f(0.0f, 0.0f);

private:
    int width;
    int height;
    vector<vector<char>> grid; // Represents the game map
    Texture wallTexture; // Texture for walls
    Texture emptyTexture; // Texture for empty spaces
    Sprite wallSprite; // Sprite for walls
    Sprite emptySprite; // Sprite for empty spaces
    vector<Platform> platforms; // Vector to store platforms


};

#endif // MAP_H
