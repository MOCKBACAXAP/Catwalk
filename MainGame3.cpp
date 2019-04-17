#include <SFML/Graphics.hpp>
#include "map.h"
sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
sf::CircleShape square(70, 4);
//sf::RectangleShape rectangle(sf::Vector2f(32, 32));
sf::Image image;
sf::Texture texture;
sf::Sprite sprite;
int i, j;


int main(){
	window.create(sf::VideoMode(640, 480), "Test");

	sf::Image map_image;
	map_image.loadFromFile("map.png");
	sf::Texture map;
	map.loadFromFile(map_image);
	sf::Sprite s_map;
	s_map.setTexture(map);

	//square.setFillColor(sf::Color::Green);
	//square.setPosition(200, 200);
	//square.rotate(45);

	//rectangle.setFillColor(sf::Color::Blue);
	//rectangle.setPosition(100, 100);

	
	//sf::RectangleShape rectangle;
	sf::RectangleShape rectangle(sf::Vector2f(32, 32));

	//int ground = 400;
	//const int H = 12;
	//const int W = 40;
	//sf::String TileMap[H] = {

	//"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	//"B                            B         B",
	//"B                            B         B",
	//"B                            B         B",
	//"B                            B         B",
	//"B                            B         B",
	//"B                            B         B",
	//"B            000         BBBBB         B",
	//"B                            B         B",
	//"BBBBB                        B         B",
	//"B                 BB                   B",
	//"B                 BB                   B",
	//"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",

	//};


	image.loadFromFile("image.png");
	float currentFrame = 0;

	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(100, 300);
	sprite.setTextureRect(sf::IntRect(0, 0, 54, 70));

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			sprite.move(-0.1, 0);
			currentFrame += 0.005;
			if (currentFrame > 4) currentFrame -= 4;
			sprite.setTextureRect(sf::IntRect(54 * int(currentFrame)+54, 0, -54, 70));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			sprite.move(0.1, 0);
			currentFrame += 0.005;
			if (currentFrame > 4) currentFrame -= 4;
			sprite.setTextureRect(sf::IntRect(54 * int(currentFrame), 0, 54, 70));

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			sprite.move(0, -0.1);
		}
		window.clear(sf::Color::Red);

		for (int i = 0; i < HEIGHT_MAP; i++);  //12
		{
			for (int j = 0; j < WIDTH_MAP; j++); //40
			{
				if (TileMap[i][j] == 's') rectangle.setFillColor(sf::Color::Black);
				if (TileMap[i][j] == '0') rectangle.setFillColor(sf::Color::Green);
				if (TileMap[i][j] == ' ') continue;

				//rectangle.setPosition(j * 32, i * 32);
				//window.draw(rectangle);

				s_map.setPosition(j * 32, i * 32);
				window.draw(s_map);

			}
			//continue;
		}

		//window.draw(square);
		//window.draw(rectangle);
	    window.draw(sprite);
		window.display();
	}


}