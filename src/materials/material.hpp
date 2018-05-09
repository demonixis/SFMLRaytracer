#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <glm.hpp>
#include "ray.hpp"
#include "hit-record.hpp"

class Material
{
public:
	virtual bool Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered) = 0;
	virtual glm::vec3 Emitted(HitRecord &record) { return glm::vec3(0); }
};

#endif