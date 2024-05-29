#include "../headers/Enemy.h"

Enemy::Enemy() : Entity() {};

Enemy::Enemy(sf::Vector2f pPosition, sf::Vector2f pSize) : Entity(pPosition, pSize)
{
	exsists = true;
	setMaxSpeed(100.0f);
}

bool Enemy::getExsits()
{
	return exsists;
}

void Enemy::setExsists(bool pExsists)
{
	exsists = pExsists;
}

void Enemy::calcMovement(sf::Time pDeltaTime, Player pPlayer)
{
	if (pPlayer.getPosition().y < getPosition().y)
	{
		setAccUp(getAccUp() + getAcc() / 4 * pDeltaTime.asSeconds());
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

	if (pPlayer.getPosition().y > getPosition().y)
	{
		setAccDown(getAccDown() + getAcc() / 4 * pDeltaTime.asSeconds());
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
	
	if (pPlayer.getPosition().x < getPosition().x)
	{
		setAccLeft(getAccLeft() + getAcc() / 4 * pDeltaTime.asSeconds());
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

	if (pPlayer.getPosition().x > getPosition().x)
	{
		setAccRight(getAccRight() + getAcc() / 4 * pDeltaTime.asSeconds());
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
