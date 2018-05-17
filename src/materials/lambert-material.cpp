#include "lambert-material.hpp"
#include "utils/mathf.hpp"

LambertMaterial::LambertMaterial(const glm::vec3 &albedo)
{
	m_Albedo = albedo;
	m_TextureEnabled = false;
	m_EmissiveEnabled = false;
}

LambertMaterial::LambertMaterial(Texture *texture)
{
	m_Texture = texture;
	m_TextureEnabled = true;
	m_EmissiveEnabled = false;
}

LambertMaterial::LambertMaterial(Texture *texture, Texture *emissive)
{
	m_Texture = texture;
	m_EmissiveTexture = emissive;
	m_TextureEnabled = true;
	m_EmissiveEnabled = true;
}

bool LambertMaterial::Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered)
{
	auto target = record.P + record.Normal + Mathf::RandomInUnitSphere();
	auto direction = target - record.P;
	scattered.Set(record.P, direction);
	attenuation = m_TextureEnabled ? m_Texture->Value(record.U, record.V, record.P) : m_Albedo;
	return true;
}

glm::vec3 LambertMaterial::Emitted(HitRecord &record)
{
	return m_EmissiveEnabled ? m_EmissiveTexture->Value(record.U, record.V, record.P) : glm::vec3(0);
}