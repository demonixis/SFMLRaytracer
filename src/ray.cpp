#include <ray.hpp>

Ray::Ray()
{
	m_Origin = glm::vec3(0);
	m_Direction = glm::vec3(0);
}

Ray::Ray(const glm::vec3 &origin, const glm::vec3 &direction)
{
	m_Origin = origin;
	m_Direction = direction;
}

void Ray::Set(const glm::vec3 &origin, const glm::vec3 &direction)
{
	m_Origin = origin;
	m_Direction = direction;
}