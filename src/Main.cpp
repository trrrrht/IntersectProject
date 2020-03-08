#include"CalIntersect.h"
#include"Hash.h"

using namespace std;

const int max_line = 500001;
const int max_cycle = 500001;

Line lines[max_line];
int line_index = 0;

Cycle cycles[max_cycle];
int cycle_index = 0;

std::unordered_set<MyKey, MyKeyHashHasher, MyKeyHashComparator> s;

int main(int argc, char* argv[]) {
	int n;
	char figure;
	std::ifstream ifile;
	std::ofstream ofile;

	ifile.open(argv[2], ios::in);
	//cin >> n;
	ifile >> n;
	for (int i = 0; i < n; i++) {
		ifile >> figure;
		//cin >> figure;

		if (figure == 'L') {
			long long x1;
			long long x2;
			long long y1;
			long long y2;
			ifile >> x1 >> y1 >> x2 >> y2;
			//cin >> x1 >> y1 >> x2 >> y2;
			Line line = RegularLine(x1, y1, x2, y2);

			lines[line_index++] = line;
		}
		else if (figure == 'C') {
			long long x;
			long long y;
			long long r;
			ifile >> x >> y >> r;
			//cin >> x >> y >> r;
			Cycle cycle;
			cycle.x = x;
			cycle.y = y;
			cycle.r = r;
			cycles[cycle_index++] = cycle;
		}
	}
	

	ifile.close();

	for (int i = 0; i < line_index; i++) {
		for (int j = i + 1; j < line_index; j++) {
			IntersectPoint point = LineIntersectLine(lines[i], lines[j]);
			if (point.exist) {
				MyKey key;
				key.x = point.x;
				key.y = point.y;
				s.emplace(key);
		
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
				MyKey key;
				key.x = point1.x;
				key.y = point1.y;
				s.emplace(key);
			}
			if (point2.exist) {
				MyKey key;
				key.x = point2.x;
				key.y = point2.y;
				s.emplace(key);
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
				MyKey key;
				key.x = point1.x;
				key.y = point1.y;
				s.emplace(key);
			}
			if (point2.exist) {
				MyKey key;
				key.x = point2.x;
				key.y = point2.y;
				s.emplace(key);
			}
		}
	}

	ofile.open(argv[4], ios::out);
	ofile << s.size();
	ofile.close();
	//cout << s.size();
	return 0;
}