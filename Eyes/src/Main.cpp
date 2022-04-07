#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Eye.h"


void OnMouseMove(const sf::Event::MouseMoveEvent& event, sf::Vector2f& mousePosition) {
	mousePosition = { float(event.x), float(event.y) };
}

void pollEvents(sf::RenderWindow& window, sf::Vector2f& mousePosition){
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseMoved:
			OnMouseMove(event.mouseMove, mousePosition);
		default:
			break;
		}
	}
}

void update(const sf::Vector2f& mousePosition, Eye& eye) {
	eye.setRotation(mousePosition);
}

void redrawFrame(sf::RenderWindow& window, Eye& eye) {
	for (auto& el : eye.getShapes())
		window.draw(el);
}

int main() {

	const unsigned int WINDOW_WIDTH = 800;
	const unsigned int WINDOW_HEIGHT = 600;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		"Test", sf::Style::Default, settings);

	std::vector<Eye> eyes = { Eye({WINDOW_WIDTH / 2 - 80, WINDOW_HEIGHT / 2}), Eye({ WINDOW_WIDTH / 2 + 80, WINDOW_HEIGHT / 2 }) };
	sf::Vector2f mousePosition;

	while (window.isOpen()) {
		pollEvents(window, mousePosition);
		window.clear();
		for (auto& el : eyes) {
			update(mousePosition, el);
			redrawFrame(window, el);
		}
		window.display();
	}


	return 0;
}