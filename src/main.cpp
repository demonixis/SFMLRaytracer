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
	bool realtime = true;
	int samples = 1;
	int maxThreads = 16;
	int sceneComplexity = 3;
	float scale = 1.0f;

	sf::RenderWindow window(sf::VideoMode(width, height), "SFML Raytracer");

	Raytracer raytracer(width, height, scale, maxThreads);
	raytracer.SetStep(samples);

	Camera camera(glm::vec3(1.5f, 0.45f, 2), glm::vec3(0), glm::vec3(0, 1, 0), 90.0f, float(width) / float(height));

	auto scene = std::vector<Hitable*>();
	SceneFactory::CreateSphereScene(scene, camera, sceneComplexity);
	HitableList world(scene);

	window.setKeyRepeatEnabled(false);

	if (realtime)
		raytracer.StartMT(camera, world);
	else
		raytracer.Render(camera, world);

	sf::Clock gameTime;
	sf::Event event;

	while (window.isOpen())
	{
		gameTime.restart();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
			{
				raytracer.Stop();
				window.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::PageUp)
					raytracer.SetStep(raytracer.Step() + 1);

				if (event.key.code == sf::Keyboard::PageDown)
					raytracer.SetStep(raytracer.Step() - 1);

				// Toggle Online/Offline
				if (event.key.code == sf::Keyboard::F11)
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

		float moveSpeed = 0.00025f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			camera.Translate(0, 0, -moveSpeed);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			camera.Translate(0, 0, moveSpeed);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			camera.Translate(-moveSpeed, 0, 0);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			camera.Translate(moveSpeed, 0, 0);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			camera.Translate(0, moveSpeed, 0);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			camera.Translate(0, -moveSpeed, 0);
		
		window.clear(sf::Color::Black);
		raytracer.PresentMT(window);
		window.display();
	}

	return 0;
}