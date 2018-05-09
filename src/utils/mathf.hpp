#ifndef MATHF_HPP
#define MATHF_HPP

#include <cmath>
#include <glm.hpp>
#include "random.hpp"

class Mathf
{
public:
	static float Length(const glm::vec3 &vec)
	{
		return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
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
};

#endif