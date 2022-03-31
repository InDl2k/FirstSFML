#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>

const unsigned WINDOW_WIDTH = 1280;
const unsigned WINDOW_HEIGHT = 1024;
constexpr float BALL_SIZE = 40;

int main() {

	constexpr int pointCount = 1000;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Test", sf::Style::Default, settings);
	sf::Clock clock;


	sf::ConvexShape shape;
	shape.setPosition({ WINDOW_WIDTH/2, WINDOW_HEIGHT/2 });
	shape.setFillColor(sf::Color(155, 0, 155));

	shape.setPointCount(pointCount);

	for (int i = 0; i < pointCount; ++i) {
		float angle = float(2 * acos(-1) * i) / float(pointCount);
		float radius = 400 * sin(6 * angle);
		sf::Vector2f point = sf::Vector2f{
			radius * cos(angle),
			radius * sin(angle)
		};
		shape.setPoint(i, point);
	}


	float speed = 5.f;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				window.close();
			}
		}

		float dt = clock.restart().asSeconds();

		window.clear();
		shape.setRotation(shape.getRotation() + dt * speed);
		window.draw(shape);
		window.display();

	}

	return 0;
}