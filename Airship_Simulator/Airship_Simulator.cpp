// Airship_Simulator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"
#include "SFML/Graphics.hpp"
#include "Deck.h"

#include <vector>

int main()
{
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "SFML DEMO");

	sf::Event event;

	Propeller prop(144, 21);
	Engine eng(prop, 4, 12, 50, 4, 8, .25, Engine::CENTER, Engine::BASIC);
	
	eng.setThrottle(50);
	eng.updateStats(0, 300, 1000, 0);

	printf("Torque: %f\n", eng.getTorque());
	printf("Horsepower: %f\n", eng.getHorsePower());
	printf("Thrust: %f\n", eng.getThrustProduced());
	printf("RPMs: %f\n", eng.getRpms());
	printf("Steam needed: %f\n", eng.getSteamNeededPerSec());

	while (renderWindow.isOpen()) {
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed) {
				renderWindow.close();
			}
		}

		renderWindow.clear();
		renderWindow.display();
	}

	

    return 0;
}

