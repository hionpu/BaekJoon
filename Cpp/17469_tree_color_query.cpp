#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using uset = unordered_set<int>;

struct DS {
private:
	vector<int> parent;

public:
	DS(int n) {
		parent.resize(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			parent[i] = i;
		}
	}

	int getParent(int a) {
		if (parent[a] == a) return a;
		return parent[a] = getParent(parent[a]);
	}

	void join(int c, int p) {
		int rootC = getParent(c);
		int rootP = getParent(p);

		parent[rootC] = rootP;
	}
};

struct query {
	int command;
	int vertex;
};

void mergeSet(uset& child, uset& parent) {
	if (parent.size() < child.size())
	{
		for (auto& p : parent)
		{
			child.insert(p);
		}
		parent.clear();
		swap(child, parent);
	}
	else
	{
		for (auto& c : child)
		{
			parent.insert(c);
		}
		child.clear();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, Q;
	cin >> N >> Q;
	unordered_map<int, int> edges;
	vector<int> colors(N + 1);
	vector<unordered_set<int>> sets(N + 1);
	DS ds(N);

	edges[1] = 0;
	for (int child = 2; child <= N; ++child)
	{
		int parent; cin >> parent;
		edges[child] = parent;
	}

	for (int i = 1; i <= N; ++i)
	{
		int c; cin >> c;
		colors[i] = c;
	}

	for (int i = 1; i <= N; ++i)
	{
		sets[i].insert(colors[i]);
	}


	vector<query> queries;
	for (int i = 0; i < N + Q - 1; ++i)
	{
		int command, v; cin >> command >> v;
		queries.push_back({ command, v });
	}

	reverse(queries.begin(), queries.end());

	vector<int> ans;

	for (auto& q : queries)
	{
		if (q.command == 1)
		{
			// merge sets in ds
			int child = q.vertex;
			int parent = edges[child];
			// Find the roots of the components for the child and parent nodes.
			int rootC = ds.getParent(child);
			int rootP = ds.getParent(parent);

			// Only perform a merge if they are in different components.
			if (rootC != rootP)
			{
				// Union the two components in the DSU structure.
				ds.join(child, parent);
				// Merge the color sets of the two components.
				// The result will be stored in the set of the new root (rootP).
				mergeSet(sets[rootC], sets[rootP]);
			}
		}
		else if (q.command == 2)
		{
			// find parent of vertex using ds
			int parent = ds.getParent(q.vertex);
			// see what elements are included this parent set in sets
			ans.push_back(sets[parent].size());
		}
	}
	for (int i = ans.size() - 1; i >= 0; --i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}