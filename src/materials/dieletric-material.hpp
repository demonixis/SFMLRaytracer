#ifndef DIELETRIC_MATERIAL_HPP
#define DIELETRIC_MATERIAL_HPP

#include "materials/material.hpp"

class DieletricMaterial : public Material
{
private:
	float m_RefIdx;

public:
	DieletricMaterial(const float refIdx, const glm::vec3 &albedo = glm::vec3(1.0f, 1.0f, 0.0f));
	DieletricMaterial(Texture *texture, const float refIdx);
	inline float RefIdx() { return m_RefIdx; }
	bool Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered) override;
};

#endif