#include "Laser.h"

Laser::Laser() {
	init();
}

void Laser::init() {
	if (!this->texture.loadFromFile("red_pointer.png")) {
		std::cout << "ERROR to load texture" << std::endl;
	}
	this->sprite.setTexture(texture);
	this->sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}

void Laser::setPosition(sf::Vector2f& mousePosition) {
	this->sprite.setPosition(mousePosition);
}

sf::Sprite Laser::getSprite() {
	return this->sprite;
}