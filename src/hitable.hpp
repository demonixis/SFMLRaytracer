#ifndef HITABLE_HPP
#define HITABLE_HPP

#include "ray.hpp"
#include "materials/material.hpp"
#include "hit-record.hpp"

class Hitable
{
protected:
	Material *m_Material;

public:
	inline Material *GetMaterial() { return m_Material; }
	virtual bool Hit(const Ray &ray, float min, float max, HitRecord &record) = 0;
};

#endif