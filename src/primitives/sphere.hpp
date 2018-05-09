#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm.hpp>
#include "hitable.hpp"
#include "hit-record.hpp"

class Sphere : public Hitable
{
private:
	glm::vec3 m_Center;
	float m_Radius;
	float m_Radius2;

public:
	Sphere(const glm::vec3 &center, float &radius);
	~Sphere();
	bool Hit(const Ray &ray, const float &min, const float &max, HitRecord &record) override;
};

#endif