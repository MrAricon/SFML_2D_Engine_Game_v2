#include "../headers/Game.h"
#include "../headers/Display.h"
#include "../headers/Entity.h"
#include "../headers/Player.h"
#include "../headers/Enemy.h"
#include "../headers/Obstacle.h"
#include "../headers/Room.h"
#include "../headers/Floor.h"

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 2);

	std::srand(gen());

	Game game;

	Player player("assets/player4.png", sf::Vector2f(510.0f, 330.0f), sf::Vector2f(64.0f, 64.0f));

	sf::RectangleShape playerRec;

	Enemy enemy;

	sf::RectangleShape enemyRec;

	Obstacle obstacles[8][12];

	Room rooms[4][4];

	Floor floors[4];

	sf::Texture player1;
	player1.loadFromFile("assets/player1.png");

	sf::Texture player2;
	player2.loadFromFile("assets/player2.png");
	
	sf::Texture player3;
	player3.loadFromFile("assets/player3.png");
	
	sf::Texture player4;
	player4.loadFromFile("assets/player4.png");

	sf::Texture enemy1;
	enemy1.loadFromFile("assets/enemy1.png");

	sf::Texture enemy2;
	enemy2.loadFromFile("assets/enemy2.png");

	sf::Texture enemy3;
	enemy3.loadFromFile("assets/enemy3.png");
	
	sf::Texture enemy4;
	enemy4.loadFromFile("assets/enemy4.png");

	sf::Texture rocksTex;
	rocksTex.loadFromFile("assets/rocks.png");

	sf::Texture doorTex;
	doorTex.loadFromFile("assets/door.png");

	sf::Texture openDoor;
	openDoor.loadFromFile("assets/doorOpen.png");

	sf::Texture closedDoorTex;
	closedDoorTex.loadFromFile("assets/doorClosed.png");

	sf::RectangleShape doorRec;
	doorRec.setSize(sf::Vector2f(98.0f, 66.0f));

	sf::RectangleShape roomRecTex;
	sf::Texture roomTex;

	roomTex.loadFromFile("assets/room.png");
	roomRecTex.setTexture(&roomTex);
	roomRecTex.setSize(sf::Vector2f(1080, 720));

	floors[0].getRooms(rooms);

	rooms[floors[0].getRoomY()][floors[0].getRoomX()].getObstacles(obstacles);
	rooms[floors[0].getRoomY()][floors[0].getRoomX()].getEnemy(enemy);

	enemyRec.setTexture(&enemy1);

	while (game.window->isOpen())
	{
		std::srand(gen());

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) == true)
		{
			rooms[floors[0].getRoomY()][floors[0].getRoomX()].setEnemies(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) == true)
		{
			rooms[floors[0].getRoomY()][floors[0].getRoomX()].setEnemies(false);
		}

		game.pollEvents();

		if (floors[0].getRoomChange() == true)
		{
			rooms[floors[0].getRoomY()][floors[0].getRoomX()].getObstacles(obstacles);
			rooms[floors[0].getRoomY()][floors[0].getRoomX()].getEnemy(enemy);
			floors[0].setRoomChange(false);
		}
		
		player.calcMovement(game.getDeltaTime());

		enemy.calcMovement(game.getDeltaTime(), player);

		game.colisions(player, obstacles, rooms[floors[0].getRoomY()][floors[0].getRoomX()]);

		game.colisions(enemy, obstacles, rooms[floors[0].getRoomY()][floors[0].getRoomX()]);

		player.applyMovement(game.getDeltaTime());
		
		enemy.applyMovement(game.getDeltaTime());

		floors[0].changeRoom(player);

		Display::room(sf::Vector2f(0.0f, 0.0f), roomRecTex, rooms[floors[0].getRoomY()][floors[0].getRoomX()], obstacles, rocksTex, openDoor, closedDoorTex, game.window);

		if (enemy.getExsits() == true)
		{
			enemyRec.setPosition(enemy.getPosition());
			enemyRec.setSize(enemy.getSize());

			if (enemy.getFacing() == 1)
			{
				enemyRec.setTexture(&enemy1);
			}
			else if (enemy.getFacing() == 3)
			{
				enemyRec.setTexture(&enemy3);
			}
			else if (enemy.getFacing() == 2)
			{
				enemyRec.setTexture(&enemy2);
			}
			else if (enemy.getFacing() == 4)
			{
				enemyRec.setTexture(&enemy4);
			}

			game.window->draw(enemyRec);
		}

		if (player.getFacing() == 1)
		{
			playerRec.setPosition(player.getPosition());
			playerRec.setSize(player.getSize());
			playerRec.setTexture(&player1);
		}
		else if (player.getFacing() == 3)
		{
			playerRec.setPosition(player.getPosition());
			playerRec.setSize(player.getSize());
			playerRec.setTexture(&player3);
		}
		if (player.getFacing() == 2)
		{
			playerRec.setPosition(player.getPosition());
			playerRec.setSize(player.getSize());
			playerRec.setTexture(&player2);
		}
		else if (player.getFacing() == 4)
		{
			playerRec.setPosition(player.getPosition());
			playerRec.setSize(player.getSize());
			playerRec.setTexture(&player4);
		}

		game.window->draw(playerRec);

		game.render();
	}

	return 0;
}