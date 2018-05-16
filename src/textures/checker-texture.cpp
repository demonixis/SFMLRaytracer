#include "checker-texture.hpp"
#include <cmath>

CheckerTexture::CheckerTexture(std::shared_ptr<Texture> &oddTexture, std::shared_ptr<Texture> &evenTexture)
{
	m_OddTexture = oddTexture;
	m_EvenTexture = evenTexture;
}

glm::vec3 CheckerTexture::Value(const float u, const float v, const glm::vec3 &p)
{
	float sines = std::sin(10.0f * p.x) * std::sin(10.0f * p.y) * std::sin(10.0f * p.z);

	if (sines < 0)
		return m_OddTexture->Value(u, v, p);

	return m_EvenTexture->Value(u, v, p);
}