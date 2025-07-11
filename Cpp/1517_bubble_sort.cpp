// inversion counting
// segment tree
// bubble sort

#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct segTree {
private:
	int n;
	vector<int> arr;
	vector<int> tree;

	int sumHelper(int start, int end, int node, int left, int right) {
		if (right < start || end < left) return 0;

		if (left <= start && end <= right) return tree[node];

		int mid = (start + end) / 2;
		return sumHelper(start, mid, node * 2, left, right) +
			sumHelper(mid + 1, end, node * 2 + 1, left, right);
	}

	void updateHelper(int start, int end, int node, int idx) {
		if (idx < start || end < idx) return;
		tree[node] += 1;

		if (start != end)
		{
			int mid = (start + end) / 2;
			updateHelper(start, mid, node * 2, idx);
			updateHelper(mid + 1, end, node * 2 + 1, idx);
		}
	}

public:
	segTree(int n) {
		this->n = n;
		arr.resize(n);
		tree.resize(4 * n, 0);
	}

	int getSum(int left, int right) {
		return sumHelper(0, n - 1, 1, left, right);
	}

	void update(int idx) {
		updateHelper(0, n - 1, 1, idx);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	vector<int> arr(N);
	vector<int> vals;
	
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		vals.push_back(arr[i]);
	}
	// Coordinate compression
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());

	segTree st(vals.size());
	long long result = 0;

	// Process from right to left (like the blog approach)
	for (int i = N - 1; i >= 0; --i)
	{
		// Find compressed index
		int idx = lower_bound(vals.begin(), vals.end(), arr[i]) - vals.begin();

		// Count smaller elements that come after current element
		result += st.getSum(0, idx - 1);

		// Add current element
		st.update(idx);
	}


	cout << result << '\n';

	return 0;

}