#pragma once
#include <SFML/Graphics.hpp>
class Eye {
private:
	sf::ConvexShape elips;
	sf::ConvexShape pupil;
	sf::Vector2f position;
	float rotation = 0;
public:
	Eye(sf::Vector2f position);

	void initEye();
	void updateEyesElements();
	std::vector<sf::ConvexShape> getShapes();
	void setRotation(sf::Vector2f mousePosition);
};