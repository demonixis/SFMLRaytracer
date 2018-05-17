#include "hitable-list.hpp"

HitableList::HitableList()
{
}

HitableList::HitableList(const std::vector<Hitable*> &list)
{
	m_List = list;
}

HitableList::~HitableList()
{
	for (size_t i = 0; i < m_List.size(); i++)
		if (m_List[i] != nullptr)
			delete m_List[i];

	m_List.clear();
}

bool HitableList::Hit(const Ray &ray, float min, float max, HitRecord &record)
{
	HitRecord tmp;
	bool hitAnything = false;
	float closestSoFar = max;

	for (size_t i = 0; i < m_List.size(); i++)
	{
		if (m_List[i]->Hit(ray, min, closestSoFar, tmp))
		{
			hitAnything = true;
			closestSoFar = tmp.T;
			record = tmp;
		}
	}

	return hitAnything;
}