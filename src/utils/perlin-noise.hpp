#ifndef PERLIN_NOISE_HPP
#define PERLIN_NOISE_HPP

#include <glm.hpp>
#include <vector>

class PerlinNoise
{
private:
	static std::vector<float> RanFloat;
	static std::vector<int> PermX;
	static std::vector<int> PermY;
	static std::vector<int> PermZ;

public:
	PerlinNoise();

	float Noise(const glm::vec3 &p) const;

private:
	static void Permute(std::vector<int> &arr);
	static void PerlinGenerate(std::vector<float> &arr);
	static void PerlinGeneratePerm(std::vector<int> &arr);
};

#endif