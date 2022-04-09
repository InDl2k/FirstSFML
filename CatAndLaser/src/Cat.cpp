#include "Cat.h"

Cat::Cat() {
	init();
}

void Cat::init() {
	if (!this->texture.loadFromFile("cat.png")) {
		std::cout << "ERROR load texture" << std::endl;
	}
	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(this->texture.getSize().x / 2, this->texture.getSize().y / 2);
}

void Cat::updateCat(sf::Vector2f& dif, float dt) {
	setPosition(dif, dt);
	setRotation(dif);
}

sf::Vector2f toScalar(sf::Vector2f& points) {
	float norm = std::max(0.001f, sqrt(points.x * points.x + points.y * points.y)); //avoid INF when div by zero, funny bug shaking cat when he gets laser
	return {
		points.x / norm,
		points.y / norm
	};
}

void Cat::setPosition(sf::Vector2f& dif, float dt) {
	this->sprite.setPosition(this->sprite.getPosition() + toScalar(dif) * this->speedMove * dt);
}

float toDegrees(float radians) {
	return float(double(radians) * 180 / acos(-1));
}

void Cat::setRotation(sf::Vector2f& dif) {
	this->sprite.setRotation(toDegrees(atan2(dif.y, dif.x)));
	if (this->sprite.getRotation() >= 90 && this->sprite.getRotation() <= 260) {
		this->sprite.setScale(1, -1);
	}
	else
		this->sprite.setScale(1, 1);
}

sf::Vector2f Cat::getPosition() {
	return this->sprite.getPosition();
}

float Cat::getRotation() {
	return this->sprite.getRotation();
}

sf::Sprite Cat::getSprite() {
	return this->sprite;
}