#include "gameTile.h"
#include "Collider.h"

using namespace std;
using namespace sf;


GameTile::GameTile(string textureName, float x, float y, Vector2f size, bool passable) {

	if (!setUpSprite(textureName)) {
		return;
	}
	pos = Vector2f(x, y);
	isPassable = passable;
	sprite.setPosition(pos);
	body.setSize(size);

	body.setPosition(pos);
}

GameTile::~GameTile()
{

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