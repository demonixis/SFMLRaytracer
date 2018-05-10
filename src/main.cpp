#include <iostream>
#include <SFML/Graphics.hpp>
#include <glm.hpp>
#include <vector>
#include "utils/random.hpp"
#include "utils/mathf.hpp"
#include "materials/dieletric-material.hpp"
#include "materials/lambert-material.hpp"
#include "materials/metal-material.hpp"
#include "camera.hpp"
#include "primitives/sphere.hpp"
#include "hitable-list.hpp"
#include "raytracer.hpp"

static void MakeSphereScene(std::vector<Hitable*> &scene, int sceneComplexity)
{
	auto *m = new LambertMaterial(glm::vec3(0));
	auto *s = new Sphere(glm::vec3(0), 1.0f, m);


	scene.push_back(new Sphere(glm::vec3(0, -1000, 0), 1000.0f, new LambertMaterial(glm::vec3(0.6f, 0.2f, 0.7f))));

	auto temp = glm::vec3(4, 0.2f, 0);

	for (int a = -sceneComplexity; a < sceneComplexity; a++)
	{
		for (int b = -sceneComplexity; b < sceneComplexity; b++)
		{
			float chooseMat = Random::Value();
			auto center = glm::vec3(a + 0.9f + Random::Value(), 0.2f, b + 0.9f + Random::Value());

			if (Mathf::Length(center - temp) > 0.9f)
			{
				if (chooseMat < 0.8f)
					scene.push_back(new Sphere(center, 0.2f, new LambertMaterial(Random::GetFloat3Pow())));
				else if (chooseMat < 0.95f)
					scene.push_back(new Sphere(center, 0.2f, new MetalMaterial(glm::vec3(0.5f * (1 + Random::Value()), 0.5f * (1 + Random::Value()), 0.5f * (1 + Random::Value())), 0.5f * Random::Value())));
				else
					scene.push_back(new Sphere(center, 0.2f, new MetalMaterial(glm::vec3(0.5f * (1 + Random::Value()), 0.5f * (1 + Random::Value()), 0.5f * (1 + Random::Value())), 0.5f * Random::Value())));
			}
		}
	}

	scene.push_back(new Sphere(glm::vec3(0, 1, -2), 1, new LambertMaterial(glm::vec3(0.5f, 0.4f, 0.5f))));
	scene.push_back(new Sphere(glm::vec3(-4, 1, 0), 1, new LambertMaterial(glm::vec3(0.5f, 0.4f, 0.5f))));
	scene.push_back(new Sphere(glm::vec3(4, 1, 0), 1,  new MetalMaterial(glm::vec3(0.7f, 0.6f, 0.5f), 0.0f)));
}

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