#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Platform.h"
#include "Map.h"

using namespace std;
using namespace sf;

static const float VIEW_HEIGHT = 1024.0f;

void ResizeView(const RenderWindow& window, View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);

    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
    RenderWindow window(VideoMode(1024, 1024), "SFML Tutorial", Style::Close | Style::Resize);
    View view(Vector2f(0.0f, 0.0f), Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
    
    Texture playerTexture;
    playerTexture.loadFromFile("green_alien.png");

    Texture wallTexture;
    wallTexture.loadFromFile("wall.jpg");
    

    Player player (&playerTexture, Vector2u(11,1), 0.3f, 100.0f);

    

    Platform platform2(&wallTexture, Vector2f(400.0f, 200.0f), Vector2f(500.0f, 0.0f));

    

    /*
    Vector2u textureSize = playerTexture.getSize();

    textureSize.x /= 11;

    player.setTextureRect(IntRect(textureSize.x * 0, 0, textureSize.x, textureSize.y));
    */

    Map map1(&wallTexture, Vector2f(0.0f, 0.0f));

    float deltaTime = 0.0f;
    Clock clock;

    while (window.isOpen()) 
    {
        deltaTime = clock.restart().asSeconds();

        Event evnt;
        
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::Resized:
                ResizeView(window, view);
                break;
            }
        }

        
        player.Update(deltaTime);

        
        platform2.GetCollider().CheckCollision(player.GetCollider(), 1.0f);

        

        window.clear(Color(150,150,150));
        window.setView(view);
        player.Draw(window);
        
        platform2.Draw(window);
        window.display();
    }

    return 0;
}