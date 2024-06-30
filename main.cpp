#include<SFML/Graphics.hpp>
#include<iostream>

int main()
{

	sf::ContextSettings setting;
	setting.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game", sf::Style::Default, setting);

	sf::Texture tex1;
	//tex1.setSmooth(true);
	//tex1.setRepeated(true);

	if (!tex1.loadFromFile("D:/Coding/Games using C++/Project1/konio dio da.jpg"))
		std::cout << "Error loading texture";

	sf::CircleShape c1(100.0);
	sf::RectangleShape r1(sf::Vector2f(300,300));
	
	c1.setTexture(&tex1);
	c1.setPosition(sf::Vector2f(250, 250));

	r1.setOrigin(0, 0);
	r1.setPosition(200,150);
	//r1.setTexture(&tex1);
	//r1.setRotation(45);
	

	while (window.isOpen()) {
		
		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
			
		window.clear();

		window.draw(r1);
		window.draw(c1);

		window.display();
	}

	return 0;
}