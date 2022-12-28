#pragma once
#include <SFML/Graphics.hpp>
namespace mo {
	class Ball : public sf::CircleShape {
	private:
		float m_xSpeed;
		float m_ySpeed;
		int m_currentColorIndex;
		unsigned int m_xMax;
		unsigned int m_yMax;
	public:
		Ball();
		void update();
		void changeColor();
		void increaseSpeed();
		void decreaseSpeed();
	};
}