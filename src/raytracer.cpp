#include "raytracer.hpp"

Raytracer::Raytracer()
{
}

Raytracer::Raytracer(const int width, const int height, const float scale)
{
	m_RenderWidth = int(width * scale);
	m_RenderHeight = int(height * scale);
	m_ColorBuffer = new sf::Uint8[m_RenderWidth * m_RenderHeight * 4];
	m_Backbuffer.create(m_RenderWidth, m_RenderHeight);
	m_Backbuffer.setRepeated(false);
	m_BackbufferSprite.setTexture(m_Backbuffer);
	m_BackbufferSprite.setScale(width / m_RenderWidth, height / m_RenderHeight);
	m_Step = 1;
}

Raytracer::~Raytracer()
{
	Stop();
	delete m_ColorBuffer;
}

void Raytracer::Start(Camera &camera, Hitable &world)
{
	Stop();

	m_RenderThread = std::thread([&] {
		m_ThreadIsRunning = true;

		while (m_ThreadIsRunning)
			Render(camera, world);
	});
}

void Raytracer::Stop()
{
	if (!m_ThreadIsRunning)
		return;

	m_ThreadIsRunning = false;

	if (m_RenderThread.joinable())
		m_RenderThread.join();
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
	auto t = 0.5f * (unitDirection.y + 1.0f);
	return (1.0f - t) * glm::vec3(1) + t * glm::vec3(0.5f, 0.7f, 1.0f);
}

void Raytracer::Render(Camera &camera, Hitable &world)
{
	m_Stopwatch.restart();

	for (int j = 0; j < m_RenderHeight; j++)
		for (int i = 0; i < m_RenderWidth; i++)
			PixelShader(i, j, camera, world);

	m_Backbuffer.update(m_ColorBuffer);
	m_LastFrameTime = m_Stopwatch.getElapsedTime().asMilliseconds();
}

void Raytracer::PixelShader(const int i, const int j, Camera &camera, Hitable &world)
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

	size_t pixelOffset = (j *m_RenderWidth + i) * 4;

	m_ColorBuffer[pixelOffset] = sf::Uint8(color.x * 255);
	m_ColorBuffer[pixelOffset + 1] = sf::Uint8(color.y * 255);
	m_ColorBuffer[pixelOffset + 2] = sf::Uint8(color.z * 255);
	m_ColorBuffer[pixelOffset + 3] = 255;
}

void Raytracer::Present(sf::RenderWindow &window)
{
	window.draw(m_BackbufferSprite);
}
