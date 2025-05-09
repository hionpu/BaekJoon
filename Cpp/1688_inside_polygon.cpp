#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

struct point {
	int x;
	int y;
};

struct segment {
	point p1;
	point p2;
};

bool isOnEdge(segment& edge, point p) {
	double a = (p.y - edge.p1.y) * (edge.p2.x - p.x);
	double c = (edge.p2.y - p.y) * (p.x - edge.p1.x);
	if (a == c)
	{
		if (min(edge.p1.x, edge.p2.x) <= p.x &&
			p.x <= max(edge.p1.x, edge.p2.x) &&
			min(edge.p1.y, edge.p2.y) <= p.y &&
			p.y <= max(edge.p1.y, edge.p2.y))
			return true;
	}
	return false;
}

int ccw(point a, point b, point c) {
	int cross = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	return cross == 0 ? 0 : (cross > 0 ? 1 : -1);
}

bool checkIntersect(segment& edge, segment& ray) {
	point a = edge.p1;
	point b = edge.p2;
	point c = ray.p1;
	point d = ray.p2;
	int abc = ccw(a, b, c);
	int abd = ccw(a, b, d);
	int cda = ccw(c, d, a);
	int cdb = ccw(c, d, b);

	if (abc * abd <= 0 && cda * cdb <= 0)
	{
		if (abc == 0 && abd == 0)
		{
			if (min(max(a.x,b.x), max(c.x,d.x)) <= max(min(a.x,b.x),min(c.x,d.x)) &&
				min(max(a.x, b.x), max(c.x, d.x)) <= max(min(a.x, b.x), min(c.x, d.x)))
				return true;
			return false;
		}
		return true;
	}
	return false;
}

bool checkInside(vector<segment>& polygon, point p) {
	int intersectCount = 0;
	segment ray = { p, {maxX, p.y} };
	for (auto& edge : polygon)
	{
		if (isOnEdge(edge, p))
		{
			return true;
		}

		if (checkIntersect(edge, ray));
	}
}
int maxX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	int x1, y1; cin >> x1 >> y1;
	maxX = x1;
	vector<segment> polygon;

	for (int i = 1; i < N; ++i)
	{
		int x2, y2; cin >> x2 >> y2;
		if (maxX < x2) maxX = x2;
		polygon.push_back({ { x1,y1 }, { x2,y2 } });
		x1 = x2;
		y1 = y2;
	}
	point A, B, C;
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

	cout << checkInside(polygon, A) << '\n';
	cout << checkInside(polygon, B) << '\n';
	cout << checkInside(polygon, C) << '\n';

	return 0;
}