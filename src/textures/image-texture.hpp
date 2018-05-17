#ifndef IMAGE_TEXTURE_HPP
#define IMAGE_TEXTURE_HPP

#include "texture.hpp"
#include <SFML/Graphics.hpp>

class ImageTexture : public Texture
{
private:
	std::vector<sf::Uint8> m_Data;
	int m_Width;
	int m_Height;

public:
	ImageTexture(sf::Texture &texture);
	ImageTexture(sf::Image &image);
	ImageTexture(std::vector<sf::Uint8> &data, int width, int height);
	glm::vec3 Value(const float u, const float v, const glm::vec3 &p) override;

private:
	void Setup(const sf::Uint8 *pixels, int width, int height);
};

#endif