#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm.hpp>
#include "ray.hpp"

class Camera
{
private:
	glm::vec3 m_Origin;
	glm::vec3 m_Rotation;
	glm::vec3 m_LowerLeftCorner;
	glm::vec3 m_Horizontal;
	glm::vec3 m_Vertical;
	glm::vec3 m_LookAt;
	glm::vec3 m_UpVector;
	float m_FieldOfView;
	float m_Aspect;

public:
	glm::vec3 Position() { return m_Origin; }

public:
	Camera();
	Camera(const glm::vec3 &origin, const glm::vec3 rotation, const glm::vec3 upVector, const float &fov, const float &aspect);
	void GetRay(Ray &ray, const float &u, const float &v);
	void Move(const float x, const float y, const float z);
	void Rotate(const float x, const float y, const float z);
private:
	void ComputeMatrix();
};

#endif