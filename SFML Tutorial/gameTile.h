#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h" 

#ifndef GAMETILE_H
#define GAMETILE_H

using namespace sf;
using namespace std;

class GameTile {
public:
	bool isPassable;
	bool isExit;
	Vector2f pos;
	Texture texture;
	Sprite sprite;
	GameTile(string, float, float, bool, bool);
	bool setUpSprite(string);
	Collider GetCollider()
	{
		return Collider(body);
	}

private:
	RectangleShape body;

};

#endif