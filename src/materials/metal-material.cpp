#include "metal-material.hpp"
#include "utils/mathf.hpp"

MetalMaterial::MetalMaterial(const glm::vec3 &albedo, const float fuzz)
{
	m_Albedo = albedo;
	m_TextureEnabled = false;

	if (fuzz < 1)
		m_Fuzz = fuzz;
	else
		m_Fuzz = 1;
}

MetalMaterial::MetalMaterial(Texture *texture, const float fuzz)
{
	m_Texture = texture;
	m_TextureEnabled = true;

	if (fuzz < 1)
		m_Fuzz = fuzz;
	else
		m_Fuzz = 1;
}

bool MetalMaterial::Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered)
{
	auto reflected = glm::reflect(Mathf::UnitVector(ray.GetDirection()), record.Normal);
	scattered.Set(record.P, reflected + m_Fuzz * Mathf::RandomInUnitSphere());
	attenuation = m_TextureEnabled ? m_Texture->Value(record.U, record.V, record.P) : m_Albedo;
	return glm::dot(scattered.GetDirection(), record.Normal) > 0;
}