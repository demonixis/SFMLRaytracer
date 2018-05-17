#ifndef DIFFUSE_LIGHT_MATERIAL_HPP
#define DIFFUSE_LIGHT_MATERIAL_HPP

#include <memory>
#include <glm.hpp>
#include "hit-record.hpp"
#include "utils/mathf.hpp"
#include "materials/material.hpp"
#include "textures/texture.hpp"

class DiffuseLightMaterial : public Material
{
public:
	DiffuseLightMaterial(const glm::vec3 &albedo);
	DiffuseLightMaterial(const std::shared_ptr<Texture> &texture);
	bool Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered) override;
	glm::vec3 Emitted(HitRecord &record) override;
};

#endif