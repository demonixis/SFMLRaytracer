#ifndef IMAGE_TEXTURE_HPP
#define IMAGE_TEXTURE_HPP

#include <glm.hpp>
#include <SFML/Graphics.hpp>
#include "texture.hpp"

class ImageTexture : public Texture
{
private:
	std::vector<sf::Uint8> m_Data;
	int m_Width;
	int m_Height;

public:
	ImageTexture(std::vector<sf::Uint8> &data, int width, int height);
	glm::vec3 Value(const float u, const float v, const glm::vec3 &p) override;
};

#endif