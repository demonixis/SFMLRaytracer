#ifndef PERLIN_NOISE_HPP
#define PERLIN_NOISE_HPP

#include <glm.hpp>
#include <vector>

class PerlinNoise
{
private:
	float RanFloat[256];
	int PermX[256];
	int PermY[256];
	int PermZ[256];

public:
	PerlinNoise();
	float Noise(const glm::vec3 &p) const;

private:
	void Permute(int *arr);
	void PerlinGenerate(float *arr);
	void PerlinGeneratePerm(int *arr);
};

#endif