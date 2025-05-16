#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
const int INF = 100000007;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, t, m; cin >> n >> t >> m;
	int start, end; cin >> start >> end;
	vector<vector<int>> dist(t + 1, vector<int>(n));
	for (int i = 0; i < n; ++i) dist[0][i] = INF;
	dist[0][start] = 0;

	for (int T = 1; T <= t; ++T)
	{
		for (int i = 0; i < n; ++i) dist[T][i] = dist[T - 1][i];
		for (int i = 0; i < m; ++i)
		{
			int s, e, d; cin >> s >> e >> d;
			dist[T][e] = min(dist[T][e], dist[T - 1][s] + d);
			dist[T][s] = min(dist[T][s], dist[T - 1][e] + d);
		}
	}

	if (dist[t][end] == INF) cout << -1 << '\n';
	else cout << dist[t][end] << '\n';

	return 0;
}