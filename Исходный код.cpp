#include <SFML/Graphics.hpp>

sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
sf::CircleShape square(70, 4);
sf::RectangleShape rectangle(sf::Vector2f(150, 5));
sf::Image image;
sf::Texture texture;
sf::Sprite sprite;

int main(){
	window.create(sf::VideoMode(640, 480), "Test");

	square.setFillColor(sf::Color::Green);
	square.setPosition(200, 200);
	square.rotate(45);

	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setPosition(100, 100);

	image.loadFromFile("image.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(50, 50);

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Red);
		window.draw(square);
		window.draw(rectangle);
		window.draw(sprite);

		window.display();
	}


}