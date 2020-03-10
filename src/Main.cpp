#include"CalIntersect.h"
#include"Hash.h"

using namespace std;

const int max_line = 500001;
const int max_cycle = 500001;

Line lines[max_line];
int line_index = 0;

Cycle cycles[max_cycle];
int cycle_index = 0;

bool comparer(IntersectPoint& point1, IntersectPoint& point2)
{
	if (abs(point1.x - point2.x) < eps) {
		return point1.y > point2.y;
	}
	else {
		return point1.x > point2.x;
	}
}

bool myunique(IntersectPoint& point1, IntersectPoint& point2)
{
	if (abs(point1.x - point2.x) < eps && abs(point1.y - point2.y) < eps) {
		return true;
	}
	else {
		return false;
	}
}

vector<IntersectPoint> v;

long long a[max_line];
long long b[max_line];
long long c[max_line];
long long x1[max_line];
long long x2[max_line];
long long ly1[max_line];
long long ly2[max_line];
long long x[max_cycle];
long long y[max_cycle];
long long r[max_cycle];


int main(int argc, char* argv[]) {
	int n;
	char figure;

	long long subs1;
	long long sigma;
	long long subs2;
	long long subs3;
	long long deltax1;
	long long deltay1;
	long long deltax2;
	long long deltay2;
	long long cross;
	long long norm;
	double denominator1;
	double distance;
	double r_;
	double deltax3;
	double deltay3;
	double deltax4;
	double deltay4;
	double deltax5;
	double deltay5;
	double base;

	long long _x1;
	long long _x2;
	long long _y1;
	long long _y2;

	long long _x;
	long long _y;
	long long _r;

	std::ifstream ifile;
	std::ofstream ofile;

	ifile.open(argv[2], ios::in);
	//cin >> n;
	ifile >> n;
	for (int i = 0; i < n; i++) {
		ifile >> figure;
		//cin >> figure;

		if (figure == 'L') {
			ifile >> _x1 >> _y1 >> _x2 >> _y2;
			//cin >> _x1 >> _y1 >> _x2 >> _y2;
			a[line_index] = _y2 - _y1;
			b[line_index] = _x1 - _x2;
			c[line_index] = _x2 * _y1 - _x1 * _y2;
			x1[line_index] = _x1;
			x2[line_index] = _x2;
			ly1[line_index] = _y1;
			ly2[line_index++] = _y2;
		}
		else if (figure == 'C') {
			ifile >> _x >> _y >> _r;
			//cin >> _x >> _y >> _r;
			x[cycle_index] = _x;
			y[cycle_index] = _y;
			r[cycle_index++] = _r;
		}
	}

	ifile.close();
	

	for (int i = 0; i < line_index; i++) {
		for (int j = i + 1; j < line_index; j++) {
			IntersectPoint point;
			long long denominator = a[i] * b[j] - a[j] * b[i];
			if (abs(denominator) < eps) {
			}
			else {
				point.x = (b[i] * c[j] - b[j] * c[i]) * 1.0 / denominator;
				point.y = (a[j] * c[i] - a[i] * c[j]) * 1.0 / denominator;
				v.push_back(point);
			}
		}
	}


	for (int i = 0; i < cycle_index; i++) {
		for (int j = i + 1; j < cycle_index; j++) {
			subs1 = x[i] * x[i] - 2 * x[i] * x[j] + x[j] * x[j] + y[i] * y[i] - 2 * y[i] * y[j] + y[j] * y[j];
			sigma = (r[i] * r[i] + 2 * r[i] * r[j] + r[j] * r[j] - x[i] * x[i] + 2 * x[i] * x[j] - x[j] * x[j] - y[i] * y[i] + 2 * y[i] * y[j] - y[j] * y[j]) * (-r[i] * r[i] + 2 * r[i] * r[j] - r[j] * r[j] + subs1);
			if (subs1 == 0 || sigma < 0) {
			}
			else {
				double sigma1 = sqrt(sigma);
				subs2 = -r[i] * r[i] * x[i] + r[i] * r[i] * x[j] + r[j] * r[j] * x[i] - r[j] * r[j] * x[j] + x[i] * x[i] * x[i] - x[i] * x[i] * x[j] - x[i] * x[j] * x[j] + x[i] * y[i] * y[i] - 2 * x[i] * y[i] * y[j] + x[i] * y[j] * y[j] + x[j] * x[j] * x[j] + x[j] * y[i] * y[i] - 2 * x[j] * y[i] * y[j] + x[j] * y[j] * y[j];
				subs3 = -r[i] * r[i] * y[i] + r[i] * r[i] * y[j] + r[j] * r[j] * y[i] - r[j] * r[j] * y[j] + x[i] * x[i] * y[i] + x[i] * x[i] * y[j] - 2 * x[i] * x[j] * y[i] - 2 * x[i] * x[j] * y[j] + x[j] * x[j] * y[i] + x[j] * x[j] * y[j] + y[i] * y[i] * y[i] - y[i] * y[i] * y[j] - y[i] * y[j] * y[j] + y[j] * y[j] * y[j];
				IntersectPoint point1;
				IntersectPoint point2;
				point1.x = (subs2 - sigma1 * y[i] + sigma1 * y[j]) / (2 * subs1);
				point2.x = (subs2 + sigma1 * y[i] - sigma1 * y[j]) / (2 * subs1);
				point1.y = (subs3 + sigma1 * x[i] - sigma1 * x[j]) / (2 * subs1);
				point2.y = (subs3 - sigma1 * x[i] + sigma1 * x[j]) / (2 * subs1);
				v.push_back(point1);
				if (abs(point1.x - point2.x) < eps && abs(point1.y - point2.y) < eps) {
				}
				else {
					v.push_back(point2);
				}
			}
		}
	}

	


	for (int i = 0; i < line_index; i++) {
		for (int j = 0; j < cycle_index; j++) {
			deltax1 = x2[i] - x1[i];
			deltay1 = ly2[i] - ly1[i];
			deltax2 = x[j] - x1[i];
			deltay2 = y[j] - ly1[i];
			cross = deltax1 * deltay2 - deltax2 * deltay1;
			norm = deltax1 * deltax1 + deltay1 * deltay1;
			denominator1 = sqrt(norm);
			distance = abs(cross / denominator1);
			if (distance - 1.0 * r[j] > eps) {
			}
			else {
				r_ = (deltax2 * deltax1 + deltay2 * deltay1) * 1.0 / norm;
				deltax3 = x1[i] + deltax1 * r_;
				deltay3 = ly1[i] + deltay1 * r_;
				deltax4 = deltax1 / denominator1;
				deltay4 = deltay1 / denominator1;
				deltax5 = deltax3 - x[j];
				deltay5 = deltay3 - y[j];
				IntersectPoint point1;
				IntersectPoint point2;
				if (abs(distance - 1.0 * r[j]) < eps) {
					point1.x = deltax3;
					point1.y = deltay3;
					v.push_back(point1);
					continue;
				}
				base = sqrt(r[j] * r[j] - (deltax5 * deltax5 + deltay5 * deltay5));
				point1.x = deltax3 + deltax4 * base;
				point1.y = deltay3 + deltay4 * base;
				point2.x = deltax3 - deltax4 * base;
				point2.y = deltay3 - deltay4 * base;
				v.push_back(point1);
				v.push_back(point2);
			}
		}
	}

	sort(v.begin(), v.end(), comparer);
	vector<IntersectPoint>::iterator new_end = unique(v.begin(), v.end(), myunique);
	
	//for (auto iter = v.begin(); iter != v.end(); iter++) {
	//	cout << iter->x << "  " << iter->y << "\n";
	//}
	ofile.open(argv[4], ios::out);
	ofile << new_end - v.begin();
	ofile.close();

	//cout << new_end - v.begin();
	return 0;
}

