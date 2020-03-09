#pragma once
#include"StdHead.h"
#include"IntersectPoint.h"

struct MyKeyHashHasher
{
	size_t operator()(const IntersectPoint& k) const noexcept
	{
		return std::hash<double>{}(k.x) + std::hash<double>{}(k.y);
	}
};

struct MyKeyHashComparator
{
	bool operator()(const IntersectPoint& k1, const IntersectPoint& k2) const noexcept
	{
		return abs(k1.x - k2.x) < eps && abs(k1.y - k2.y) < eps;
	}
};