#include "image-texture.hpp"

ImageTexture::ImageTexture(std::vector<sf::Uint8> &data, int width, int height)
{
	m_Data = data;
	m_Width = width;
	m_Height = height;
}

glm::vec3 ImageTexture::Value(const float u, const float v, const glm::vec3 &p)
{
	int i = int(u * m_Width);
	int j = int((1 - v) * m_Height - 0.001f);

	if (i < 0)
		i = 0;

	if (j < 0)
		j = 0;

	if (i > m_Width - 1)
		i = m_Width - 1;

	if (j > m_Height - 1)
		j = m_Height - 1;

	float r = m_Data[3 * i + 3 * m_Width * j] / 255.0f;
	float g = m_Data[3 * i + 3 * m_Width * j + 1] / 255.0f;
	float b = m_Data[3 * i + 3 * m_Width * j + 2] / 255.0f;

	return glm::vec3(r, g, b);
}