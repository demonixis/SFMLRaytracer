#ifndef HITABLE_LIST_HPP
#define HITABLE_LIST_HPP

#include <vector>
#include "hitable.hpp"
#include "ray.hpp"
#include "hit-record.hpp"

class HitableList : public Hitable
{
private:
	std::vector<Hitable*> m_List;

public:
	HitableList(const std::vector<Hitable*> &list);
	~HitableList();
	bool Hit(const Ray &ray, const float &min, const float &max, HitRecord &record) override;
};

#endif