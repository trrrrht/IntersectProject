#include"CalIntersect.h"

IntersectPoint LineIntersectLine(Line l1, Line l2) {
	IntersectPoint point;
	long long denominator = l1.a * l2.b - l2.a * l1.b;
	if (denominator == 0) {
		point.exist = false;
	}
	else {
		point.x = (l1.b * l2.c - l2.b * l1.c) * 1.0 / denominator;
		point.y = (l2.a * l1.c - l1.a * l2.c) * 1.0 / denominator;
		point.exist = true;
	}
	return point;
}

void CycleIntersectCycle(Cycle c1, Cycle c2, IntersectPoint* points) {
	long long denominator = c1.x * c1.x - 2 * c1.x * c2.x + c2.x * c2.x + c1.y * c1.y - 2 * c1.y * c2.y + c2.y * c2.y;
	long long numerator1 = -c1.r * c1.r * c1.x + c1.r * c1.r * c2.x + c2.r * c2.r * c1.x - c2.r * c2.r * c2.x + c1.x * c1.x * c1.x - c1.x * c1.x * c2.x - c1.x * c2.x * c2.x + c1.x * c1.y * c1.y - 2 * c1.x * c1.y * c2.y + c1.x * c2.y * c2.y + c2.x * c2.x * c2.x + c2.x * c1.y * c1.y - 2 * c2.x * c1.y * c2.y + c2.x * c2.y * c2.y;
	long long numerator2 = -c1.r * c1.r * c1.y + c1.r * c1.r * c2.y + c2.r * c2.r * c1.y - c2.r * c2.r * c2.y + c1.x * c1.x * c1.y + c1.x * c1.x * c2.y - 2 * c1.x * c2.x * c1.y - 2 * c1.x * c2.x * c2.y + c2.x * c2.x * c1.y + c2.x * c2.x * c2.y + c1.y * c1.y * c1.y - c1.y * c1.y * c2.y - c1.y * c2.y * c2.y + c2.y * c2.y * c2.y;
	long long numerator3 = (c1.r * c1.r + 2 * c1.r * c2.r + c2.r * c2.r - c1.x * c1.x + 2 * c1.x * c2.x - c2.x * c2.x - c1.y * c1.y + 2 * c1.y * c2.y - c2.y * c2.y) * (-c1.r * c1.r + 2 * c1.r * c2.r - c2.r * c2.r + denominator);

	if (numerator3 < 0 || denominator == 0) {
		points[0].exist = false;
		points[1].exist = false;
	}
	else {
		double numerator = sqrt(numerator3);
		points[0].x = (numerator1 - numerator * c1.y + numerator * c2.y) * 1.0 / (2 * denominator);
		points[0].y = (numerator2 + numerator * c1.x - numerator * c2.x) * 1.0 / (2 * denominator);
		points[1].x = (numerator1 + numerator * c1.y - numerator * c2.y) * 1.0 / (2 * denominator);
		points[1].y = (numerator2 - numerator * c1.x + numerator * c2.x) * 1.0 / (2 * denominator);
		points[0].exist = true;
		if (numerator3 == 0) {
			points[1].exist = false;
		}
		else {
			points[1].exist = true;
		}
	}
}

void LineIntersectCycle(Line l, Cycle c, IntersectPoint* points) {
	long long denominator = l.a * l.a + l.b * l.b;
	long long numerator1 = l.a * l.c - c.x * l.b * l.b + l.a * l.b * c.y;
	long long numerator2 = l.b * l.c - l.a * l.a * c.y + l.a * c.x * l.b;
	double numerator3 = -l.a * l.a * c.x * c.x + l.a * l.a * c.r * c.r - 2.0 * l.a * c.x * l.b * c.y - 2 * l.a * c.x * l.c - l.b * l.b * c.y * c.y + l.b * l.b * c.r * c.r - 2 * l.b * c.y * l.c - l.c * l.c;
	
	if (numerator3 < 0 || denominator == 0) {
		points[0].exist = false;
		points[1].exist = false;
	}
	else {
		numerator3 = sqrt(numerator3);
		points[0].x = -(numerator1 - l.b * numerator3) / denominator;
		points[0].y = -(numerator2 + l.a * numerator3) / denominator;
		points[1].x = -(numerator1 + l.b * numerator3) / denominator;
		points[1].y = -(numerator2 - l.a * numerator3) / denominator;
		
		points[0].exist = true;
		if (numerator3 == 0) {
			points[1].exist = false;
		}
		else {
			points[1].exist = true;
		}
	}
}