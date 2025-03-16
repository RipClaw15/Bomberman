#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Animation
{

public:
	Animation(Texture* texture, Vector2u imageCount, float switchTime);
	~Animation();

	void Update(int row, float deltaTime, bool faceRight);


	IntRect uvRect;
	Vector2u getImageCount() const;
private:

	Vector2u imageCount;
	Vector2u currentImage;

	float totalTime;
	float switchTime;



};