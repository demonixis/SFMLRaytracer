#ifndef METAL_MATERIAL_HPP
#define METAL_MATERIAL_HPP

#include <memory>
#include <glm.hpp>
#include "utils/mathf.hpp"
#include "materials/material.hpp"
#include "hit-record.hpp"
#include "textures/texture.hpp"

class MetalMaterial : public Material
{
private:
	std::shared_ptr<Texture> m_Texture;
	bool m_TextureEnabled;
	glm::vec3 m_Albedo;
	float m_Fuzz;

public:
	MetalMaterial(const std::shared_ptr<Texture> &texture, const float fuzz);
	MetalMaterial(const glm::vec3 &albedo, const float fuzz);
	inline glm::vec3 Albedo() { return m_Albedo; }
	bool Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered) override;
};

#endif