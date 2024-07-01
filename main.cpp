#include<SFML/Graphics.hpp>
#include<iostream>

int main()
{
	//sf::ContextSettings setting;
	//setting.antialiasingLevel = 4;
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Game"); //sf::Style::Default, setting);

	sf::Texture tSprite1;
	//tex1.setSmooth(true);
	//tex1.setRepeated(true);

	if (!tSprite1.loadFromFile("D:/Coding/Games using C++/Project1/Assets/Sprite/Old_hero.png"))
		std::cout << "Error loading texture for Sprite";

	
	sf::Sprite P1;

	P1.setTexture(tSprite1);
	P1.setTextureRect(sf::IntRect(17 * 0, 17 * 1, 17, 17));
	P1.setScale(5,5);
	P1.setPosition(1024 / 2 - 16, 768/2 - 17);

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			P1.setPosition(P1.getPosition() + sf::Vector2f(1, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			P1.setPosition(P1.getPosition() + sf::Vector2f(-1, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			P1.setPosition(P1.getPosition() + sf::Vector2f(0,-1));
			//P1.setPosition(P1.getPosition() + sf::Vector2f(0,1));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			P1.setPosition(P1.getPosition() + sf::Vector2f(0, 1));
		
			
		window.clear();

		window.draw(P1);

		window.display();
	}

	return 0;
}