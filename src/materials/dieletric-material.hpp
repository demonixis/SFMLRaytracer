#ifndef DIELETRIC_MATERIAL_HPP
#define DIELETRIC_MATERIAL_HPP

#include <memory>
#include <glm.hpp>
#include "hit-record.hpp"
#include "utils/mathf.hpp"
#include "materials/material.hpp"
#include "textures/texture.hpp"

class DieletricMaterial : public Material
{
private:
	float m_RefIdx;

public:
	DieletricMaterial(const float refIdx);
	DieletricMaterial(const glm::vec3 &albedo, const float refIdx);
	DieletricMaterial(const std::shared_ptr<Texture> &texture, const float refIdx);
	inline float RefIdx() { return m_RefIdx; }
	bool Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered) override;
};

#endif