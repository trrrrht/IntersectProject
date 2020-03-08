#pragma once
#include"StdHead.h"
#include"Cycle.h"
#include"IntersectPoint.h"
#include"Line.h"

IntersectPoint LineIntersectLine(Line l1, Line l2);
void CycleIntersectCycle(Cycle c1, Cycle c2, IntersectPoint* points);
void LineIntersectCycle(Line l, Cycle c, IntersectPoint* points);

