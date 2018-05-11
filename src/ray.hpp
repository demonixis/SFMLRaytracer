#ifndef RAY_HPP
#define RAY_HPP

#include <glm.hpp>

class Ray
{
private:
	glm::vec3 m_Origin;
	glm::vec3 m_Direction;

public:
	Ray();
	Ray(const glm::vec3 &origin, const glm::vec3 &direction);
	void Set(const glm::vec3 &origin, const glm::vec3 &direction);
	inline glm::vec3 PointAtParameter(const float &t) const { return m_Origin + t * m_Direction; }
	inline glm::vec3 GetOrigin() const { return m_Origin; }
	inline glm::vec3 GetDirection() const { return m_Direction; }
};

#endif