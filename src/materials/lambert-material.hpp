#ifndef LAMBERT_MATERIAL_HPP
#define LAMBERT_MATERIAL_HPP

#include "materials/material.hpp"

class LambertMaterial : public Material
{
private:
	Texture *m_EmissiveTexture;
	bool m_EmissiveEnabled;

public:
	LambertMaterial(const glm::vec3 &albedo);
	LambertMaterial(Texture *texture);
	LambertMaterial(Texture *texture, Texture *emissive);
	bool Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered) override;
	glm::vec3 Emitted(HitRecord &record) override;
};

#endif