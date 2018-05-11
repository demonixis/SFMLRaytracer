#include <iostream>
#include <SFML/Graphics.hpp>
#include <glm.hpp>
#include <vector>
#include "camera.hpp"
#include "hitable-list.hpp"
#include "raytracer.hpp"
#include "scene-factory.hpp"

int main(int argc, char* argv[])
{
	const int width = 640;
	const int height = 480;

	sf::RenderWindow window(sf::VideoMode(width, height), "SFML Raytracer");

	Raytracer raytracer(width, height, 1.0f);
	Camera camera(glm::vec3(0, 0.5f, 5), glm::vec3(0), glm::vec3(0, 1, 0), 75.0f, float(width) / float(height));

	auto scene = std::vector<Hitable*>();
	SceneFactory::CreateSphereScene(scene, camera, 1);
	HitableList world(scene);
	
	//raytracer.Render(camera, world);

	raytracer.Start(camera, world);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
			{
				raytracer.Stop();
				window.close();
			}
		}

		window.clear(sf::Color::Black);
		raytracer.Present(window);
		window.display();
	}

	return 0;
}