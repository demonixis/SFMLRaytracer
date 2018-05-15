#include "diffuse-material.hpp"

DiffuseLightMaterial::DiffuseLightMaterial(Texture &texture)
{
	m_Texture = std::make_shared<Texture>(texture);
}

bool DiffuseLightMaterial::Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered)
{
	return false;
}

glm::vec3 DiffuseLightMaterial::Emitted(HitRecord &record)
{
	return m_Texture->Value(record.U, record.V, record.P);
}