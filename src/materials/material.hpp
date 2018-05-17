#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <glm.hpp>
#include "ray.hpp"
#include "hit-record.hpp"
#include "textures/texture.hpp"

class Material
{
protected:
	Texture *m_Texture;
	glm::vec3 m_Albedo;
	bool m_TextureEnabled;

public:
	inline glm::vec3 Albedo() { return m_Albedo; }
	inline bool TextureEnabled() { return m_TextureEnabled; }
	virtual bool Scatter(const Ray &ray, HitRecord &record, glm::vec3 &attenuation, Ray &scattered) = 0;
	virtual glm::vec3 Emitted(HitRecord &record) { return glm::vec3(0); }
};

#endif