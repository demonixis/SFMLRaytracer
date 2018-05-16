#ifndef CHECKER_TEXTURE_HPP
#define CHECKER_TEXTURE_HPP

#include <glm.hpp>
#include "texture.hpp"

class CheckerTexture : public Texture
{
private:
	glm::vec3 m_Odd;
	glm::vec3 m_Even;

public:
	CheckerTexture(const glm::vec3 &odd, const glm::vec3 &even);
	glm::vec3 Value(const float u, const float v, const glm::vec3 &p) override;
};

#endif