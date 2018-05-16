#include "lambert-material.hpp"

LambertMaterial::LambertMaterial(const glm::vec3 &albedo)
{
	m_Albedo = albedo;
	m_TextureEnabled = false;
}

LambertMaterial::LambertMaterial(const std::shared_ptr<Texture> &texture)
{
	m_Texture = texture;
	m_TextureEnabled = true;
}

bool LambertMaterial::Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered)
{
	auto target = record.P + record.Normal + Mathf::RandomInUnitSphere();
	auto direction = target - record.P;
	scattered.Set(record.P, direction);

	attenuation = m_TextureEnabled ? m_Texture->Value(record.U, record.V, record.P) : m_Albedo;

	return true;
}