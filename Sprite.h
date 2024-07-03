#pragma once
#include <SFML/Graphics.hpp>

class Sprite
{
private:	// Variables
	sf::Sprite S;
	sf::Texture texS;

public:		// Functions

	//loads texture for sprite
	bool loadTexture(const std::string);

	//sets the texture loaded
	void setSize();

	//set the origin to the center of the sprite
	void origin();

	//checks for the update of movement for the sprite
	void update();

	//makes the sprite move the direction its facing
	void moveFront(int);


	sf::Sprite getSprite();

	void draw(sf::RenderWindow&);
};

