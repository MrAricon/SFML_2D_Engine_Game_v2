#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Entity.h"

class Obstacle
{
private:
	sf::Vector2f position;
	sf::Vector2f size;

	bool exists;

	bool bomb;
	int marked;
	int type;

	static void populateObstacle(int x, int y, Obstacle (&pObstacles)[8][12]);

public:
	// Constructor
	Obstacle();

	// Getter
	sf::Vector2f getPostion();
	sf::Vector2f getSize();
	bool getExists();
	bool getBomb();
	int getMarkerd();
	int getType();

	// Setters
	void setPosition(sf::Vector2f pPosition);
	void setExists(bool pExsists);

	// Methods
	static void obstacles(Obstacle (&pObstacles)[8][12]);
};