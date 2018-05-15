#ifndef PERLIN_NOISE_HPP
#define PERLIN_NOISE_HPP

#include <glm.hpp>

class PerlinNoise
{
private:
	static float *RanFloat;
	static int *PermX;
	static int *PermY;
	static int *PermZ;

public:
	PerlinNoise();
	float Noise(glm::vec3 &p);
};

#endif