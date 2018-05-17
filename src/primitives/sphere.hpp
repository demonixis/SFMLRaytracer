#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm.hpp>
#include "hitable.hpp"
#include "hit-record.hpp"
#include "materials/material.hpp"

class Sphere : public Hitable
{
private:
	glm::vec3 m_Center;
	float m_Radius;
	float m_Radius2;

public:
	Sphere(const glm::vec3 &center, float radius);
	Sphere(const glm::vec3 &center, float radius, Material *material);
	~Sphere();

	bool Hit(const Ray &ray, float min, float max, HitRecord &record) override;
	void UpdateSphereUV(HitRecord &record);
};

#endif