#include <iostream>
#include <SFML/Graphics.hpp>
#include <glm.hpp>
#include <vector>
#include "camera.hpp"
#include "primitives/sphere.hpp"
#include "hitable-list.hpp"
#include "raytracer.hpp"

int main(int argc, char* argv[])
{
	const int width = 800;
	const int height = 600;
	sf::RenderWindow window(sf::VideoMode(width, height), "SFML Raytracer");

	auto world = std::vector<Hitable*>();

	Raytracer raytracer(width, height, 0.5f);
	Camera camera;
	HitableList list(world);

	raytracer.StartThreading(camera, list);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.key.code == sf::Keyboard::Escape)
				window.close();
		}

		window.clear(sf::Color::Black);

		raytracer.Present(window);

		window.display();
	}

	return 0;
}