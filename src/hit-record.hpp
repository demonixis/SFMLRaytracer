#ifndef HITRECORD_HPP
#define HITRECORD_HPP

#include <glm.hpp>
#include "materials/material.hpp"

class Material;

struct HitRecord
{
	float U;
	float V;
	float T;
	glm::vec3 P;
	glm::vec3 Normal;
	Material *TargetMaterial;
};

#endif