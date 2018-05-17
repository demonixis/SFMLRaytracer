#ifndef DIFFUSE_LIGHT_MATERIAL_HPP
#define DIFFUSE_LIGHT_MATERIAL_HPP

#include "materials/material.hpp"

class DiffuseLightMaterial : public Material
{
public:
	DiffuseLightMaterial(const glm::vec3 &albedo);
	DiffuseLightMaterial(Texture *texture);
	bool Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered) override;
	glm::vec3 Emitted(HitRecord &record) override;
};

#endif