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
	const int width = 1024;
	const int height = 600;
	bool realtime = true;
	int samples = 1;

	sf::RenderWindow window(sf::VideoMode(width, height), "SFML Raytracer");

	Raytracer raytracer(width, height, 1.0f);
	raytracer.SetStep(samples);

	Camera camera(glm::vec3(0, 0.5f, 3), glm::vec3(0), glm::vec3(0, 1, 0), 90.0f, float(width) / float(height));

	auto scene = std::vector<Hitable*>();
	SceneFactory::CreateSphereScene(scene, camera, 1);
	HitableList world(scene);

	if (realtime)
		raytracer.Start(camera, world);
	else
		raytracer.Render(camera, world);

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

			if (event.type == sf::Event::KeyPressed)
			{
				float moveSpeed = 0.25f;

				if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Z)
					camera.Translate(0, 0, -moveSpeed);
				else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
					camera.Translate(0, 0, moveSpeed);
				else if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Q)
					camera.Translate(-moveSpeed, 0, 0);
				else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
					camera.Translate(moveSpeed, 0, 0);

				if (event.key.code == sf::Keyboard::PageUp)
					raytracer.SetStep(raytracer.Step() + 1);

				if (event.key.code == sf::Keyboard::PageDown)
					raytracer.SetStep(raytracer.Step() - 1);

				// Toggle Online/Offline
				if (!realtime && event.key.code == sf::Keyboard::F11)
				{
					if (realtime)
						raytracer.Stop();
					else
						raytracer.Start(camera, world);

					realtime = !realtime;
				}

				// Offline
				if (!realtime && event.key.code == sf::Keyboard::F12)
					raytracer.Render(camera, world);
			}
		}

		window.clear(sf::Color::Black);
		raytracer.Present(window);
		window.display();
	}

	return 0;
}