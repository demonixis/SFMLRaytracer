#ifndef CHECKER_TEXTURE_HPP
#define CHECKER_TEXTURE_HPP

#include <glm.hpp>
#include <memory>
#include "texture.hpp"

class CheckerTexture : public Texture
{
private:
	std::shared_ptr<Texture> m_OddTexture;
	std::shared_ptr<Texture> m_EvenTexture;

public:
	CheckerTexture(std::shared_ptr<Texture> oddTexture, std::shared_ptr<Texture> evenTexture);
	glm::vec3 Value(const float u, const float v, const glm::vec3 &p) override;
};

#endif