#include "../headers/Game.h"

Game::Game()
{
	videoMode.width = 1080;
	videoMode.height = 720;
	window = new sf::RenderWindow(videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
	window->setPosition(sf::Vector2i(150, 100));
	window->setFramerateLimit(144);
	//window->setPosition(sf::Vector2i(100, -1000));

	floorNum = 0;
}

sf::Time Game::getDeltaTime()
{
	return deltaTime;
}

int Game::getFloorNum()
{
	return floorNum;
}

void Game::updateDeltaTime()
{
	deltaTime = deltaClock.restart();
}

void Game::pollEvents()
{
	while (window->pollEvent(ev))
	{
		sf::Vector2i winPos = window->getPosition();
		sf::Vector2i mousePosition = sf::Mouse::getPosition();
		switch (ev.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
				window->close();
			if (ev.key.code == sf::Keyboard::C)
			{
				system("cls");
			}
			break;
		case sf::Event::MouseButtonPressed:

			break;
		case sf::Event::MouseButtonReleased:
			mousePosition.x = mousePosition.x - winPos.x - 8;
			mousePosition.y = mousePosition.y - winPos.y - 30;
			std::cout << mousePosition.x << " " << mousePosition.y << "\n";

			break;
		}
	}
}

bool Game::mousePos(int x, int y, int width, int height, bool click)
{
	sf::Vector2i winPos = window->getPosition();
	sf::Vector2i mousePos = sf::Mouse::getPosition();
	int mouseX = mousePos.x - winPos.x - 9;
	int mouseY = mousePos.y - winPos.y - 30;

	if (x < mouseX && x + width > mouseX && y < mouseY && y + height > mouseY)
	{
		if (click == true && ev.type == sf::Event::MouseButtonReleased)
		{
			return true;
		}
		else if (click == false)
		{
			return true;
		}
	}
	return false;
}

void Game::render()
{
	window->display();
	window->clear();
	updateDeltaTime();
}

void Game::colisions(Entity &pEntity, Obstacle pObstacles[8][12], Room pRoom)
{
	float diff = 3.0f;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (pObstacles[i][j].getExists() == true)
			{
				// Right
				if ((pEntity.getPosition().x > pObstacles[i][j].getPostion().x - (pEntity.getSize().x + diff) && pEntity.getPosition().x < pObstacles[i][j].getPostion().x) &&
					(pEntity.getPosition().x + pEntity.getSize().x > pObstacles[i][j].getPostion().x - (pEntity.getSize().x + diff) && pEntity.getPosition().x + pEntity.getSize().x < pObstacles[i][j].getPostion().x + diff))
				{
					if (pEntity.getPosition().x + pEntity.getSize().x > pObstacles[i][j].getPostion().x && pEntity.getPosition().x < pObstacles[i][j].getPostion().x + pObstacles[i][j].getSize().x && pEntity.getPosition().y + pEntity.getSize().y > pObstacles[i][j].getPostion().y && pEntity.getPosition().y < pObstacles[i][j].getPostion().y + pObstacles[i][j].getSize().y)
					{
						pEntity.setPosition(sf::Vector2f(pObstacles[i][j].getPostion().x - pEntity.getSize().x, pEntity.getPosition().y));
						pEntity.setAccRight(0);
					}
				}

				// Up
				if ((pEntity.getPosition().y < pObstacles[i][j].getPostion().y + pObstacles[i][j].getSize().y + (pEntity.getSize().y + diff) && pEntity.getPosition().y > pObstacles[i][j].getPostion().y + pObstacles[i][j].getSize().y - diff) &&
					(pEntity.getPosition().y + pEntity.getSize().y < pObstacles[i][j].getPostion().y + pObstacles[i][j].getSize().y + (pEntity.getSize().y + diff) && pEntity.getPosition().y + pEntity.getSize().y > pObstacles[i][j].getPostion().y + pObstacles[i][j].getSize().y - diff))
				{
					if (pEntity.getPosition().x + pEntity.getSize().x > pObstacles[i][j].getPostion().x && pEntity.getPosition().x < pObstacles[i][j].getPostion().x + pObstacles[i][j].getSize().x && pEntity.getPosition().y + pEntity.getSize().y > pObstacles[i][j].getPostion().y && pEntity.getPosition().y < pObstacles[i][j].getPostion().y + pObstacles[i][j].getSize().y)
					{
						pEntity.setPosition(sf::Vector2f(pEntity.getPosition().x, pObstacles[i][j].getPostion().y + pObstacles[i][j].getSize().y));
						pEntity.setAccUp(0);
					}
				}

				// Left
				if ((pEntity.getPosition().x < pObstacles[i][j].getPostion().x + pObstacles[i][j].getSize().x + (pEntity.getSize().x + diff) && pEntity.getPosition().x > pObstacles[i][j].getPostion().x + pObstacles[i][j].getSize().x - diff) &&
					(pEntity.getPosition().x + pEntity.getSize().x < pObstacles[i][j].getPostion().x + pObstacles[i][j].getSize().x + (pEntity.getSize().x + diff) && pEntity.getPosition().x + pEntity.getSize().x > pObstacles[i][j].getPostion().x + pObstacles[i][j].getSize().x - diff))
				{
					if (pEntity.getPosition().x + pEntity.getSize().x > pObstacles[i][j].getPostion().x && pEntity.getPosition().x < pObstacles[i][j].getPostion().x + pObstacles[i][j].getSize().x && pEntity.getPosition().y + pEntity.getSize().y > pObstacles[i][j].getPostion().y && pEntity.getPosition().y < pObstacles[i][j].getPostion().y + pObstacles[i][j].getSize().y)
					{
						pEntity.setPosition(sf::Vector2f(pObstacles[i][j].getPostion().x + pObstacles[i][j].getSize().x, pEntity.getPosition().y));
						pEntity.setAccLeft(0);
					}
				}

				// Down
				if ((pEntity.getPosition().y > pObstacles[i][j].getPostion().y - (pEntity.getSize().y + diff) && pEntity.getPosition().y < pObstacles[i][j].getPostion().y) &&
					(pEntity.getPosition().y + pEntity.getSize().y > pObstacles[i][j].getPostion().y - (pEntity.getSize().y + diff) && pEntity.getPosition().y + pEntity.getSize().y < pObstacles[i][j].getPostion().y + diff))
				{
					if (pEntity.getPosition().x + pEntity.getSize().x > pObstacles[i][j].getPostion().x && pEntity.getPosition().x < pObstacles[i][j].getPostion().x + pObstacles[i][j].getSize().x && pEntity.getPosition().y + pEntity.getSize().y > pObstacles[i][j].getPostion().y && pEntity.getPosition().y < pObstacles[i][j].getPostion().y + pObstacles[i][j].getSize().y)
					{
						pEntity.setPosition(sf::Vector2f(pEntity.getPosition().x, pObstacles[i][j].getPostion().y - pEntity.getSize().y));
						pEntity.setAccDown(0);
					}
				}
			}
		}
	}

	if (pRoom.getEnemies() == true)
	{
		if ((pEntity.getPosition().y < 60.0f + 60.0f + (pEntity.getSize().y + diff) && pEntity.getPosition().y > 60.0f + 60.0f - diff) &&
				(pEntity.getPosition().y + pEntity.getSize().y < 60.0f + 60.0f + (pEntity.getSize().y + diff) && pEntity.getPosition().y + pEntity.getSize().y > 60.0f + 60.0f - diff))
		{
			if (pEntity.getPosition().x + pEntity.getSize().x > 180.0f && pEntity.getPosition().x < 180.0f + 720.0f && pEntity.getPosition().y + pEntity.getSize().y > 60.0f && pEntity.getPosition().y < 60.0f + 60.0f)
			{
				pEntity.setPosition(sf::Vector2f(pEntity.getPosition().x, 60.0f + 60.0f));
				pEntity.setAccUp(0);
			}
		}

		if ((pEntity.getPosition().y > 598.0f - (pEntity.getSize().y + diff) && pEntity.getPosition().y < 598.0f) &&
			(pEntity.getPosition().y + pEntity.getSize().y > 598.0f - (pEntity.getSize().y + diff) && pEntity.getPosition().y + pEntity.getSize().y < 598.0f + diff))
		{
			if (pEntity.getPosition().x + pEntity.getSize().x > 180.0f && pEntity.getPosition().x < 180.0f + 720.0f && pEntity.getPosition().y + pEntity.getSize().y > 598.0f && pEntity.getPosition().y < 598.0f + 60.0f)
			{
				pEntity.setPosition(sf::Vector2f(pEntity.getPosition().x, 598.0f - pEntity.getSize().y));
				pEntity.setAccDown(0);
			}
		}

		if ((pEntity.getPosition().x < 120.0f + 60.0f + (pEntity.getSize().x + diff) && pEntity.getPosition().x > 120.0f + 60.0f - diff) &&
			(pEntity.getPosition().x + pEntity.getSize().x < 120.0f + 60.0f + (pEntity.getSize().x + diff) && pEntity.getPosition().x + pEntity.getSize().x > 120.0f + 60.0f - diff))
		{
			if (pEntity.getPosition().x + pEntity.getSize().x > 120.0f && pEntity.getPosition().x < 120.0f + 60.0f && pEntity.getPosition().y + pEntity.getSize().y > 120.0f && pEntity.getPosition().y < 120.0f + 598.0f)
			{
				pEntity.setPosition(sf::Vector2f(120.0f + 60.0f, pEntity.getPosition().y));
				pEntity.setAccLeft(0);
			}
		}

		if ((pEntity.getPosition().x > 898.0f - (pEntity.getSize().x + diff) && pEntity.getPosition().x < 898.0f) &&
			(pEntity.getPosition().x + pEntity.getSize().x > 898.0f - (pEntity.getSize().x + diff) && pEntity.getPosition().x + pEntity.getSize().x < 898.0f + diff))
		{
			if (pEntity.getPosition().x + pEntity.getSize().x > 898.0f && pEntity.getPosition().x < 898.0f + 60.0f && pEntity.getPosition().y + pEntity.getSize().y > 120.0f && pEntity.getPosition().y < 120.0f + 598.0f)
			{
				pEntity.setPosition(sf::Vector2f(898.0f - pEntity.getSize().x, pEntity.getPosition().y));
				pEntity.setAccRight(0);
			}
		}
	}
	else
	{
		if (pRoom.getDoorUp() == true)
		{
			if ((pEntity.getPosition().y < 60.0f + 60.0f + (pEntity.getSize().y + diff) && pEntity.getPosition().y > 60.0f + 60.0f - diff) &&
				(pEntity.getPosition().y + pEntity.getSize().y < 60.0f + 60.0f + (pEntity.getSize().y + diff) && pEntity.getPosition().y + pEntity.getSize().y > 60.0f + 60.0f - diff))
			{
				if (pEntity.getPosition().x + pEntity.getSize().x > 180.0f && pEntity.getPosition().x < 180.0f + 320.0f && pEntity.getPosition().y + pEntity.getSize().y > 60.0f && pEntity.getPosition().y < 60.0f + 60.0f)
				{
					pEntity.setPosition(sf::Vector2f(pEntity.getPosition().x, 60.0f + 60.0f));
					pEntity.setAccUp(0);
				}
			}

			if ((pEntity.getPosition().y < 60.0f + 60.0f + (pEntity.getSize().y + diff) && pEntity.getPosition().y > 60.0f + 60.0f - diff) &&
				(pEntity.getPosition().y + pEntity.getSize().y < 60.0f + 60.0f + (pEntity.getSize().y + diff) && pEntity.getPosition().y + pEntity.getSize().y > 60.0f + 60.0f - diff))
			{
				if (pEntity.getPosition().x + pEntity.getSize().x > 180.0f + 80.0f + 320.0f && pEntity.getPosition().x < 180.0f + 320.0f + 80.0f + 320.0f && pEntity.getPosition().y + pEntity.getSize().y > 60.0f && pEntity.getPosition().y < 60.0f + 60.0f)
				{
					pEntity.setPosition(sf::Vector2f(pEntity.getPosition().x, 60.0f + 60.0f));
					pEntity.setAccUp(0);
				}
			}
		}
		else
		{
			if ((pEntity.getPosition().y < 60.0f + 60.0f + (pEntity.getSize().y + diff) && pEntity.getPosition().y > 60.0f + 60.0f - diff) &&
				(pEntity.getPosition().y + pEntity.getSize().y < 60.0f + 60.0f + (pEntity.getSize().y + diff) && pEntity.getPosition().y + pEntity.getSize().y > 60.0f + 60.0f - diff))
			{
				if (pEntity.getPosition().x + pEntity.getSize().x > 180.0f && pEntity.getPosition().x < 180.0f + 720.0f && pEntity.getPosition().y + pEntity.getSize().y > 60.0f && pEntity.getPosition().y < 60.0f + 60.0f)
				{
					pEntity.setPosition(sf::Vector2f(pEntity.getPosition().x, 60.0f + 60.0f));
					pEntity.setAccUp(0);
				}
			}
		}

		if (pRoom.getDoorDown() == true)
		{
			if ((pEntity.getPosition().y > 598.0f - (pEntity.getSize().y + diff) && pEntity.getPosition().y < 598.0f) &&
				(pEntity.getPosition().y + pEntity.getSize().y > 598.0f - (pEntity.getSize().y + diff) && pEntity.getPosition().y + pEntity.getSize().y < 598.0f + diff))
			{
				if (pEntity.getPosition().x + pEntity.getSize().x > 180.0f && pEntity.getPosition().x < 180.0f + 320.0f && pEntity.getPosition().y + pEntity.getSize().y > 598.0f && pEntity.getPosition().y < 598.0f + 60.0f)
				{
					pEntity.setPosition(sf::Vector2f(pEntity.getPosition().x, 598.0f - pEntity.getSize().y));
					pEntity.setAccDown(0);
				}
			}

			if ((pEntity.getPosition().y > 598.0f - (pEntity.getSize().y + diff) && pEntity.getPosition().y < 598.0f) &&
				(pEntity.getPosition().y + pEntity.getSize().y > 598.0f - (pEntity.getSize().y + diff) && pEntity.getPosition().y + pEntity.getSize().y < 598.0f + diff))
			{
				if (pEntity.getPosition().x + pEntity.getSize().x > 180.0f + 80.0f + 320.0f && pEntity.getPosition().x < 180.0f + 320.0f + 80.0f + 320.0f && pEntity.getPosition().y + pEntity.getSize().y > 598.0f && pEntity.getPosition().y < 598.0f + 60.0f)
				{
					pEntity.setPosition(sf::Vector2f(pEntity.getPosition().x, 598.0f - pEntity.getSize().y));
					pEntity.setAccDown(0);
				}
			}
		}
		else
		{
			if ((pEntity.getPosition().y > 598.0f - (pEntity.getSize().y + diff) && pEntity.getPosition().y < 598.0f) &&
				(pEntity.getPosition().y + pEntity.getSize().y > 598.0f - (pEntity.getSize().y + diff) && pEntity.getPosition().y + pEntity.getSize().y < 598.0f + diff))
			{
				if (pEntity.getPosition().x + pEntity.getSize().x > 180.0f && pEntity.getPosition().x < 180.0f + 720.0f && pEntity.getPosition().y + pEntity.getSize().y > 598.0f && pEntity.getPosition().y < 598.0f + 60.0f)
				{
					pEntity.setPosition(sf::Vector2f(pEntity.getPosition().x, 598.0f - pEntity.getSize().y));
					pEntity.setAccDown(0);
				}
			}
		}

		if (pRoom.getDoorLeft() == true)
		{
			if ((pEntity.getPosition().x < 120.0f + 60.0f + (pEntity.getSize().x + diff) && pEntity.getPosition().x > 120.0f + 60.0f - diff) &&
				(pEntity.getPosition().x + pEntity.getSize().x < 120.0f + 60.0f + (pEntity.getSize().x + diff) && pEntity.getPosition().x + pEntity.getSize().x > 120.0f + 60.0f - diff))
			{
				if (pEntity.getPosition().x + pEntity.getSize().x > 120.0f && pEntity.getPosition().x < 120.0f + 60.0f && pEntity.getPosition().y + pEntity.getSize().y > 120.0f && pEntity.getPosition().y < 120.0f + 200.0f)
				{
					pEntity.setPosition(sf::Vector2f(120.0f + 60.0f, pEntity.getPosition().y));
					pEntity.setAccLeft(0);
				}
			}

			if ((pEntity.getPosition().x < 120.0f + 60.0f + (pEntity.getSize().x + diff) && pEntity.getPosition().x > 120.0f + 60.0f - diff) &&
				(pEntity.getPosition().x + pEntity.getSize().x < 120.0f + 60.0f + (pEntity.getSize().x + diff) && pEntity.getPosition().x + pEntity.getSize().x > 120.0f + 60.0f - diff))
			{
				if (pEntity.getPosition().x + pEntity.getSize().x > 120.0f && pEntity.getPosition().x < 120.0f + 60.0f && pEntity.getPosition().y + pEntity.getSize().y > 120.0f + 200.0f + 80.0f && pEntity.getPosition().y < 120.0f + 598.0f)
				{
					pEntity.setPosition(sf::Vector2f(120.0f + 60.0f, pEntity.getPosition().y));
					pEntity.setAccLeft(0);
				}
			}
		}
		else
		{
			if ((pEntity.getPosition().x < 120.0f + 60.0f + (pEntity.getSize().x + diff) && pEntity.getPosition().x > 120.0f + 60.0f - diff) &&
				(pEntity.getPosition().x + pEntity.getSize().x < 120.0f + 60.0f + (pEntity.getSize().x + diff) && pEntity.getPosition().x + pEntity.getSize().x > 120.0f + 60.0f - diff))
			{
				if (pEntity.getPosition().x + pEntity.getSize().x > 120.0f && pEntity.getPosition().x < 120.0f + 60.0f && pEntity.getPosition().y + pEntity.getSize().y > 120.0f && pEntity.getPosition().y < 120.0f + 598.0f)
				{
					pEntity.setPosition(sf::Vector2f(120.0f + 60.0f, pEntity.getPosition().y));
					pEntity.setAccLeft(0);
				}
			}
		}

		if (pRoom.getDoorRight() == true)
		{
			if ((pEntity.getPosition().x > 898.0f - (pEntity.getSize().x + diff) && pEntity.getPosition().x < 898.0f) &&
				(pEntity.getPosition().x + pEntity.getSize().x > 898.0f - (pEntity.getSize().x + diff) && pEntity.getPosition().x + pEntity.getSize().x < 898.0f + diff))
			{
				if (pEntity.getPosition().x + pEntity.getSize().x > 898.0f && pEntity.getPosition().x < 898.0f + 60.0f && pEntity.getPosition().y + pEntity.getSize().y > 120.0f && pEntity.getPosition().y < 120.0f + 200.0f)
				{
					pEntity.setPosition(sf::Vector2f(898.0f - pEntity.getSize().x, pEntity.getPosition().y));
					pEntity.setAccRight(0);
				}
			}

			if ((pEntity.getPosition().x > 898.0f - (pEntity.getSize().x + diff) && pEntity.getPosition().x < 898.0f) &&
				(pEntity.getPosition().x + pEntity.getSize().x > 898.0f - (pEntity.getSize().x + diff) && pEntity.getPosition().x + pEntity.getSize().x < 898.0f + diff))
			{
				if (pEntity.getPosition().x + pEntity.getSize().x > 898.0f && pEntity.getPosition().x < 898.0f + 60.0f && pEntity.getPosition().y + pEntity.getSize().y > 120.0f + 200.0f + 80.0f && pEntity.getPosition().y < 120.0f + 598.0f)
				{
					pEntity.setPosition(sf::Vector2f(898.0f - pEntity.getSize().x, pEntity.getPosition().y));
					pEntity.setAccRight(0);
				}
			}
		}
		else
		{
			if ((pEntity.getPosition().x > 898.0f - (pEntity.getSize().x + diff) && pEntity.getPosition().x < 898.0f) &&
				(pEntity.getPosition().x + pEntity.getSize().x > 898.0f - (pEntity.getSize().x + diff) && pEntity.getPosition().x + pEntity.getSize().x < 898.0f + diff))
			{
				if (pEntity.getPosition().x + pEntity.getSize().x > 898.0f && pEntity.getPosition().x < 898.0f + 60.0f && pEntity.getPosition().y + pEntity.getSize().y > 120.0f && pEntity.getPosition().y < 120.0f + 598.0f)
				{
					pEntity.setPosition(sf::Vector2f(898.0f - pEntity.getSize().x, pEntity.getPosition().y));
					pEntity.setAccRight(0);
				}
			}
		}
	}
}

