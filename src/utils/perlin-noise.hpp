#ifndef PERLIN_NOISE_HPP
#define PERLIN_NOISE_HPP

#include <glm.hpp>
#include <vector>

class PerlinNoise
{
private:
	std::vector<float> RanFloat;
	std::vector<int> PermX;
	std::vector<int> PermY;
	std::vector<int> PermZ;

public:
	PerlinNoise();
	float Noise(const glm::vec3 &p) const;

private:
	void Permute(std::vector<int> &arr);
	void PerlinGenerate(std::vector<float> &arr);
	void PerlinGeneratePerm(std::vector<int> &arr);
};

#endif