#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <cstdlib>
#include <glm.hpp>
#include <SFML\Graphics\Color.hpp>

class Random
{
public:
	static float Value() 
	{ 
		return static_cast <float> (rand()) / static_cast <float> (RAND_MAX); 
	}

	static void Value(float &target)
	{
		target = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	}

	static glm::vec3 GetFloat3() 
	{ 
		return glm::vec3(Value(), Value(), Value()); 
	}

	static void GetFloat3(glm::vec3 &vector)
	{
		vector.x = Value();
		vector.y = Value();
		vector.z = Value();
	}

	static glm::vec3 GetFloat3Pow()
	{ 
		return glm::vec3(Value() * Value(), Value() * Value(), Value() * Value());
	}
	
	static void GetFloat3Pow(glm::vec3 &vector)
	{
		vector.x = Value() * Value();
		vector.y = Value() * Value();
		vector.z = Value() * Value();
	}

	static sf::Color GetColor() 
	{ 
		return sf::Color(sf::Uint8(Value() * 255), sf::Uint8(Value() * 255), sf::Uint8(Value() * 255), 255);
	}

	static void GetColor(sf::Color &color)
	{
		color.r = sf::Uint8(Value() * 255);
		color.g = sf::Uint8(Value() * 255);
		color.b = sf::Uint8(Value() * 255);
		color.a = 255;
	}
};

#endif