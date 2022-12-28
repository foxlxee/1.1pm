#include "Application.h"

namespace mo {
	Application* Application::m_instance = nullptr;

	Application::Application() : m_mainWindow(sf::VideoMode(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT), "Bouncing Ball", sf::Style::Close) {
		m_mainWindow.setFramerateLimit(60);
	}

	Application* Application::instance() {
		if (m_instance == nullptr) {
			m_instance = new Application;
		}
		return m_instance;
	}

	int Application::run() {
		while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			sf::Event event;
			while (m_mainWindow.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					m_mainWindow.close();
					return 0;
				}
			}

			m_mainWindow.clear(sf::Color::White);

			m_ball.update();

			m_mainWindow.draw(m_ball);
			m_mainWindow.display();
		}

		return 0;
	}
}