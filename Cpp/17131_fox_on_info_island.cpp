#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using ll = long long;

const int MOD = 1'000'000'007;

struct point {
	int x;
	int y;
};

struct segTree {
private:
	vector<ll> tree;

	void updateHelper(int start, int end, int node, int idx) {
		if (idx < start || end < idx) return;
		if (start == end)
		{
			tree[node]++;
			return;
		}

		int mid = (start + end) / 2;
		
		if (idx <= mid) updateHelper(start, mid, node * 2, idx);
		else updateHelper(mid + 1, end, node * 2 + 1, idx);

		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}

	ll queryHelper(int start, int end, int node, int left, int right) {
		if (right < start || end < left) return 0;

		if (left <= start && end <= right) return tree[node];

		int mid = (start + end) / 2;
		return (queryHelper(start, mid, node * 2, left, right) + queryHelper(mid + 1, end, node * 2 + 1, left, right)) % MOD;
	}

public:
	int n;
	segTree(int n) {
		this->n = n;
		tree.resize(4 * n);
	}

	void update(int idx) {
		return updateHelper(0, n - 1, 1, idx);
	}

	ll query(int left, int right) {
		return queryHelper(0, n - 1, 1, left, right);
	}
	
};

ll process_batch(segTree& st, vector<int>& batch) {
	ll ans = 0;

	for (auto& x : batch)
	{
		ans = (ans + st.query(0, x - 1)*st.query(x+1,st.n-1)) % MOD;
	}

	for (auto& x : batch)
	{
		st.update(x);
	}

	return ans;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	vector<point> pts(N);
	vector<int> vec_x(N);
	for (int i = 0; i < N; ++i)
	{
		int x, y; cin >> x >> y;
		pts[i] = { x,y };
		vec_x[i] = x;
	}

	sort(pts.begin(), pts.end(), [](point a, point b)->bool
		{
			if (a.y == b.y) return a.x < b.x;
			return a.y > b.y;
		});

	auto comp_x = [](int x1, int x2) -> bool { return x1 < x2; };
	sort(vec_x.begin(), vec_x.end(), comp_x);
	vec_x.erase(unique(vec_x.begin(), vec_x.end()), vec_x.end());

	int prev_y = 200'001;
	vector<int> batch;
	segTree st(vec_x.size());
	ll ans = 0;
	for (int i = 0; i < N; ++i)
	{
		int cur_y = pts[i].y;
		int cur_x = pts[i].x;
		if (prev_y != cur_y)
		{
			ans = (ans + process_batch(st, batch)) % MOD;
			batch.clear();
			prev_y = cur_y;
		}
		auto it = lower_bound(vec_x.begin(), vec_x.end(), cur_x);
		int idx = it - vec_x.begin();
		batch.push_back(idx);
	}
	ans = (ans + process_batch(st, batch)) % MOD;

	cout << ans << '\n';
	return 0;
}