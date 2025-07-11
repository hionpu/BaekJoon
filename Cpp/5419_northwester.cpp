#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <functional>

using namespace std;
using ll = long long;

struct point {
	int x;
	int y;
};

struct segTree {
private:
	int n;
	vector<int> tree;

	void updateHelper(int start, int end, int node, int idx) {
		if (idx < start || idx > end) return;

		if (start == end)
		{
			tree[node]++;
			return;
		}

		int mid = (start + end) / 2;
		updateHelper(start, mid, node * 2, idx);
		updateHelper(mid + 1, end, node * 2 + 1, idx);

		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}

	int queryHelper(int start, int end, int node, int left, int right) {
		if (right < start || end < left) return 0;
		if (left <= start && end <= right) return tree[node];

		int mid = (start + end) / 2;
		return queryHelper(start, mid, node * 2, left, right) +
			queryHelper(mid + 1, end, node * 2 + 1, left, right);
	}

public:
	segTree(int n) {
		this->n = n;
		tree.resize(4 * n);
	}

	void update(int idx) {
		return updateHelper(0, n - 1, 1, idx);
	}

	int query(int idx) {
		return queryHelper(0, n - 1, 1, 0, idx);
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;

	while (T--)
	{
		int n; cin >> n;
		vector<point> pts;
		vector<int> vec_y;

		for (int i = 0; i < n; ++i)
		{
			int x, y; cin >> x >> y;
			pts.push_back({ x,y });
			vec_y.push_back(y);
		}

		sort(pts.begin(), pts.end(), [](point a, point b) -> bool
			{
				if (a.x == b.x) return a.y > b.y;
				else return a.x < b.x;
			});

		function<bool(int, int)> comp_y = [](int y1, int y2) -> bool { return y1 > y2; };
		sort(vec_y.begin(), vec_y.end(), comp_y);
		vec_y.erase(unique(vec_y.begin(), vec_y.end()), vec_y.end());

		segTree st(vec_y.size());

		ll ans = 0;
		for (int i = 0; i < n; ++i)
		{
			auto it = upper_bound(vec_y.begin(), vec_y.end(), pts[i].y, comp_y) - 1;
			int idx = it - vec_y.begin();

			ans += st.query(idx);
			st.update(idx);
		}
		cout << ans << '\n';
	}

	return 0;
}