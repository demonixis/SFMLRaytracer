#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <glm.hpp>

class Texture
{
public:
	virtual glm::vec3 Value(const float u, const float v, const glm::vec3 &p) = 0;
};

#endif