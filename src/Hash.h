#pragma once
#include"StdHead.h"

struct MyKey
{
	double x;
	double y;
};

struct MyKeyHashHasher
{
	size_t operator()(const MyKey& k) const noexcept
	{
		return std::hash<double>{}(k.x) + std::hash<double>{}(k.y);
	}
};

struct MyKeyHashComparator
{
	bool operator()(const MyKey& k1, const MyKey& k2) const noexcept
	{
		return abs(k1.x - k2.x) < 0.000001 && abs(k1.y - k2.y) < 0.000001;
	}
};