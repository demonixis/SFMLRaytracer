#include "noise-texture.hpp"

NoiseTexture::NoiseTexture()
{
}

glm::vec3 NoiseTexture::Value(const float u, const float v, const glm::vec3 &p)
{
	return glm::vec3(1) * m_Noise.Noise(p);
}