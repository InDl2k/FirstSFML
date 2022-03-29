#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Ball.h"

const unsigned WINDOW_WIDTH = 1280;
const unsigned WINDOW_HEIGHT = 1024;

constexpr float BALL_SIZE = 10; //control values
constexpr int COUNT_BALLS = 100;
constexpr int MAX_SPEED = 100;

int main() {

	srand(time(NULL));


	sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Test");
	sf::Clock clock;

	std::vector<Ball> balls;
	for (int i = 0; i < COUNT_BALLS; ++i) {
		Ball ball(BALL_SIZE, MAX_SPEED);
		ball.setPosition(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT);
		ball.setFillColor(sf::Color::White);
		balls.push_back(ball);
	}

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();

		const float dt = clock.restart().asSeconds();
		for (auto& ball : balls) {

			sf::Vector2f position = ball.getPosition();
			sf::Vector2f speed = ball.getSpeed();
			position += speed * dt;

			if ((position.x + 2 * BALL_SIZE >= WINDOW_WIDTH) && (speed.x > 0)) {
				ball.changeVectX();
			}

			if ((position.x < 0) && (speed.x < 0)) {
				ball.changeVectX();
			}

			if ((position.y + 2 * BALL_SIZE >= WINDOW_HEIGHT) && (speed.y > 0)) {
				ball.changeVectY();
			}

			if ((position.y < 0) && (speed.y < 0)) {
				ball.changeVectY();
			}
			ball.setPosition(position);
			window.draw(ball);
		}

		//std::cout << 1 / dt << std::endl; //fps
		window.display();


	}

	return 0;
}