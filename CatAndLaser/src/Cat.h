#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Cat {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedRotation = 90;
	float speedMove = 250;

	void init();
	void setRotation(sf::Vector2f& dif);
	void setPosition(sf::Vector2f& dif, float dt);
public:
	Cat();
	void updateCat(sf::Vector2f& dif, float dt);
	sf::Vector2f getPosition();
	float getRotation();
	sf::Sprite getSprite();
};
