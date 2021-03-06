#include "sphere.hpp"
#include "utils/mathf.hpp"

Sphere::Sphere(const glm::vec3 &center, float radius, Material *material)
{
	m_Center = center;
	m_Radius = radius;
	m_Radius2 = radius * radius;
	m_Material = material;
}

Sphere::~Sphere()
{
	if (m_Material != nullptr)
		delete m_Material;
}

bool Sphere::Hit(const Ray &ray, float min, float max, HitRecord &record)
{
	auto origin = ray.GetOrigin();
	auto rayDirection = ray.GetDirection();
	auto oc = origin - m_Center;
	auto a = glm::dot(rayDirection, rayDirection);
	auto b = glm::dot(oc, rayDirection);
	auto c = glm::dot(oc, oc) - m_Radius2;
	auto disciminent = b * b - a * c;

	if (disciminent > 0)
	{
		auto temp = (-b - std::sqrt(b * b - a * c)) / a;

		if (temp < max && temp > min)
		{
			record.T = temp;
			record.P = ray.PointAtParameter(record.T);
			record.Normal = (record.P - m_Center) / m_Radius;
			record.TargetMaterial = m_Material;

			UpdateSphereUV(record);

			return true;
		}

		temp = (-b + std::sqrt(b * b - a * c)) / a;

		if (temp < max && temp > min)
		{
			record.T = temp;
			record.P = ray.PointAtParameter(record.T);
			record.Normal = (record.P - m_Center) / m_Radius;
			record.TargetMaterial = m_Material;

			UpdateSphereUV(record);

			return true;
		}
	}

	return false;
}

void Sphere::UpdateSphereUV(HitRecord &record)
{
	auto p = (record.P - m_Center) / m_Radius;
	auto phi = std::atan2(p.z, p.x);
	auto theta = std::asin(p.y);
	record.U = 1.0f - (phi + Mathf::Pi()) / (2.0f * Mathf::Pi());
	record.V = (theta + Mathf::Pi() / 2.0f) / Mathf::Pi();
}