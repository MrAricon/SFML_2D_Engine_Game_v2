#include "../headers/Player.h"

Player::Player(std::string pTextureFile, sf::Vector2f pPosition, sf::Vector2f pSize) : Entity(pTextureFile, pPosition, pSize)
{
}

void Player::calcMovement(sf::Time pDeltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) == true)
	{
		setAccUp(getAccUp() + getAcc() * pDeltaTime.asSeconds());
		setFacing(1);
		if (getAccUp() >= getMaxSpeed())
		{
			setAccUp(getMaxSpeed());
		}
	}
	else
	{
		setAccUp(getAccUp() - getFriction() * pDeltaTime.asSeconds());
		if (getAccUp() <= 0)
		{
			setAccUp(0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) == true)
	{
		setAccLeft(getAccLeft() + getAcc() * pDeltaTime.asSeconds());
		setFacing(2);
		if (getAccLeft() >= getMaxSpeed())
		{
			setAccLeft(getMaxSpeed());
		}
	}
	else
	{
		setAccLeft(getAccLeft() - getFriction() * pDeltaTime.asSeconds());
		if (getAccLeft() < 0)
		{
			setAccLeft(0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) == true)
	{
		setAccDown(getAccDown() + getAcc() * pDeltaTime.asSeconds());
		setFacing(3);
		if (getAccDown() >= getMaxSpeed())
		{
			setAccDown(getMaxSpeed());
		}
	}
	else
	{
		setAccDown(getAccDown() - getFriction() * pDeltaTime.asSeconds());
		if (getAccDown() <= 0)
		{
			setAccDown(0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) == true)
	{
		setAccRight(getAccRight() + getAcc() * pDeltaTime.asSeconds());
		setFacing(4);
		if (getAccRight() >= getMaxSpeed())
		{
			setAccRight(getMaxSpeed());
		}
	}
	else
	{
		setAccRight(getAccRight() - getFriction() * pDeltaTime.asSeconds());
		if (getAccRight() <= 0)
		{
			setAccRight(0);
		}
	}
}
