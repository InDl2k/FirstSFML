#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Cat.h"
#include "Laser.h"

void onMouseMove(sf::Event::MouseMoveEvent& event, sf::Vector2f& mousePosition){
	mousePosition = { (float)event.x, (float)event.y };
}

void pollEvents(sf::RenderWindow& window, sf::Vector2f& mousePosition) {
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseMoved:
			onMouseMove(event.mouseMove, mousePosition);
		default:
			break;
		}
	}
}

void update(Cat& cat, sf::Vector2f& mousePosition, sf::Clock& clock, Laser& laser) {
	sf::Vector2f dif = mousePosition - cat.getPosition();
	float dt = clock.restart().asSeconds();
	cat.updateCat(dif, dt);

	laser.setPosition(mousePosition);
}

void redrawFrame(sf::RenderWindow& window, Cat& cat, Laser& laser) {
	window.draw(laser.getSprite());
	window.draw(cat.getSprite());
}


int main(){

	const unsigned int WINDOW_WIDTH = 800;
	const unsigned int WINDOW_HEIGHT = 600;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), 
		"Text", sf::Style::Default, settings);
	sf::Clock clock;

	Cat cat;
	Laser laser;
	sf::Vector2f mousePosition;

	while (window.isOpen()) {
		pollEvents(window, mousePosition);
		window.clear(sf::Color::White);
		update(cat, mousePosition, clock, laser);
		redrawFrame(window, cat, laser);
		window.display();
	}

	return 0;
}