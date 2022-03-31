#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

extern const unsigned WINDOW_WIDTH;
extern const unsigned WINDOW_HEIGHT;

class Ball : public sf::CircleShape {
private:
	sf::Vector2f speed;
public:

	Ball(float r, int maxSpeed);

	sf::Vector2f getSpeed();

	void changeVectX();

	void changeVectY();

};