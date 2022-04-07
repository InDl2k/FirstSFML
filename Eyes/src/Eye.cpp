#include "Eye.h"

Eye::Eye(sf::Vector2f position) {
	this->position = position;
	initEye();
}

sf::Vector2f toEuclidean(float radius, float angle) {
	return {
		radius * cos(angle),
		radius * sin(angle)
	};
}

void Eye::updateEyesElements() {
	const sf::Vector2f pupilOffset = toEuclidean(40, this->rotation);
	this->pupil.setPosition(this->position + pupilOffset);
}

void Eye::initEye() {
	float radiusX = 60;
	float radiusY = 120;
	this->elips.setPointCount(1000);
	for (int i = 0; i < this->elips.getPointCount(); ++i) {
		float point = float(i * 2 * acos(-1)) / float(this->elips.getPointCount());
		this->elips.setPoint(i, { radiusX * cos(point), radiusY * sin(point) });
	}
	this->elips.setFillColor(sf::Color::White);
	this->elips.setPosition(this->position);

	radiusX = 15;
	radiusY = 25;
	this->pupil.setPointCount(100);
	for (int i = 0; i < this->pupil.getPointCount(); ++i) {
		float point = i * this->pupil.getPointCount() / acos(-1);
		this->pupil.setPoint(i, { radiusX * cos(point), radiusY * sin(point) });
	}
	this->pupil.setFillColor(sf::Color::Green);
}

void Eye::setRotation(sf::Vector2f mousePosition) {
	const sf::Vector2f delta = mousePosition - this->position;
	this->rotation = atan2(delta.y, delta.x);
	updateEyesElements();
}

std::vector<sf::ConvexShape> Eye::getShapes() { return { this->elips, this->pupil }; }