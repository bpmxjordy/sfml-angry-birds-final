#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <cmath>
#include <queue>
#include <list>

#include "GameObject.h"
#include "Player.h"
#include "Slingshot.h"
#include "Pig.h"
#include "Brick.h"
using namespace std;
#define NULL nullptr  // since C++11


sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

float mouseSlingAngle = 0;
float playerSlingAngle = 0;
bool shot = false;
bool shotClick = false;

void deleteAnimal(GameObject* a)
{
	delete a;
}

int lab1(int A[], int n)
{
	return 0;
}

void update()
{

}


bool AABBIntersect(const sf::FloatRect& a, const sf::FloatRect& b)
{
	return a.left + a.width > b.left && a.left < b.left + b.width &&
		a.top + a.height > b.top && a.top < b.top + b.height;
}


bool checkCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2) {
	sf::FloatRect bounds1 = sprite1.getGlobalBounds();
	sf::FloatRect bounds2 = sprite2.getGlobalBounds();

	return bounds1.intersects(bounds2);
}



int main()
{
	// Create the window
	sf::RenderWindow window(sf::VideoMode(1203, 600), "Angry Birds");

	// Load the background texture
	sf::Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("background2.png"))
	{
		std::cout << "Error loading background image" << std::endl;
		return -1;
	}

	// Create the background sprite
	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(0.6, 0.6);
	backgroundSprite.setPosition(0, 0);

	// Load the bird sprite
	Player* bird = new Player();
	sf::Texture birdTex;
	birdTex.loadFromFile("bird.png");
	bird->setTexture(&birdTex);
	bird->setPos(300, 400);
	bird->setRotation(0);
	bird->setScale(sf::Vector2f(0.06, 0.06));
	bird->setOrigin(sf::Vector2f(500, 500));

	// Load the bird sprite
	Player* elephant = new Player();
	sf::Texture elephantTex;
	elephantTex.loadFromFile("elephant.png");
	elephant->setTexture(&elephantTex);
	elephant->setPos(150, 570);
	elephant->setRotation(0);
	elephant->setScale(sf::Vector2f(0.25, 0.25));
	elephant->setOrigin(sf::Vector2f(32, 32));

	Player* monkey = new Player();
	sf::Texture monkeyTex;
	monkeyTex.loadFromFile("monkey.png");
	monkey->setTexture(&monkeyTex);
	monkey->setPos(100, 570);
	monkey->setRotation(0);
	monkey->setScale(sf::Vector2f(0.25, 0.25));
	monkey->setOrigin(sf::Vector2f(32, 32));

	// Load the pig sprites
	Pig* pig1 = new Pig();
	sf::Texture pigTex;
	pigTex.loadFromFile("crocodile.png");
	pig1->setTexture(&pigTex);
	pig1->setRotation(0);
	pig1->setScale(sf::Vector2f(0.25, 0.25));
	pig1->setOrigin(sf::Vector2f(135, 62));
	pig1->setPos(790, 465);

	Pig* pig2 = new Pig();
	pig2->setTexture(&pigTex);
	pig2->setRotation(0);
	pig2->setScale(sf::Vector2f(0.25, 0.25));
	pig2->setOrigin(sf::Vector2f(135, 62));
	pig2->setPos(840, 465);

	Pig* pig3 = new Pig();
	pig3->setTexture(&pigTex);
	pig3->setRotation(0);
	pig3->setScale(sf::Vector2f(0.25, 0.25));
	pig3->setOrigin(sf::Vector2f(135, 62));
	pig3->setPos(840, 265);

	sf::Texture birdTexture;
	if (!birdTexture.loadFromFile("bird.png"))
	{
		return -1;
	}
	bird->getSprite().setOrigin((bird->getSprite().getLocalBounds().width) / 2, (bird->getSprite().getLocalBounds().height) / 2);
	bird->setPos(100, 100);

	// Load the slingshot sprite
	Slingshot* slingshot = new Slingshot();
	sf::Texture slingTex;
	slingTex.loadFromFile("slingshot.png");
	slingshot->setTexture(&slingTex);
	slingshot->setRotation(0);
	slingshot->setScale(sf::Vector2f(0.5, 0.5));
	slingshot->setOrigin(sf::Vector2f(135, 62));
	slingshot->setPos(300, 470);

	//// Load the brick sprites
	Brick* brick1 = new Brick();
	sf::Texture brickTex;
	brickTex.loadFromFile("brick.png");
	brick1->setTexture(&brickTex);
	brick1->setRotation(0);
	brick1->setScale(sf::Vector2f(3, 3));
	brick1->setOrigin(sf::Vector2f(135, 62));
	brick1->setPos(1300, 720);

	Brick* brick2 = new Brick();
	brick2->setTexture(&brickTex);
	brick2->setRotation(0);
	brick2->setScale(sf::Vector2f(3, 3));
	brick2->setOrigin(sf::Vector2f(135, 62));
	brick2->setPos(1350, 720);

	Brick* brick3 = new Brick();
	brick3->setTexture(&brickTex);
	brick3->setRotation(0);
	brick3->setScale(sf::Vector2f(3, 3));
	brick3->setOrigin(sf::Vector2f(135, 62));
	brick3->setPos(1350, 670);

	Brick* brick4 = new Brick();
	brick4->setTexture(&brickTex);
	brick4->setRotation(0);
	brick4->setScale(sf::Vector2f(3, 3));
	brick4->setOrigin(sf::Vector2f(135, 62));
	brick4->setPos(1300, 670);

	Brick* brick5 = new Brick();
	brick5->setTexture(&brickTex);
	brick5->setRotation(0);
	brick5->setScale(sf::Vector2f(3, 3));
	brick5->setOrigin(sf::Vector2f(135, 62));
	brick5->setPos(1300, 620);

	Brick* brick6 = new Brick();
	brick6->setTexture(&brickTex);
	brick6->setRotation(0);
	brick6->setScale(sf::Vector2f(3, 3));
	brick6->setOrigin(sf::Vector2f(135, 62));
	brick6->setPos(1350, 620);

	Brick* brick7 = new Brick();
	brick7->setTexture(&brickTex);
	brick7->setRotation(0);
	brick7->setScale(sf::Vector2f(3, 3));
	brick7->setOrigin(sf::Vector2f(135, 62));
	brick7->setPos(1300, 570);

	Brick* brick8 = new Brick();
	brick8->setTexture(&brickTex);
	brick8->setRotation(0);
	brick8->setScale(sf::Vector2f(3, 3));
	brick8->setOrigin(sf::Vector2f(135, 62));
	brick8->setPos(1350, 570);

	Brick* brick9 = new Brick();
	brick9->setTexture(&brickTex);
	brick9->setRotation(0);
	brick9->setScale(sf::Vector2f(3, 3));
	brick9->setOrigin(sf::Vector2f(135, 62));
	brick9->setPos(1100, 720);

	Brick* brick10 = new Brick();
	brick10->setTexture(&brickTex);
	brick10->setRotation(0);
	brick10->setScale(sf::Vector2f(3, 3));
	brick10->setOrigin(sf::Vector2f(135, 62));
	brick10->setPos(1150, 720);

	Brick* brick11 = new Brick();
	brick11->setTexture(&brickTex);
	brick11->setRotation(0);
	brick11->setScale(sf::Vector2f(3, 3));
	brick11->setOrigin(sf::Vector2f(135, 62));
	brick11->setPos(1100, 670);

	Brick* brick12 = new Brick();
	brick8->setTexture(&brickTex);
	brick8->setRotation(0);
	brick8->setScale(sf::Vector2f(3, 3));
	brick8->setOrigin(sf::Vector2f(135, 62));
	brick8->setPos(1150, 670);

	Brick* brick13 = new Brick();
	brick13->setTexture(&brickTex);
	brick13->setRotation(0);
	brick13->setScale(sf::Vector2f(3, 3));
	brick13->setOrigin(sf::Vector2f(135, 62));
	brick13->setPos(1350, 570);

	Brick* brick14 = new Brick();
	brick14->setTexture(&brickTex);
	brick14->setRotation(0);
	brick14->setScale(sf::Vector2f(3, 3));
	brick14->setOrigin(sf::Vector2f(135, 62));
	brick14->setPos(1350, 520);

	Brick* brick15 = new Brick();
	brick15->setTexture(&brickTex);
	brick15->setRotation(0);
	brick15->setScale(sf::Vector2f(3, 3));
	brick15->setOrigin(sf::Vector2f(135, 62));
	brick15->setPos(1300, 520);

	Brick* brick16 = new Brick();
	brick16->setTexture(&brickTex);
	brick16->setRotation(0);
	brick16->setScale(sf::Vector2f(3, 3));
	brick16->setOrigin(sf::Vector2f(135, 62));
	brick16->setPos(1250, 470);

	Brick* brick17 = new Brick();
	brick17->setTexture(&brickTex);
	brick17->setRotation(0);
	brick17->setScale(sf::Vector2f(3, 3));
	brick17->setOrigin(sf::Vector2f(135, 62));
	brick17->setPos(1300, 470);

	Brick* brick18 = new Brick();
	brick18->setTexture(&brickTex);
	brick18->setRotation(0);
	brick18->setScale(sf::Vector2f(3, 3));
	brick18->setOrigin(sf::Vector2f(135, 62));
	brick18->setPos(1150, 520);

	Brick* brick19 = new Brick();
	brick19->setTexture(&brickTex);
	brick19->setRotation(0);
	brick19->setScale(sf::Vector2f(3, 3));
	brick19->setOrigin(sf::Vector2f(135, 62));
	brick19->setPos(1100, 520);

	Brick* brick20 = new Brick();
	brick20->setTexture(&brickTex);
	brick20->setRotation(0);
	brick20->setScale(sf::Vector2f(3, 3));
	brick20->setOrigin(sf::Vector2f(135, 62));
	brick20->setPos(1150, 470);

	Brick* brick21 = new Brick();
	brick21->setTexture(&brickTex);
	brick21->setRotation(0);
	brick21->setScale(sf::Vector2f(3, 3));
	brick21->setOrigin(sf::Vector2f(135, 62));
	brick21->setPos(1100, 570);

	Brick* brick22 = new Brick();
	brick22->setTexture(&brickTex);
	brick22->setRotation(0);
	brick22->setScale(sf::Vector2f(3, 3));
	brick22->setOrigin(sf::Vector2f(135, 62));
	brick22->setPos(1200, 470);

	Brick* brick23 = new Brick();
	brick23->setTexture(&brickTex);
	brick23->setRotation(0);
	brick23->setScale(sf::Vector2f(3, 3));
	brick23->setOrigin(sf::Vector2f(135, 62));
	brick23->setPos(1200, 470);

	Brick* brick24 = new Brick();
	brick24->setTexture(&brickTex);
	brick24->setRotation(0);
	brick24->setScale(sf::Vector2f(3, 3));
	brick24->setOrigin(sf::Vector2f(135, 62));
	brick24->setPos(1100, 620);

	Brick* brick25 = new Brick();
	brick25->setTexture(&brickTex);
	brick25->setRotation(0);
	brick25->setScale(sf::Vector2f(3, 3));
	brick25->setOrigin(sf::Vector2f(135, 62));
	brick25->setPos(1200, 720);

	Brick* brick26 = new Brick();
	brick11->setTexture(&brickTex);
	brick11->setRotation(0);
	brick11->setScale(sf::Vector2f(3, 3));
	brick11->setOrigin(sf::Vector2f(135, 62));
	brick11->setPos(1200, 670);

	Brick* brick27 = new Brick();
	brick27->setTexture(&brickTex);
	brick27->setRotation(0);
	brick27->setScale(sf::Vector2f(3, 3));
	brick27->setOrigin(sf::Vector2f(135, 62));
	brick27->setPos(1100, 670);

	std::queue<Player*> players;

	players.push(bird);
	players.push(elephant);
	players.push(monkey);
	

	
	
	std::list<Brick*> bricks = { brick1, brick2, brick3, brick4, brick5, brick6, brick7, brick8, brick9, brick10,
							  brick11, brick12, brick13, brick14, brick15, brick16, brick17, brick18, brick19, brick20,
							  brick21, brick22, brick23, brick24, brick25, brick26, brick27 };


	std::list<Pig*> pigs = { pig1, pig2, pig3 };


	// Variables to store the position of the bird in the slingshot
	float birdX = bird->getPos().x;
	float birdY = bird->getPos().y;
	float slingshotX = slingshot->getPos().x;
	float slingshotY = slingshot->getPos().y;

	// Create the power indicator circle
	sf::CircleShape powerIndicator;
	powerIndicator.setFillColor(sf::Color(0, 255, 0, 25)); // Green color with 10% opacity
	powerIndicator.setOrigin(0, 0);
	powerIndicator.setPosition(slingshotX, slingshotY);

	// Variables to store the velocity and angle of the bird
	float velocity = 0;
	sf::Vector2f aimDir;

	// Variables to store the initial position and velocity of the bird after being shot
	sf::Vector2f initPos;
	sf::Vector2f initVel;
	const float maxPowerRadius = 100.0;

	// Variable to store the state of the game
	bool fired = false;

	// Define the gravity constant
	const float gravity = 9.8f;

	// Define the time interval between updates (in seconds)
	const float timeInterval = 0.01f;

	// Variables for parabolic motion
	float initialVelocity = 0.0;
	float angle = 0.0;
	float velocityX = 0.0;
	float velocityY = 0.0;
	sf::Clock clock;

	//arrays for the rope
	sf::VertexArray rope1(sf::Lines, 2);
	sf::VertexArray rope2(sf::Lines, 2);

	Player* currentPlayer = new Player();

	currentPlayer = players.front();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::MouseMoved)
			{
				if (!fired)
				{
					// Move the bird along with the mouse while the mouse button is being pressed
					birdX = event.mouseMove.x;
					birdY = event.mouseMove.y;
					currentPlayer->setPos(birdX, birdY);


					// Calculate the distance between the bird and the slingshot
					float dx = slingshotX - event.mouseMove.x;
					float dy = slingshotY - event.mouseMove.y;
					float distance = std::sqrt(dx * dx + dy * dy);

					// Limit the distance to the maximum power radius
					if (distance > maxPowerRadius)
					{
						distance = maxPowerRadius;
					}

					// Calculate the angle
					float angle = atan2(dy, dx);

					// Update the bird's position based on the distance and angle
					birdX = (slingshotX - distance * cos(angle));
					birdY = (slingshotY - distance * sin(angle));
					currentPlayer->setPos(birdX, birdY);

					// Set the radius of the power indicator circle based on the distance
					powerIndicator.setRadius(distance);

					// Set the circle's origin to its center
					powerIndicator.setOrigin(distance, distance);

					// Change the circle's color based on the power
					float powerRatio = distance / maxPowerRadius;
					powerIndicator.setFillColor(sf::Color(255 * powerRatio, 255 * (1 - powerRatio), 0, 75));

					// Update the vertices of the ropes based on the bird's position
					rope1[0].position = sf::Vector2f(slingshot->getPos().x, slingshot->getPos().y);
					rope1[1].position = sf::Vector2f(currentPlayer->getPos().x, currentPlayer->getPos().y);
					rope2[0].position = sf::Vector2f(slingshot->getPos().x + 40, slingshot->getPos().y);
					rope2[1].position = sf::Vector2f(currentPlayer->getPos().x, currentPlayer->getPos().y);

					// Set rope colors
					rope1[0].color = sf::Color::Black;
					rope1[1].color = sf::Color::Black;
					rope2[0].color = sf::Color::Black;
					rope2[1].color = sf::Color::Black;


				}
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				// Calculate the distance between the bird and the slingshot
				float dx = slingshotX - birdX;
				float dy = slingshotY - birdY;
				float distance = std::sqrt(dx * dx + dy * dy);

				// Calculate the angle
				angle = atan2(dy, dx);

				// Calculate the initial velocity based on the distance
				initialVelocity = distance * 0.035;

				// Calculate the x and y components of the initial velocity
				velocityX = initialVelocity * cos(angle);
				velocityY = initialVelocity * sin(angle);

				// Set the fired flag to true
				fired = true;

				// Restart the clock
				clock.restart();
			}

		}

		if (fired)
		{
			float deltaTime = clock.getElapsedTime().asSeconds();

			// Update the bird's position based on the parabolic trajectory
			birdX = birdX + velocityX * deltaTime;
			birdY = birdY + velocityY * deltaTime + 0.5 * gravity * deltaTime * deltaTime;
			currentPlayer->setPos(birdX, birdY);

			for (auto it = bricks.begin(); it != bricks.end(); ) {
				Brick* brick = *it;
				if (checkCollision(currentPlayer->getSprite(), brick->getSprite())) {
					// Collision detected, delete the brick and remove it from the vector
					brick->setOpacity(0);
					it = bricks.erase(it);
				}
				else {
					++it;
				}
			}

			for (auto x = pigs.begin(); x != pigs.end(); ) {
				Pig* pig = *x;
				if (checkCollision(currentPlayer->getSprite(), pig->getSprite())) {
					// Collision detected, delete the brick and remove it from the vector
					pig->setOpacity(0);
					x = pigs.erase(x);
				}
				else {
					++x;
				}
			}



			if (birdX < 0 || birdX > window.getSize().x || birdY < 0 || birdY > window.getSize().y)
			{
				fired = false;
				if (players.size() == 1)
				{
					players.push(bird);
					players.push(elephant);
					players.push(monkey);
				}
				else {
					players.pop();
					currentPlayer = players.front();
					currentPlayer->setPos(slingshotX, slingshotY);
					birdX = slingshotX;
					birdY = slingshotY;
				}
				
			}
		}

		// Clear the window
		window.clear();

		// Draw the background
		window.draw(backgroundSprite);
		

		// Draw the game objects
		window.draw(bird->getSprite());
		window.draw(elephant->getSprite());
		window.draw(monkey->getSprite());
		window.draw(slingshot->getSprite());

		for (Pig* pig : pigs) {
			window.draw(pig->getSprite());
		}

		for (Brick* brick : bricks) {
			window.draw(brick->getSprite());
		}
		window.draw(powerIndicator);
		window.draw(rope1);
		window.draw(rope2);

		// Display the window
		window.display();
	}

	return 0;
}
