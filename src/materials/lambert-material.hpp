#ifndef LAMBERT_MATERIAL_HPP
#define LAMBERT_MATERIAL_HPP

#include <memory>
#include <glm.hpp>
#include "utils/mathf.hpp"
#include "materials/material.hpp"
#include "hit-record.hpp"
#include "textures/texture.hpp"

class LambertMaterial : public Material
{
private:
	glm::vec3 m_Albedo;
	std::shared_ptr<Texture> m_Texture;
	bool m_TextureEnabled;

public:
	LambertMaterial(const glm::vec3 &albedo);
	LambertMaterial(const std::shared_ptr<Texture> &texture);
	inline glm::vec3 Albedo() { return m_Albedo; }
	bool Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered) override;
};

#endif