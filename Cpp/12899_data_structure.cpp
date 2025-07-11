#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct segTree {
private:
	vector<int> tree;
	int NMAX = 2'000'000;
	void insertHelper(int start, int end, int node, int x) {
		if (start == end)
		{
			tree[node]++;
			return;
		}

		int mid = (start + end) / 2;
		if (x <= mid) insertHelper(start, mid, node * 2, x);
		else insertHelper(mid + 1, end, node * 2 + 1, x);

		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}

	int deleteHelper(int start, int end, int node, int rank) {
		if (start == end)
		{
			tree[node]--;
			return start;
		}

		int mid = (start + end) / 2;
		int ans = 0;
		if (rank <= tree[node * 2])
		{
			ans = deleteHelper(start, mid, node * 2, rank);

		}
		else ans = deleteHelper(mid + 1, end, node * 2 + 1, rank - tree[node * 2]);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
		return ans;
	}

public:
	segTree() {
		tree.resize(1 << 22);
	}

	void insert(int x) {
		return insertHelper(0, NMAX - 1, 1, x);
	}

	int deleteRank(int rank) {
		return deleteHelper(0, NMAX - 1, 1, rank);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	segTree st;
	while (N--)
	{
		int T, X; cin >> T >> X;
		if (T == 1)
		{
			st.insert(X - 1);
		}
		else if (T == 2)
		{
			cout << st.deleteRank(X) +1 << '\n';
		}
	}
	return 0;
}
