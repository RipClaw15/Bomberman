#include "gameTile.h"
#include "Collider.h"

using namespace std;
using namespace sf;

GameTile::GameTile(string textureName, float x, float y, bool passable, bool exit) {
	if (!setUpSprite(textureName)) {
		return;
	}
	pos = Vector2f(x, y);
	sprite.setPosition(pos);
	isExit = exit;

	isPassable = passable;

}

bool GameTile::setUpSprite(string textureName) {

	if (!texture.loadFromFile(textureName))
	{
		return 0;
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 20, 16));
	sprite.setScale(4.0f, 4.0f);
	return true;
}