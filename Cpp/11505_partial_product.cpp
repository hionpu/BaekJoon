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
	const ll MOD = 1'000'000'007;

	ll modInverse(ll a) {
		ll result = 1;
		ll exp = MOD - 2;
		while (exp > 0)
		{
			if (exp % 2 == 1) result = (result * a) % MOD;
			a = (a * a) % MOD;
			exp /= 2;
		}
		return result;
	}

	ll prodHelper(int start, int end, int node, int left, int right) {

		if (right < start || end < left) return 1;

		if (left <= start && end <= right) return tree[node];

		int mid = (start + end) / 2;
		return (prodHelper(start, mid, node * 2, left, right) * prodHelper(mid + 1, end, node * 2 + 1, left, right)) % MOD;
	}

	void updateHelper(int start, int end, int node, int idx, ll oldVal, ll newVal) {
		if (idx < start || end < idx) return;

		if (oldVal == 0)
		{
			// If old value was 0, we need to rebuild this subtree
			if (start == end)
			{
				tree[node] = newVal;
			}
			else
			{
				int mid = (start + end) / 2;
				updateHelper(start, mid, node * 2, idx, oldVal, newVal);
				updateHelper(mid + 1, end, node * 2 + 1, idx, oldVal, newVal);
				tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
			}
		}
		else
		{
			// Normal case: use modular inverse
			tree[node] = (tree[node] * modInverse(oldVal) % MOD * newVal) % MOD;

			if (start != end)
			{
				int mid = (start + end) / 2;
				updateHelper(start, mid, node * 2, idx, oldVal, newVal);
				updateHelper(mid + 1, end, node * 2 + 1, idx, oldVal, newVal);
			}
		}
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

		tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
	}

public:
	segTree(vector<ll>& arr) {
		this->n = arr.size();
		this->arr = arr;
		tree.resize(4 * n);
		init(0, n - 1, 1);
	}

	ll prod(int left, int right) {
		return prodHelper(0, n - 1, 1, left, right);
	}

	void update(int idx, ll newVal) {
		ll oldVal = arr[idx];
		arr[idx] = newVal;
		updateHelper(0, n - 1, 1, idx, oldVal, newVal);
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
		int x; cin >> x;
		arr.push_back(x);
	}

	segTree st(arr);
	for (int i = 0; i < M + K; ++i)
	{
		int a, b, c; cin >> a >> b >> c;

		if (a == 1)
		{
			st.update(b - 1, c);
		}
		else if (a == 2)
		{
			cout << st.prod(b - 1, c - 1) << '\n';
		}
	}

	return 0;
}