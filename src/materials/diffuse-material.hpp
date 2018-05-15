#ifndef DIFFUSE_LIGHT_MATERIAL_HPP
#define DIFFUSE_LIGHT_MATERIAL_HPP

#include <memory>
#include <glm.hpp>
#include "utils/mathf.hpp"
#include "materials/material.hpp"
#include "hit-record.hpp"
#include "textures/texture.hpp"

class DiffuseLightMaterial : public Material
{
private:
	std::shared_ptr<Texture> m_Texture;

public:
	DiffuseLightMaterial(Texture &texture);
	bool Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered) override;
	glm::vec3 Emitted(HitRecord &record) override;
};

#endif