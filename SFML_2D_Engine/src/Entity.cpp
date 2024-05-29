#include "../headers/Entity.h"

Entity::Entity() {}

Entity::Entity(sf::Vector2f pPosition, sf::Vector2f pSize)
{
	entityRecSize = pSize;
	entityRec.setSize(entityRecSize);
	setPosition(pPosition);
	entityRec.setPosition(position);
}

Entity::Entity(std::string pTextureFile, sf::Vector2f pPosition, sf::Vector2f pSize)
{
	entityText.loadFromFile(pTextureFile);
	entityRec.setTexture(&entityText);
	entityRecSize = pSize;
	entityRec.setSize(entityRecSize);
	setPosition(pPosition);
	entityRec.setPosition(position);
}

sf::Vector2f Entity::getPosition()
{
	return position;
}

sf::RectangleShape Entity::getEntityRec()
{
	return entityRec;
}

sf::Vector2f Entity::getSize()
{
	return entityRecSize;
}

int Entity::getHealth()
{
	return health;
}

int Entity::getAttackDMG()
{
	return attackDMG;
}

float Entity::getMaxSpeed()
{
	return maxSpeed;
}

float Entity::getAcc()
{
	return acc;
}

float Entity::getFriction()
{
	return friction;
}

float Entity::getAccUp()
{
	return accUp;
}

float Entity::getAccDown()
{
	return accDown;
}

float Entity::getAccLeft()
{
	return accLeft;
}

float Entity::getAccRight()
{
	return accRight;
}

float Entity::getFacing()
{
	return facing;
}

void Entity::setPosition(sf::Vector2f pPosition)
{
	position = pPosition;
	entityRec.setPosition(position);
}

void Entity::setHealth(int pHealth)
{
	health = pHealth;
}

void Entity::setAttackDMG(int pAttackDMG)
{
	attackDMG = pAttackDMG;
}

void Entity::setAccUp(float pAccUp)
{
	accUp = pAccUp;
}

void Entity::setAccDown(float pAccDown)
{
	accDown = pAccDown;
}

void Entity::setAccLeft(float pAccLeft)
{
	accLeft = pAccLeft;
}

void Entity::setAccRight(float pAccRight)
{
	accRight = pAccRight;
}

void Entity::setFacing(int pFacing)
{
	facing = pFacing;
}

void Entity::setMaxSpeed(float pMaxSpeed)
{
	maxSpeed = pMaxSpeed;
}

void Entity::applyMovement(sf::Time pDeltaTime)
{
	setPosition(sf::Vector2f(getPosition().x + getAccRight() * pDeltaTime.asSeconds(), getPosition().y));
	setPosition(sf::Vector2f(getPosition().x - getAccLeft() * pDeltaTime.asSeconds(), getPosition().y));
	setPosition(sf::Vector2f(getPosition().x, getPosition().y + getAccDown() * pDeltaTime.asSeconds()));
	setPosition(sf::Vector2f(getPosition().x, getPosition().y - getAccUp() * pDeltaTime.asSeconds()));

	setPosition(position);
}