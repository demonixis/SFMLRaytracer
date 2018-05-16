#include "constant-texture.hpp"

ConstantTexture::ConstantTexture(const glm::vec3 &color)
{
	m_Color = color;
}

ConstantTexture::ConstantTexture(const sf::Color &color)
{
	m_Color.x = color.r;
	m_Color.y = color.g;
	m_Color.z = color.b;
}

ConstantTexture::ConstantTexture(const float r, const float g, const float b)
{
	m_Color.x = r;
	m_Color.y = g;
	m_Color.z = b;
}

glm::vec3 ConstantTexture::Value(const float u, const float v, const glm::vec3 &p)
{
	return m_Color;
}
