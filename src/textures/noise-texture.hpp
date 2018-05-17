#ifndef NOISE_TEXTURE_HPP
#define NOISE_TEXTURE_HPP

#include "texture.hpp"
#include "utils/perlin-noise.hpp"

class NoiseTexture : public Texture
{
private:
	PerlinNoise m_Noise;

public:
	NoiseTexture();
	glm::vec3 Value(const float u, const float v, const glm::vec3 &p) override;
};

#endif