#include "metal-material.hpp"

MetalMaterial::MetalMaterial(const glm::vec3 &albedo, const float &fuzz)
{
	m_Albedo = albedo;
	m_Fuzz = fuzz;
}

bool MetalMaterial::Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered)
{
	auto reflected = glm::reflect(Mathf::UnitVector(ray.GetDirection()), record.Normal);
	scattered.Set(record.P, reflected + m_Fuzz * Mathf::RandomInUnitSphere());
	attenuation = m_Albedo;
	return glm::dot(scattered.GetDirection(), record.Normal) > 0;
}