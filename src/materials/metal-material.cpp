#include "metal-material.hpp"

MetalMaterial::MetalMaterial(const glm::vec3 &albedo, const float fuzz)
{
	m_Albedo = albedo;
	m_Fuzz = fuzz;
	m_TextureEnabled = false;
}

MetalMaterial::MetalMaterial(const std::shared_ptr<Texture> &texture, const float fuzz)
{
	m_Texture = texture;
	m_Fuzz = fuzz;
	m_TextureEnabled = true;
}

bool MetalMaterial::Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered)
{
	auto reflected = glm::reflect(Mathf::UnitVector(ray.GetDirection()), record.Normal);
	scattered.Set(record.P, reflected + m_Fuzz * Mathf::RandomInUnitSphere());
	attenuation = m_TextureEnabled ? m_Texture->Value(record.U, record.V, record.P) : m_Albedo;
	return glm::dot(scattered.GetDirection(), record.Normal) > 0;
}