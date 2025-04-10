#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> adj;
unordered_map<int, int> parents;

void dfs(int node) {
	for (auto& next : adj[node])
	{
		if (parents[next] == 0)
		{
			parents[next] = node;
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	

	for (int i = 0; i < N - 1; ++i)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= N; ++i)
	{
		cout << parents[i] << '\n';
	}

	return 0;
}