#include "sphere.hpp"

Sphere::Sphere(const glm::vec3 &center, float &radius, Material *material)
{
	m_Center = center;
	m_Radius = radius;
	m_Radius2 = radius * radius;
	m_Material = material;
}

Sphere::~Sphere()
{
	if (m_Material != nullptr)
		delete m_Material;
}

bool Sphere::Hit(const Ray &ray, const float &min, const float &max, HitRecord &record)
{
	return false;
}