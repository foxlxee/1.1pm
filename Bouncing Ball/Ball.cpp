#include "Ball.h"
#include "Application.h"

#define RADIUS 100.f
#define INITIAL_SPEED 3.f
#define STEP 0.05f
#define MAX_SPEED 5.f
#define MIN_SPEED 0.5f

namespace mo {
	Ball::Ball() : sf::CircleShape(RADIUS, 100),
		m_currentColorIndex(-1),
		m_xSpeed(INITIAL_SPEED),
		m_ySpeed(INITIAL_SPEED),
		m_xMax(MAIN_WINDOW_WIDTH - RADIUS * 2),
		m_yMax(MAIN_WINDOW_HEIGHT - RADIUS * 2) {
		srand(time(NULL));
		
		changeColor();
		setPosition(sf::Vector2f(rand() % m_xMax, rand() % m_yMax));
		m_xSpeed *= rand() % 1001 >= 500 ? 1 : -1;
		m_ySpeed *= rand() % 1001 >= 500 ? 1 : -1;
	}

	void Ball::increaseSpeed() {
		float newXSpeed = m_xSpeed;
		float newYSpeed = m_ySpeed;

		if (newXSpeed < 0) {
			newXSpeed -= STEP;
		} else {
			newXSpeed += STEP;
		}

		if (newYSpeed < 0) {
			newYSpeed -= STEP;
		} else {
			newYSpeed += STEP;
		}

		if (abs(newXSpeed) <= MAX_SPEED) {
			m_xSpeed = newXSpeed;
		}

		if (abs(newYSpeed) <= MAX_SPEED) {
			m_ySpeed = newYSpeed;
		}
	}

	void Ball::decreaseSpeed() {
		float newXSpeed = m_xSpeed;
		float newYSpeed = m_ySpeed;

		if (newXSpeed < 0) {
			newXSpeed += STEP;
		} else {
			newXSpeed -= STEP;
		}

		if (newYSpeed < 0) {
			newYSpeed += STEP;
		} else {
			newYSpeed -= STEP;
		}

		if (abs(newXSpeed) >= MIN_SPEED) {
			m_xSpeed = newXSpeed;
		}

		if (abs(newYSpeed) >= MIN_SPEED) {
			m_ySpeed = newYSpeed;
		}
	}

	void Ball::changeColor() {
		int value = -1;
		
		do {
			value = rand() % 6;
		} while (value == m_currentColorIndex);

		m_currentColorIndex = value;

		switch (value) {
		case 0:
			setFillColor(sf::Color::Magenta);
			break;
		case 1:
			setFillColor(sf::Color::Red);
			break;
		case 2:
			setFillColor(sf::Color::Green);
			break;
		case 3:
			setFillColor(sf::Color::Blue);
			break;
		case 4:
			setFillColor(sf::Color::Yellow);
			break;
		case 5:
			setFillColor(sf::Color::Cyan);
			break;
		}
	}

	void Ball::update() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			increaseSpeed();
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			decreaseSpeed();
		}

		move(m_xSpeed, m_ySpeed);

		const sf::Vector2f& position = getPosition();

		bool hit = false;

		if (position.x > m_xMax || position.x < 0) {
			m_xSpeed *= -1;
			hit = true;
		}
		
		if (position.y > m_yMax || position.y < 0) {
			m_ySpeed *= -1;
			hit = true;
		}

		if (hit) {
			changeColor();
		}
	}
}