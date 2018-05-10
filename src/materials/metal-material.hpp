#ifndef METAL_MATERIAL_HPP
#define METAL_MATERIAL_HPP

#include <glm.hpp>
#include "utils/mathf.hpp"
#include "materials/material.hpp"
#include "hit-record.hpp"

class MetalMaterial : public Material
{
private:
	glm::vec3 m_Albedo;
	float m_Fuzz;

public:
	MetalMaterial(const glm::vec3 &albedo, const float &fuzz);
	inline glm::vec3 Albedo() { return m_Albedo; }
	bool Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered) override;
};

#endif