/*
if (pRoom.getEnemies() == true)
	{ii
		if ((pEntity.getPosition().y < 60.0f + 60.0f + (pEntity.getSize().y + diff) && pEntity.getPosition().y > 60.0f + 60.0f - diff) &&
				(pEntity.getPosition().y + pEntity.getSize().y < 60.0f + 60.0f + (pEntity.getSize().y + diff) && pEntity.getPosition().y + pEntity.getSize().y > 60.0f + 60.0f - diff))
		{
			if (pEntity.getPosition().x + pEntity.getSize().x > 180.0f && pEntity.getPosition().x < 180.0f + 720.0f && pEntity.getPosition().y + pEntity.getSize().y > 60.0f && pEntity.getPosition().y < 60.0f + 60.0f)
			{
				pEntity.setPosition(sf::Vector2f(pEntity.getPosition().x, 60.0f + 60.0f));
				pEntity.setAccUp(0);
			}
		}

		if ((pEntity.getPosition().y > 598.0f - (pEntity.getSize().y + diff) && pEntity.getPosition().y < 598.0f) &&
			(pEntity.getPosition().y + pEntity.getSize().y > 598.0f - (pEntity.getSize().y + diff) && pEntity.getPosition().y + pEntity.getSize().y < 598.0f + diff))
		{
			if (pEntity.getPosition().x + pEntity.getSize().x > 180.0f && pEntity.getPosition().x < 180.0f + 720.0f && pEntity.getPosition().y + pEntity.getSize().y > 598.0f && pEntity.getPosition().y < 598.0f + 60.0f)
			{
				pEntity.setPosition(sf::Vector2f(pEntity.getPosition().x, 598.0f - pEntity.getSize().y));
				pEntity.setAccDown(0);
			}
		}

		if ((pEntity.getPosition().x < 120.0f + 60.0f + (pEntity.getSize().x + diff) && pEntity.getPosition().x > 120.0f + 60.0f - diff) &&
			(pEntity.getPosition().x + pEntity.getSize().x < 120.0f + 60.0f + (pEntity.getSize().x + diff) && pEntity.getPosition().x + pEntity.getSize().x > 120.0f + 60.0f - diff))
		{
			if (pEntity.getPosition().x + pEntity.getSize().x > 120.0f && pEntity.getPosition().x < 120.0f + 60.0f && pEntity.getPosition().y + pEntity.getSize().y > 120.0f && pEntity.getPosition().y < 120.0f + 598.0f)
			{
				pEntity.setPosition(sf::Vector2f(120.0f + 60.0f, pEntity.getPosition().y));
				pEntity.setAccLeft(0);
			}
		}

		if ((pEntity.getPosition().x > 898.0f - (pEntity.getSize().x + diff) && pEntity.getPosition().x < 898.0f) &&
			(pEntity.getPosition().x + pEntity.getSize().x > 898.0f - (pEntity.getSize().x + diff) && pEntity.getPosition().x + pEntity.getSize().x < 898.0f + diff))
		{
			if (pEntity.getPosition().x + pEntity.getSize().x > 898.0f && pEntity.getPosition().x < 898.0f + 60.0f && pEntity.getPosition().y + pEntity.getSize().y > 120.0f && pEntity.getPosition().y < 120.0f + 598.0f)
			{
				pEntity.setPosition(sf::Vector2f(898.0f - pEntity.getSize().x, pEntity.getPosition().y));
				pEntity.setAccRight(0);
			}
		}
	}
	else
	{
		if ((pEntity.getPosition().y < 60.0f + 60.0f + (pEntity.getSize().y + diff) && pEntity.getPosition().y > 60.0f + 60.0f - diff) &&
			(pEntity.getPosition().y + pEntity.getSize().y < 60.0f + 60.0f + (pEntity.getSize().y + diff) && pEntity.getPosition().y + pEntity.getSize().y > 60.0f + 60.0f - diff))
		{
			if (pEntity.getPosition().x + pEntity.getSize().x > 180.0f && pEntity.getPosition().x < 180.0f + 320.0f && pEntity.getPosition().y + pEntity.getSize().y > 60.0f && pEntity.getPosition().y < 60.0f + 60.0f)
			{
				pEntity.setPosition(sf::Vector2f(pEntity.getPosition().x, 60.0f + 60.0f));
				pEntity.setAccUp(0);
			}
		}

		if ((pEntity.getPosition().y > 598.0f - (pEntity.getSize().y + diff) && pEntity.getPosition().y < 598.0f) &&
			(pEntity.getPosition().y + pEntity.getSize().y > 598.0f - (pEntity.getSize().y + diff) && pEntity.getPosition().y + pEntity.getSize().y < 598.0f + diff))
		{
			if (pEntity.getPosition().x + pEntity.getSize().x > 180.0f && pEntity.getPosition().x < 180.0f + 720.0f && pEntity.getPosition().y + pEntity.getSize().y > 598.0f && pEntity.getPosition().y < 598.0f + 60.0f)
			{
				pEntity.setPosition(sf::Vector2f(pEntity.getPosition().x, 598.0f - pEntity.getSize().y));
				pEntity.setAccDown(0);
			}
		}

		if ((pEntity.getPosition().x < 120.0f + 60.0f + (pEntity.getSize().x + diff) && pEntity.getPosition().x > 120.0f + 60.0f - diff) &&
			(pEntity.getPosition().x + pEntity.getSize().x < 120.0f + 60.0f + (pEntity.getSize().x + diff) && pEntity.getPosition().x + pEntity.getSize().x > 120.0f + 60.0f - diff))
		{
			if (pEntity.getPosition().x + pEntity.getSize().x > 120.0f && pEntity.getPosition().x < 120.0f + 60.0f && pEntity.getPosition().y + pEntity.getSize().y > 120.0f && pEntity.getPosition().y < 120.0f + 598.0f)
			{
				pEntity.setPosition(sf::Vector2f(120.0f + 60.0f, pEntity.getPosition().y));
				pEntity.setAccLeft(0);
			}
		}

		if ((pEntity.getPosition().x > 898.0f - (pEntity.getSize().x + diff) && pEntity.getPosition().x < 898.0f) &&
			(pEntity.getPosition().x + pEntity.getSize().x > 898.0f - (pEntity.getSize().x + diff) && pEntity.getPosition().x + pEntity.getSize().x < 898.0f + diff))
		{
			if (pEntity.getPosition().x + pEntity.getSize().x > 898.0f && pEntity.getPosition().x < 898.0f + 60.0f && pEntity.getPosition().y + pEntity.getSize().y > 120.0f && pEntity.getPosition().y < 120.0f + 598.0f)
			{
				pEntity.setPosition(sf::Vector2f(898.0f - pEntity.getSize().x, pEntity.getPosition().y));
				pEntity.setAccRight(0);
			}
		}
	}
*/