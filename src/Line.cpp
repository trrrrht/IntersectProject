#include"Line.h"

Line RegularLine(long long x1, long long y1, long long x2, long long y2) {
	Line line;
	line.a = y2 - y1;
	line.b = x1 - x2;
	line.c = x2 * y1 - x1 * y2;
	return line;
}

