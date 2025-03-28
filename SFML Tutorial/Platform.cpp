#include "Platform.h"

void Platform::Draw(RenderWindow& window)
{
	window.draw(body);
}

Platform::Platform(Texture* texture, Vector2f size, Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
}
Platform::~Platform()
{

}