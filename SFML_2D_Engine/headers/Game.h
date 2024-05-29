#pragma once

#include "Entity.h"
#include "Room.h"

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <random>

class Game
{
private:
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Vector2f mousePosition;

	sf::Clock deltaClock;
	sf::Time deltaTime;

	int floorNum;

public:
	sf::RenderWindow* window = nullptr;

	// Constructor
	Game();

	// Getters
	sf::Time getDeltaTime();
	int getFloorNum();

	// Setters
	void updateDeltaTime();

	// Methods
	void pollEvents();
	bool mousePos(int x, int y, int width, int height, bool click);
	void render();

	void colisions(Entity &pEntity, Obstacle pObstacles[8][12], Room pRoom);
};

