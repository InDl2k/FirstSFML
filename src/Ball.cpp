#include "Ball.h"

Ball::Ball(float r, int maxSpeed): sf::CircleShape(r) {
	this->setPosition(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT);
	this->setFillColor(sf::Color::White);
	this->speed = sf::Vector2f(rand() % (2 * maxSpeed) - maxSpeed, rand() % (2 * maxSpeed) - maxSpeed);
}

sf::Vector2f Ball::getSpeed() {
	return this->speed;
}

void Ball::changeVectX() {
	speed.x = -speed.x;
}

void Ball::changeVectY() {
	speed.y = -speed.y;
}
