#ifndef LAMBERT_MATERIAL_HPP
#define LAMBERT_MATERIAL_HPP

#include <glm.hpp>
#include "hit-record.hpp"
#include "utils/mathf.hpp"
#include "materials/material.hpp"
#include "textures/texture.hpp"

class LambertMaterial : public Material
{
private:
	std::shared_ptr<Texture> m_EmissiveTexture;
	bool m_EmissiveEnabled;

public:
	LambertMaterial(const glm::vec3 &albedo);
	LambertMaterial(const std::shared_ptr<Texture> &texture);
	LambertMaterial(const std::shared_ptr<Texture> &texture, const std::shared_ptr<Texture> &illum);
	bool Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered) override;
};

#endif