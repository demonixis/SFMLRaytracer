#ifndef DIELETRIC_MATERIAL_HPP
#define DIELETRIC_MATERIAL_HPP

#include <memory>
#include <glm.hpp>
#include "utils/mathf.hpp"
#include "materials/material.hpp"
#include "hit-record.hpp"
#include "textures/texture.hpp"

class DieletricMaterial : public Material
{
private:
	std::shared_ptr<Texture> m_Texture;
	bool m_TextureEnabled;
	float m_RefIdx;

public:
	DieletricMaterial(const std::shared_ptr<Texture> &texture, const float refIdx);
	DieletricMaterial(const float refIdx);
	inline float RefIdx() { return m_RefIdx; }
	bool Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered) override;
};

#endif