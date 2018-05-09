#ifndef LAMBERT_MATERIAL_HPP
#define LAMBERT_MATERIAL_HPP

#include <glm.hpp>
#include "utils/mathf.hpp"
#include "materials/material.hpp"
#include "hit-record.hpp"

class DieletricMaterial : public Material
{
private:
	float m_RefIdx;

public:
	DieletricMaterial(const float &refIdx);
	inline float RefIdx() { return m_RefIdx; }
	bool Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered) override;
};

#endif