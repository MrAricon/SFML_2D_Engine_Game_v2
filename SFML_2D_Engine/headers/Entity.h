#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Entity
{
private:
	sf::Vector2f position;
	sf::RectangleShape entityRec;
	sf::Vector2f entityRecSize;
	sf::Texture entityText;

	int health;
	int attackDMG;

	float maxSpeed = 400.0f;
	float acc = 2000.0f;
	float friction = 1700.0f;

	float accUp = 0.0f;
	float accDown = 0.0f;
	float accLeft = 0.0f;
	float accRight = 0.0f;

	int facing = 1;

public:
	// Constructors
	Entity();
	Entity(sf::Vector2f pPosition, sf::Vector2f pSize);
	Entity(std::string pTextureFile, sf::Vector2f pPosition, sf::Vector2f pSize);

	// Getters
	sf::Vector2f getPosition();
	sf::RectangleShape getEntityRec();
	sf::Vector2f getSize();
	int getHealth();
	int getAttackDMG();
	float getMaxSpeed();
	float getAcc();
	float getFriction();
	float getAccUp();
	float getAccDown();
	float getAccLeft();
	float getAccRight();
	float getFacing();

	// Setters
	void setPosition(sf::Vector2f pPosition);
	void setHealth(int pHealth);
	void setAttackDMG(int pAttackDMG);
	void setAccUp(float pAccUp);
	void setAccDown(float pAccDown);
	void setAccLeft(float pAccLeft);
	void setAccRight(float pAccRight);
	void setFacing(int pFacing);
	void setMaxSpeed(float pMaxSpeed);

	// Methods
	void applyMovement(sf::Time pDeltaTime);

};