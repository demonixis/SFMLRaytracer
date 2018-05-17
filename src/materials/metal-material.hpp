#ifndef METAL_MATERIAL_HPP
#define METAL_MATERIAL_HPP

#include "materials/material.hpp"

class MetalMaterial : public Material
{
private:
	float m_Fuzz;

public:
	MetalMaterial(const glm::vec3 &albedo, const float fuzz);
	MetalMaterial(Texture *texture, const float fuzz);
	bool Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered) override;
};

#endif