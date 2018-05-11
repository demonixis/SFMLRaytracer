#include <cmath>
#include "camera.hpp"
#include "utils/mathf.hpp"

Camera::Camera()
{
	m_Origin = glm::vec3(0);
	m_Rotation = glm::vec3(0);
	m_LookAt = m_Origin + glm::vec3(0, 0, -1);
	m_UpVector = glm::vec3(0, 1, 0);
	m_FieldOfView = 75.0f * Mathf::Pi() / 180.0f;
	m_Aspect = float(640 / 480);
	ComputeMatrix();
}

Camera::Camera(const glm::vec3 &origin, const glm::vec3 rotation, const glm::vec3 upVector, const float fov, const float aspect)
{
	m_Origin = origin;
	m_Rotation = rotation;
	m_LookAt = m_Origin + glm::vec3(0, 0, -1);
	m_UpVector = upVector;
	m_FieldOfView = fov;
	m_Aspect = aspect;
	ComputeMatrix();
}

void Camera::Camera::GetRay(Ray &ray, const float u, const float v)
{
	ray.Set(m_Origin, m_LowerLeftCorner + u * m_Horizontal + v * m_Vertical - m_Origin);
}

void Camera::SetPosition(float x, float y, float z)
{
	m_Origin.x = x;
	m_Origin.y = y;
	m_Origin.z = z;
}

void Camera::Translate(const float x, const float y, const float z)
{
	m_Origin.x += x;
	m_Origin.y += y;
	m_Origin.z += z;
	m_LookAt = m_Origin + glm::vec3(0, 0, -1); // TODO, rotation later.
	ComputeMatrix();
}

void Camera::Rotate(const float x, const float y, const float z)
{
	m_Rotation.x += x;
	m_Rotation.y += y;
	m_Rotation.z += z;
	m_LookAt = m_Origin + glm::vec3(0, 0, -1); // TODO, rotation later.
	ComputeMatrix();
}

void Camera::ComputeMatrix()
{
	float theta = m_FieldOfView * Mathf::Pi() / 180.0f;
	float halfHeight = tan(theta / 2.0f);
	float halfWidth = m_Aspect * halfHeight;

	auto w = Mathf::UnitVector(m_Origin - m_LookAt);
	auto u = Mathf::UnitVector(glm::cross(m_UpVector, w));
	auto v = glm::cross(w, u);

	m_LowerLeftCorner.x = -halfWidth;
	m_LowerLeftCorner.y = -halfHeight;
	m_LowerLeftCorner.z = -1.0f;

	m_LowerLeftCorner = m_Origin - halfWidth * u - halfHeight * v - w;
	m_Horizontal = 2.0f * halfWidth * u;
	m_Vertical = 2.0f * halfHeight * v;
}