#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

#include <thread>
#include <SFML/Graphics.hpp>
#include <glm.hpp>
#include "hitable.hpp"
#include "hitable-list.hpp"
#include "camera.hpp"
#include "utils/random.hpp"
#include "utils/mathf.hpp"
#include "ray.hpp"

class Raytracer
{
private:
	sf::Sprite m_BackbufferSprite;
	sf::Texture m_Backbuffer;
	sf::Uint8 *m_ColorBuffer;
	sf::Clock m_Stopwatch;
	std::thread m_RenderThread;
	sf::Uint32 m_LastFrameTime;
	int m_RenderWidth;
	int m_RenderHeight;
	int m_Step;
	bool m_ThreadIsRunning;

public:
	sf::Uint32 LastFrameTime() { return m_LastFrameTime; }
	int RenderWidth() { return m_RenderWidth; }
	int RenderHeight() { return m_RenderHeight; }
	int Step() { return m_Step; }
	void SetStep(int value) { m_Step = value; }

public:
	Raytracer();
	Raytracer(const int &width, const int &height, const float &scale);
	~Raytracer();
	void Start(Camera &camera, Hitable &world);
	void Stop();
	void Render(Camera &camera, Hitable &world);
	void Present(sf::RenderWindow &window);

private:
	glm::vec3 GetColor(const Ray &ray, Hitable &world);
	void PixelShader(const int &i, const int &j, Camera &camera, Hitable &world);
};

#endif