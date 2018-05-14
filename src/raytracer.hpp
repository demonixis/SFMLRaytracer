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

class SubRect
{
public:
	bool Done;
	int X;
	int Y;
	int Width;
	int Height;

	SubRect(const int x, const int y, const int width, const int height, int slice)
	{
		X = width / slice * x;
		Y = height / slice * y;
		Width = width / slice;
		Height = height / slice;
		Done = false;
	}
};

class Raytracer
{
private:
	sf::Uint8 *m_ColorBuffer;
	sf::Sprite m_BackbufferSprite;
	sf::Texture m_Backbuffer;
	sf::Clock m_Stopwatch;
	sf::Uint32 m_LastFrameTime;
	std::vector<SubRect> m_SubRects;
	std::vector<std::thread> m_ThreadPool;
	bool m_ThreadIsRunning;
	int m_RenderWidth;
	int m_RenderHeight;
	int m_Step;
	int m_ThreadSleepTime;
	int m_SlicePixels;
	int m_ChunkCount;

public:
	sf::Uint32 LastFrameTime() { return m_LastFrameTime; }
	int RenderWidth() { return m_RenderWidth; }
	int RenderHeight() { return m_RenderHeight; }
	int Step() { return m_Step; }
	void SetStep(int value) { if (value > 0) m_Step = value; }

public:
	Raytracer();
	Raytracer(const int width, const int height, const float scale, const int threadCount = 0);
	~Raytracer();
	void Start(Camera &camera, Hitable &world);
	void StartMT(Camera &camera, HitableList &world);
	void Stop();
	void Render(Camera &camera, Hitable &world);
	void Present(sf::RenderWindow &window);
	void PresentMT(sf::RenderWindow &window);

private:
	void StartRenderLoop(Camera &camera, HitableList &world, const int subRectIndex);
	glm::vec3 GetColor(const Ray &ray, Hitable &world);
	void PixelShader(const int i, const int j, Camera &camera, Hitable &world);
	void RenderMT(Camera &camera, Hitable &world, const int subRectIndex);
	void PixelShaderMT(const int i, const int j, Camera &camera, Hitable &world, const int subRectIndex);
};

#endif