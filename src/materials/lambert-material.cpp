#include "lambert-material.hpp"

LambertMaterial::LambertMaterial(const glm::vec3 &albedo)
{
	m_Albedo = albedo;
}

bool LambertMaterial::Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered)
{
	auto target = record.P + record.Normal + Mathf::RandomInUnitSphere();
	auto direction = target - record.P;
	scattered.Set(record.P, direction);

	attenuation = m_Albedo;

	return true;
}