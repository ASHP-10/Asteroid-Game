#include<SFML/Graphics.hpp>
#include<iostream>
#include "Sprite.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");
	
	Sprite P1;
	if (!P1.loadTexture("D:/Coding/Games using C++/Project1/Assets/Sprite/triangle.jpg"))
		return -1;
	
	P1.origin();
	P1.setSize();
		
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)	//checks for the closed event fromt he queue
				window.close();
		}

		P1.update();
			

		window.clear();		//clears the window
		P1.draw(window);
		window.display();	//displays the window
	}

	return 0;
}