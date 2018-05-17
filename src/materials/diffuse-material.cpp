#include "diffuse-material.hpp"

DiffuseLightMaterial::DiffuseLightMaterial(const glm::vec3 &albedo)
{
	m_Albedo = albedo;
	m_TextureEnabled = false;
}

DiffuseLightMaterial::DiffuseLightMaterial(const std::shared_ptr<Texture> &texture)
{
	m_Texture = texture;
	m_TextureEnabled = true;
}

bool DiffuseLightMaterial::Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered)
{
	return false;
}

glm::vec3 DiffuseLightMaterial::Emitted(HitRecord &record)
{
	return m_Texture->Value(record.U, record.V, record.P);
}