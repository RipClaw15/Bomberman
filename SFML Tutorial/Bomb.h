#pragma once

#ifndef BOMB_H
#define BOMB_H

#include <iostream>
#include <string>
#include <chrono>

#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "Animation.h"

using namespace std;
using namespace sf;

class Bomb
{
public:
	Bomb(Texture* texture, Texture* explosionTexture, Vector2f position, Vector2u imageCount, float switchTime);
	~Bomb();

	void Draw(RenderWindow& window);
	Collider GetCollider()
	{
		return Collider(body);
	}

	void update(float deltaTime);

	void printStatus() const;

	bool hasExploded() const;


private:
	RectangleShape body;
	Texture bombTexture;
	Texture explosionTexture;
	Animation animation;
	std::chrono::steady_clock::time_point startTime;
	const int duration = 3; // Duration in seconds
	bool isExploding = false;
	bool hasExplodedFlag = false;
};

#endif // BOMB_H