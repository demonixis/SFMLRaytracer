#ifndef SCENE_FACTORY_HPP
#define SCENE_FACTORY_HPP

#include <glm.hpp>
#include <vector>
#include <memory>
#include "utils/random.hpp"
#include "utils/mathf.hpp"
#include "materials/dieletric-material.hpp"
#include "materials/lambert-material.hpp"
#include "materials/metal-material.hpp"
#include "camera.hpp"
#include "primitives/sphere.hpp"
#include "hitable-list.hpp"
#include "textures/checker-texture.hpp"
#include "textures/image-texture.hpp"
#include "textures/noise-texture.hpp"

class SceneFactory
{
public:
	static void CreateSphereScene(std::vector<Hitable*> &scene, Camera &camera, const int sceneComplexity)
	{
		scene.push_back(new Sphere(glm::vec3(0, -1000, 0), 1000.0f, new LambertMaterial(glm::vec3(0.2f, 0.2f, 0.4f))));

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

		auto noiseTexShared = std::make_shared<Texture>(NoiseTexture());
		auto checkTexShared = std::make_shared<CheckerTexture>(CheckerTexture(glm::vec3(0.2f), glm::vec3(0.9f)));

		scene.push_back(new Sphere(glm::vec3(0, 1, -2), 1, new LambertMaterial(checkTexShared)));
		scene.push_back(new Sphere(glm::vec3(-4, 1, 0), 1, new LambertMaterial(glm::vec3(0.5f, 0.4f, 0.5f))));
		scene.push_back(new Sphere(glm::vec3(4, 1, 0), 1, new MetalMaterial(glm::vec3(0.7f, 0.6f, 0.5f), 0.0f)));

		camera.SetPosition(0.0f, 0.5f, 5.0f);
	}
};

#endif