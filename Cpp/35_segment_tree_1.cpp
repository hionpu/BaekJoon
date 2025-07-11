#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using ll = long long;

struct segTree {
private:
	int n;
	vector<ll> arr;
	vector<ll> tree;

public:
	segTree(vector<ll>& arr) {
		this->n = arr.size();
		this->arr = arr;
		tree.resize(4 * n);
		init(0, n - 1, 1);
	}

	void init(int start, int end, int node) {
		if (start == end)
		{
			tree[node] = arr[start];
			return;
		}

		int mid = (start + end) / 2;
		init(start, mid, node * 2);
		init(mid + 1, end, node * 2 + 1);

		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}

	ll sum(int left, int right) {
		return sumHelper(0, n - 1, 1, left, right);

	}

	ll sumHelper(int start, int end, int node, int left, int right) {
		if (right < start || left > end) return 0;

		if (left <= start && end <= right) return tree[node];

		int mid = (start + end) / 2;
		return sumHelper(start, mid, node * 2, left, right) + sumHelper(mid + 1, end, node * 2 + 1, left, right);
	}

	void update(int idx, ll newValue) {
		ll diff = newValue - arr[idx];
		arr[idx] = newValue;
		updateHelper(0, n - 1, 1, idx, diff);
	}

	void updateHelper(int start, int end, int node, int idx, ll diff) {
		if (idx < start || end < idx) return;
		tree[node] += diff;

		if (start != end)
		{
			int mid = (start + end) / 2;
			updateHelper(start, mid, node * 2, idx, diff);
			updateHelper(mid + 1, end, node * 2 + 1, idx, diff);
		}
	}

};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, K; cin >> N >> M >> K;
	vector<ll> arr;
	for (int i = 0; i < N; ++i)
	{
		ll x; cin >> x;
		arr.push_back(x);
	}

	segTree st(arr);

	for (int i = 0; i < M + K; ++i)
	{
		ll a, b, c;
		cin >> a;
		cin >> b >> c;

		if (a == 1)
		{
			st.update(b - 1, c);
		}
		else if (a == 2)
		{
			cout << st.sum(b - 1, c - 1) <<'\n';

		}
	}


	return 0;
}