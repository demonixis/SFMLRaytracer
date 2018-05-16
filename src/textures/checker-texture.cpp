#include "checker-texture.hpp"
#include <cmath>

CheckerTexture::CheckerTexture(const glm::vec3 &odd, const glm::vec3 &even)
{
	m_Odd = odd;
	m_Even = even;
}

glm::vec3 CheckerTexture::Value(const float u, const float v, const glm::vec3 &p)
{
	float sines = std::sin(10.0f * p.x) * std::sin(10.0f * p.y) * std::sin(10.0f * p.z);
	return sines < 0 ? m_Odd : m_Even;
}