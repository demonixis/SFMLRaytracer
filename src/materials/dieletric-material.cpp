#include "dieletric-material.hpp"

DieletricMaterial::DieletricMaterial(const float refIdx)
{
	m_RefIdx = refIdx;
	m_TextureEnabled = false;
}

DieletricMaterial::DieletricMaterial(const std::shared_ptr<Texture> &texture, const float refIdx)
{
	m_RefIdx = refIdx;
	m_Texture = texture;
	m_TextureEnabled = true;
}

bool DieletricMaterial::Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered)
{
	auto rayDirection = ray.GetDirection();
	glm::vec3 outwardNormal(0);
	auto reflected = glm::reflect(rayDirection, record.Normal);
	float niOverNt = 0.0f;

	attenuation = m_TextureEnabled ? m_Texture->Value(record.U, record.V, record.P) : glm::vec3(1.0f, 1.0f, 0.0f);
	glm::vec3 refracted(0);
	float reflectProbe = 0.0f;
	float cosine = 0.0f;

	if (glm::dot(rayDirection, record.Normal) > 0)
	{
		outwardNormal = -record.Normal;
		niOverNt = m_RefIdx;
		cosine = m_RefIdx * glm::dot(rayDirection, record.Normal) / Mathf::Length(rayDirection);
	}
	else
	{
		outwardNormal = record.Normal;
		niOverNt = 1.0f / m_RefIdx;
		cosine = -glm::dot(rayDirection, record.Normal) / Mathf::Length(rayDirection);
	}

	if (Mathf::Refract(rayDirection, outwardNormal, niOverNt, refracted))
	{
		reflectProbe = Mathf::Schlick(cosine, m_RefIdx);
	}
	else
	{
		scattered.Set(record.P, refracted);
		reflectProbe = 1.0f;
	}

	if (Random::Value() < reflectProbe)
		scattered.Set(record.P, reflected);
	else
		scattered.Set(record.P, refracted);

	return true;
}