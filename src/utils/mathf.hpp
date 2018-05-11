#ifndef MATHF_HPP
#define MATHF_HPP
#define _USE_MATH_DEFINES
#include <cmath>
#include <glm.hpp>
#include "random.hpp"

class Mathf
{
public:
	static float Pi()
	{
		return 3.14159265358979323846f;
	}

	static float Length(const glm::vec3 &vec)
	{
		return std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	}

	static float LengthSquared(const glm::vec3 &vec)
	{
		return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
	}

	static glm::vec3 RandomInUnitSphere()
	{
		glm::vec3 vec(0);
		glm::vec3 one(1, 1, 1);

		do
		{
			vec = 2.0f * Random::GetFloat3() - one;
		} while (LengthSquared(vec) > 1.0f);

		return vec;
	}

	static void RandomInUnitSphere(glm::vec3 &result)
	{
		glm::vec3 one(1, 1, 1);

		do
		{
			result = 2.0f * Random::GetFloat3() - one;
		} while (LengthSquared(result) > 1.0f);
	}

	static glm::vec3 UnitVector(const glm::vec3 &vector)
	{
		return vector / Length(vector);
	}

	static void UnitVector(const glm::vec3 &vector, glm::vec3 &target)
	{
		target = vector / Length(vector);
	}

	static void MakeUnitVector(glm::vec3 &vector)
	{
		float k = 1.0f / Length(vector);
		vector *= k;
	}

	static float Schlick(const float cosine, const float refIdx)
	{
		float r0 = (1.0f - refIdx) / (1 + refIdx);
		r0 = r0 * r0;
		return r0 + (1.0f - r0) * pow((1.0f - cosine), 5.0f);
	}

	static bool Refract(const glm::vec3 &v, const glm::vec3 &n, const float niOverNt, glm::vec3 &refracted)
	{
		auto uv = UnitVector(v);
		auto dt = glm::dot(uv, n);
		auto discriminant = 1.0f - niOverNt * niOverNt * (1.0f - dt * dt);

		if (discriminant > 0)
		{
			refracted = niOverNt * (uv - n * dt) - n * std::sqrt(discriminant);
			return true;
		}

		return false;
	}
};

#endif