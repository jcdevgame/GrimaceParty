#include <SFML/Graphics.hpp>

float changeX;
float changeY;
int ShakesCounterNum;

bool holdingCup = false;
bool drankCup = false;

int main()
{	
	//Defining the sprites
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "GRIMACE PARTY (V 0.3)");

	window.setFramerateLimit(30);
	window.clear(sf::Color::White);
	sf::Texture grimaceCharLeft;;
	sf::Texture grimaceCharRight;;
	sf::Texture grimaceCharRightShake;;
	sf::Texture grimaceCharLeftShake;;
	sf::Texture grimaceShake;;
	grimaceShake.loadFromFile("Images/GrimaceShake2.png");
	grimaceCharRight.loadFromFile("Images/GrimaceChar/RightFacingGrimace.png");
	grimaceCharLeft.loadFromFile("Images/GrimaceChar/LeftFacingGrimace.png");
	grimaceCharLeftShake.loadFromFile("Images/GrimaceChar/LeftFacingGrimaceWithShake.png");
	grimaceCharRightShake.loadFromFile("Images/GrimaceChar/RightFacingGrimaceWithShake.png");
	sf::Sprite shakeGrimace(grimaceShake);
	sf::Sprite grimaceCharacter(grimaceCharRight);
		

	//Defining the text
	sf::Font font;
	sf::Text Guide;
	sf::Text ShakesDrank;

	font.loadFromFile("C:/GrimaceParty/Fonts/Roboto-Regular.ttf");
	Guide.setFont(font);
	Guide.setString("E to grab a shake");
	Guide.setCharacterSize(75);
	Guide.setFillColor(sf::Color::White);

	ShakesDrank.setFont(font);
	ShakesDrank.setString("");
	ShakesDrank.setCharacterSize(75);
	ShakesDrank.setFillColor(sf::Color::White);

	//Setting the locations
	shakeGrimace.setOrigin(-500, -500);
	grimaceCharacter.setOrigin(10, -700);
	Guide.setOrigin(-600, 0);
	ShakesDrank.setOrigin(-600, -100);
	


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//Keyboard functions
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
				shakeGrimace.setPosition(-200, 0);
				holdingCup = true;
			}
			
			//Movement Functions
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				changeX = -5;
				grimaceCharacter.setTexture(grimaceCharLeft);
				grimaceCharacter.move(changeX, changeY);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				changeX = 5;
				grimaceCharacter.setTexture(grimaceCharRight);
				grimaceCharacter.move(changeX, changeY);
			}
			
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) and holdingCup == true) {
				changeX = -5;
				grimaceCharacter.setTexture(grimaceCharLeftShake);
				grimaceCharacter.move(changeX, changeY);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) and holdingCup == true) {
				changeX = 5;
				grimaceCharacter.setTexture(grimaceCharRightShake);
				grimaceCharacter.move(changeX, changeY);
			}
			
			//Other Functions
			if (holdingCup == true) {
				Guide.setString("F to drink Shake");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
					drankCup = true;
					holdingCup = false;
					Guide.setString("E to grab a shake");
				}
			}
			
		}
		
		//Drawing the different objects
		window.draw(shakeGrimace);
		window.draw(grimaceCharacter);
		window.draw(Guide);
		window.draw(ShakesDrank);

		window.display();
		window.clear();
	}
	return 0;
}


