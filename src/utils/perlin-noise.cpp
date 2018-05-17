#include "perlin-noise.hpp"
#include "utils/random.hpp"

PerlinNoise::PerlinNoise()
{
	PerlinGenerate(RanFloat);
	PerlinGeneratePerm(PermX);
	PerlinGeneratePerm(PermY);
	PerlinGeneratePerm(PermZ);
}

float PerlinNoise::Noise(const glm::vec3 &p) const
{
	int i = int(4 * p.x) & 255;
	int j = int(4 * p.y) & 255;
	int k = int(4 * p.z) & 255;
	return RanFloat[PermX[i] ^ PermY[j] ^ PermZ[k]];
}

void PerlinNoise::Permute(int *arr)
{
	for (int i = 0; i < 256; i++)
	{
		int target = int(Random::Value() * (i + 1));
		int tmp = arr[i];
		arr[i] = arr[target];
		arr[target] = tmp;
	}
}

void PerlinNoise::PerlinGenerate(float *arr)
{
	for (int i = 0; i < 256; i++)
		arr[i] = Random::Value();
}

void PerlinNoise::PerlinGeneratePerm(int *arr)
{
	for (int i = 0; i < 256; i++)
		arr[i] = i;

	Permute(arr);
}