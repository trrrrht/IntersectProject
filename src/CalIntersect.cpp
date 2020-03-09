#include"CalIntersect.h"

IntersectPoint LineIntersectLine(Line l1, Line l2) {
	IntersectPoint point;
	long long denominator = l1.a * l2.b - l2.a * l1.b;
	if (abs(denominator) < eps) {
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
	double subs1 = c1.x * c1.x - 2.0 * c1.x * c2.x + c2.x * c2.x + c1.y * c1.y - 2 * c1.y * c2.y + c2.y * c2.y; 
	double sigma = (c1.r * c1.r + 2.0 * c1.r * c2.r + c2.r * c2.r - c1.x * c1.x + 2 * c1.x * c2.x - c2.x * c2.x - c1.y * c1.y + 2 * c1.y * c2.y - c2.y * c2.y) * (-c1.r * c1.r + 2 * c1.r * c2.r - c2.r * c2.r + subs1);
	if (abs(subs1) < eps || sigma < 0) {
		points[0].exist = false;
		points[1].exist = false;
	}
	else {
		sigma = sqrt(sigma);
		double subs2 = -c1.r * c1.r * c1.x + c1.r * c1.r * c2.x + c2.r * c2.r * c1.x - c2.r * c2.r * c2.x + c1.x * c1.x * c1.x - c1.x * c1.x * c2.x - c1.x * c2.x * c2.x + c1.x * c1.y * c1.y - 2.0 * c1.x * c1.y * c2.y + c1.x * c2.y * c2.y + c2.x * c2.x * c2.x + c2.x * c1.y * c1.y - 2 * c2.x * c1.y * c2.y + c2.x * c2.y * c2.y;
		double subs3 = -c1.r * c1.r * c1.y + c1.r * c1.r * c2.y + c2.r * c2.r * c1.y - c2.r * c2.r * c2.y + c1.x * c1.x * c1.y + c1.x * c1.x * c2.y - 2.0 * c1.x * c2.x * c1.y - 2 * c1.x * c2.x * c2.y + c2.x * c2.x * c1.y + c2.x * c2.x * c2.y + c1.y * c1.y * c1.y - c1.y * c1.y * c2.y - c1.y * c2.y * c2.y + c2.y * c2.y * c2.y;
		points[0].x = (subs2 - sigma * c1.y + sigma * c2.y) / (2 * subs1);
		points[1].x = (subs2 + sigma * c1.y - sigma * c2.y) / (2 * subs1);

		points[0].y = (subs3 + sigma * c1.x - sigma * c2.x) / (2 * subs1);
		points[1].y = (subs3 - sigma * c1.x + sigma * c2.x) / (2 * subs1);
		points[0].exist = true;
		if (abs(points[0].x - points[1].x) < eps && abs(points[0].y - points[1].y) < eps) {
			points[1].exist = false;
		}
		else {
			points[1].exist = true;
		}
	}
}

void LineIntersectCycle(Line l, Cycle c, IntersectPoint* points) {
	long long deltax1 = l.x2 - l.x1;
	long long deltay1 = l.y2 - l.y1;
	long long deltax2 = c.x - l.x1;
	long long deltay2 = c.y - l.y1;
	long long cross = deltax1 * deltay2 - deltax2 * deltay1;
	long long norm = deltax1 * deltax1 + deltay1 * deltay1;
	double denominator1 = sqrt(norm);
	double distance = abs(cross / denominator1);
	if (abs(distance) - 1.0 * c.r > eps) {
		points[0].exist = false;
		points[1].exist = false;
	}
	else {
		double r = (deltax2 * deltax1 + deltay2 * deltay1) * 1.0 / norm;
		double deltax3 = l.x1 + deltax1 * r;
		double deltay3 = l.y1 + deltay1 * r;
		double deltax4 = deltax1 / denominator1;
		double deltay4 = deltay1 / denominator1;
		double deltax5 = deltax3 - c.x;
		double deltay5 = deltay3 - c.y;
		double base = sqrt(c.r * c.r - (deltax5 * deltax5 + deltay5 * deltay5));
		points[0].x = deltax3 + deltax4 * base;
		points[0].y = deltay3 + deltay4 * base;
		points[0].exist = true;
		points[1].x = deltax3 - deltax4 * base;
		points[1].y = deltay3 - deltay4 * base;
		if (abs(points[0].x - points[1].x) < eps && abs(points[0].y - points[1].y) < eps) {
			points[1].exist = false;
		}
		else {
			points[1].exist = true;
		}
	}
}