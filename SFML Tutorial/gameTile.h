#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h" 

#ifndef GAMETILE_H
#define GAMETILE_H

using namespace sf;
using namespace std;

class GameTile {
public:

	GameTile(string, float, float, Vector2f pos, bool);
	~GameTile();
	Texture texture;
	Sprite sprite;
	
	bool isPassable;
	bool setUpSprite(string);
	Vector2f pos;
	Collider GetCollider()	{
		return Collider(body);
	}

private:
	RectangleShape body;

};

#endif