#ifndef CONSTANT_TEXTURE_HPP
#define CONSTANT_TEXTURE_HPP

#include "texture.hpp"
#include <SFML/Graphics/Color.hpp>

class ConstantTexture : public Texture
{
private:
	glm::vec3 m_Color;

public:
	ConstantTexture(const glm::vec3 &color);
	ConstantTexture(const sf::Color &color);
	ConstantTexture(const float r, const float g, const float b);
	glm::vec3 Value(const float u, const float v, const glm::vec3 &p) override;
};

#endif