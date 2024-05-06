#pragma once
#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include <vector>

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

using namespace std;
using namespace sf;

class GameWorld
{
	Vector2i exitPos;
	Vector2i playerPos;
	vector<Vector2i> enemyPositions;
	void setUpInitialState();
	void setUpEnemyPositions();
	void setUpTiles();
public:
	vector<vector<GameTile*> > tiles;
	int gridLength;
	int gridHeight;
	GameWorld();
};

#endif