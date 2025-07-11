// segment tree
// data structure

#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <functional>

using namespace std;

struct minMax {
	int min;
	int max;
};

struct segTree {
private:
	int n;
	vector<int> arr;
	vector<minMax> tree;
	const int MAX = 100001;
	const int MIN = -1;

	void init(int start, int end, int node) {
		if (start == end)
		{
			tree[node] = { arr[start], arr[start] };
			return;
		}

		int mid = (start + end) / 2;
		init(start, mid, node * 2);
		init(mid + 1, end, node * 2 + 1);

		tree[node] = {
			min(tree[node * 2].min, tree[node * 2 + 1].min),
		max(tree[node * 2].max, tree[node * 2 + 1].max)
		};
	}

	minMax minMaxHelper(int start, int end, int node, int left, int right) {
		if (right < start || end < left) return { MAX, MIN };

		if (left <= start && end <= right) return tree[node];

		int mid = (start + end) / 2;
		minMax leftChild = minMaxHelper(start, mid, node * 2, left, right);
		minMax rightChild = minMaxHelper(mid + 1, end, node * 2 + 1, left, right);
		return { min(leftChild.min, rightChild.min), max(leftChild.max, rightChild.max) };
	}

	void updateHelper(int start, int end, int node, int idx, int newVal) {
		if (idx < start || end < idx) return;

		if (start == end)
		{
			tree[node] = { newVal, newVal };
			return;
		}

		int mid = (start + end) / 2;
		updateHelper(start, mid, node * 2, idx, newVal);
		updateHelper(mid + 1, end, node * 2 + 1, idx, newVal);

		tree[node] = {
			min(tree[node * 2].min, tree[node * 2 + 1].min),
			max(tree[node * 2].max, tree[node * 2 + 1].max)
		};
	}
public:
	segTree(vector<int>& arr) {
		this->n = arr.size();
		this->arr = arr;
		tree.resize(4 * n);

		init(0, n - 1, 1);
	}

	function<minMax(int, int)> getMinMax = [&](int left, int right) { return minMaxHelper(0, n - 1, 1, left, right); };
	function<void(int, int)> swapElement = [&](int idxA, int idxB)
		{
			int oldA = arr[idxA];
			int oldB = arr[idxB];
			swap(arr[idxA], arr[idxB]);
			updateHelper(0, n - 1, 1, idxA, oldB);
			updateHelper(0, n - 1, 1, idxB, oldA);
		};
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;

	while (T--)
	{
		int N, K; cin >> N >> K;

		vector<int> arr(N);
		for (int i = 0; i < N; ++i)
		{
			arr[i] = i;
		}

		segTree st(arr);

		while (K--)
		{
			int Q, A, B; cin >> Q >> A >> B;

			if (Q == 0)
			{
				st.swapElement(A, B);
			}
			else if (Q == 1)
			{
				minMax mm = st.getMinMax(A, B);
				if (mm.min == A && mm.max == B)
				{
					cout << "YES" << '\n';
				}
				else cout << "NO" << '\n';
			}
		}
	}


	return 0;
}