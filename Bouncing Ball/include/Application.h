#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"

#define MAIN_WINDOW_WIDTH 800
#define MAIN_WINDOW_HEIGHT 600

namespace mo {
	class Application {
	private:
		Ball m_ball;
		sf::RenderWindow m_mainWindow;
		static Application* m_instance;
		Application();
	public:
		static Application* instance();
		int run();
	};
}