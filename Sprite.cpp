#include "Sprite.h"
#include <iostream>
#include "VectorMath.cpp"
#include <cmath>

bool Sprite::loadTexture(const std::string addressPath) {
	if (!texS.loadFromFile(addressPath)) {
		std::cout << "Error loading texture from" << addressPath << std::endl;

		return false;
	}
	S.setTexture(texS);
	return true;
}

void Sprite::setSize() {
	//S.setTextureRect(sf::IntRect(17 * 0, 17 * 1, 17, 17));
	//S.setScale(4, 4);
	S.setPosition(1920 / 2 - 17, 1080 / 2 - 17);
}

void Sprite::update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))	//rotate right
		S.rotate(5);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))	//rotate left
		S.rotate(-5);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))	//move forward
		moveFront(5);
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))	//hyperspace(teleports randomly)
		std::cout << "hyperspace" << std::endl;
}

void Sprite::moveFront(int playerSpeed) {
	float angle = VectorMath::DegtoRad(S.getRotation());
	S.move(std::cos(angle) * playerSpeed, std::sin(angle) * playerSpeed);
}

sf::Sprite Sprite::getSprite() {
	return S;
}

void Sprite::draw(sf::RenderWindow& w) {
	w.draw(S);
}

void Sprite::origin() {
	sf::FloatRect bound = S.getGlobalBounds();

	S.setOrigin(bound.width/ 2.0f, bound.height/ 2.0f);
}