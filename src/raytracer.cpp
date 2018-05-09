#include "raytracer.hpp"

Raytracer::Raytracer(const int &width, const int &height, const float &scale)
{
	m_RenderWidth = int(width * scale);
	m_RenderHeight = int(height * scale);
	m_ColorBuffer = new sf::Uint8[m_RenderWidth * m_RenderHeight * 4];
	m_Backbuffer = new sf::Texture();
	m_BackbufferSprite = new sf::Sprite();
	m_BackbufferSprite->setTexture(*m_Backbuffer);
	m_Stopwatch = new sf::Clock();
}

Raytracer::~Raytracer()
{
	delete m_ColorBuffer;
	delete m_Backbuffer;
	delete m_BackbufferSprite;
	delete m_Stopwatch;
}

glm::vec3 Raytracer::GetColor(const Ray &ray, Hitable &world)
{
	HitRecord record;

	bool hit = world.Hit(ray, 0.001f, FLT_MAX, record);
	bool wasInLoop = hit;
	glm::vec3 color(0);
	glm::vec3 attenuation(0);
	Ray scattered;
	int depth = 0;
	int maxDepth = 50;

	while (hit && depth < maxDepth)
	{
		color += record.TargetMaterial->Emitted(record);

		hit = record.TargetMaterial->Scatter(ray, record, attenuation, scattered);

		if (hit)
		{
			if (depth == 0)
				color += attenuation;
			else
				color *= attenuation;

			hit = world.Hit(scattered, 0.001f, FLT_MAX, record);

			depth++;
		}
	}

	if (wasInLoop)
		return color;

	// Background color.
	auto unitDirection = Mathf::UnitVector(ray.GetDirection());
	float t = 0.5f * (unitDirection.y + 1.0f);
	return (1.0f - t) * glm::vec3(1) + t * glm::vec3(0.5f, 0.7f, 1.0f);
}

void Raytracer::Render(Camera &camera, Hitable &world)
{
	m_Stopwatch->restart();

	for (int j = 0; j < m_RenderHeight; j++)
		for (int i = 0; i < m_RenderWidth; i++)
			PixelShader(i, j, camera, world);

	m_Backbuffer->update(m_ColorBuffer);
	m_LastFrameTime = m_Stopwatch->getElapsedTime().asMilliseconds();
}

void Raytracer::PixelShader(const int &i, const int &j, Camera &camera, Hitable &world)
{
	glm::vec3 color(0);

	Ray ray;

	for (int s = 0; s < m_Step; s++)
	{
		float u = float((i + Random::Value()) / m_RenderWidth);
		float v = float((j + Random::Value()) / m_RenderHeight);
		camera.GetRay(ray, u, v);
		color += GetColor(ray, world);
	}

	color /= (float)m_Step;
	color = glm::sqrt(color);

	m_ColorBuffer[i + j * m_RenderWidth] = sf::Uint8(color.x * 255);
	m_ColorBuffer[i + j * m_RenderWidth + 1] = sf::Uint8(color.y * 255);
	m_ColorBuffer[i + j * m_RenderWidth + 2] = sf::Uint8(color.z * 255);
	m_ColorBuffer[i + j * m_RenderWidth + 4] = 255;
}

void Raytracer::Present(sf::RenderWindow &window)
{
	window.draw(*m_BackbufferSprite);
}
