#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <functional>
#include <unordered_set>

using namespace std;

struct edge {
	int target;
	int relation;
};

struct DS {
private:
	int N;
	vector<int> parent;
	vector<int> rank;

public:
	DS(int n) {
		N = n;
		parent.resize(n + 1);
		rank.assign(n + 1, 0);

		for (int i = 1; i <= n; ++i)
		{
			parent[i] = i;
		}
	}

	int getParent(int a) {
		if (parent[a] == a) return a;
		return parent[a] = getParent(parent[a]);
	}

	void join(int a, int b) {
		int rootA = getParent(a);
		int rootB = getParent(b);

		if (rootA == rootB) return;

		if (rank[rootA] > rank[rootB]) parent[rootB] = rootA;
		else
		{
			parent[rootA] = rootB;
			if (rank[rootA] == rank[rootB]) rank[rootB]++;
		}
	}

	int countDisjointSets() {
		unordered_set<int> s;

		for (int i = 1; i <= N; ++i)
		{
			s.insert(getParent(i));
		}

		return s.size();
	}
};



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<int>> enemies(n+1);
	vector<bool> visited(n + 1, false);

	DS ds(n);

	for (int i = 0; i < m; ++i)
	{
		char c;
		int p, q;
		cin >> c >> p >> q;
		if (c == 'F') ds.join(p, q);
		else if (c == 'E')
		{
			enemies[p].push_back(q);
			enemies[q].push_back(p);
		}
	}

	

	for (int i = 1; i <= n; ++i)
	{
		for (int enemy : enemies[i])
		{
			for (int enemy_enemy : enemies[enemy])
			{
				ds.join(i, enemy_enemy);
			}
		}
	}

	cout << ds.countDisjointSets() << '\n';

	return 0;
}