/*int main(int argc, char* argv[]) {
	int n;
	char figure;
	std::ifstream ifile;
	std::ofstream ofile;

	//ifile.open(argv[2], ios::in);
	cin >> n;
	//ifile >> n;
	for (int i = 0; i < n; i++) {
		//ifile >> figure;
		cin >> figure;

		if (figure == 'L') {
			long long x1;
			long long x2;
			long long y1;
			long long y2;
			//ifile >> x1 >> y1 >> x2 >> y2;
			cin >> x1 >> y1 >> x2 >> y2;
			Line line = RegularLine(x1, y1, x2, y2);

			lines[line_index++] = line;
		}
		else if (figure == 'C') {
			long long x;
			long long y;
			long long r;
			//ifile >> x >> y >> r;
			cin >> x >> y >> r;
			Cycle cycle;
			cycle.x = x;
			cycle.y = y;
			cycle.r = r;
			cycles[cycle_index++] = cycle;
		}
	}
	
	//ifile.close();

	for (int i = 0; i < line_index; i++) {
		for (int j = i + 1; j < line_index; j++) {
			IntersectPoint point = LineIntersectLine(lines[i], lines[j]);
			if (point.exist) {
				v.push_back(point);
			}
		}
	}

	for (int i = 0; i < cycle_index; i++) {
		for (int j = i + 1; j < cycle_index; j++) {
			IntersectPoint points[2];
			CycleIntersectCycle(cycles[i], cycles[j], points);
			IntersectPoint point1 = points[0];
			IntersectPoint point2 = points[1];
			if (point1.exist) {
				v.push_back(point1);
			}
			if (point2.exist) {
				v.push_back(point2);
			}
		}
	}

	

	for (int i = 0; i < line_index; i++) {
		for (int j = 0; j < cycle_index; j++) {
			IntersectPoint points[2];
			LineIntersectCycle(lines[i], cycles[j], points);
			IntersectPoint point1 = points[0];
			IntersectPoint point2 = points[1];
			if (point1.exist) {
				v.push_back(point1);
			}
			if (point2.exist) {
				v.push_back(point2);
			}
		}
	}

	sort(v.begin(), v.end(), comparer);
	vector<IntersectPoint>::iterator new_end = unique(v.begin(), v.end(), myunique);

	//ofile.open(argv[4], ios::out);
	//ofile << new_end - v.begin();
	//ofile.close();
	cout << new_end - v.begin();


	return 0;
}*/
