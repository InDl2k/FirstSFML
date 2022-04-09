#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Laser {
private:
	sf::Sprite sprite;
	sf::Texture texture;

	void init();
public:
	Laser();
	void setPosition(sf::Vector2f& mousePosition);
	sf::Sprite getSprite();
};
