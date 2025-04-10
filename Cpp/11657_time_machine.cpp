#include <iostream>   
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Edge{
	int A, B, C;
};

const int NMAX = 500;
const int MMAX = 6000;
const ll INF = 1e18;

int N;
vector<Edge> edges;
ll costs[NMAX + 1];



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M; cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int A, B, C; cin >> A >> B >> C;
		edges.push_back({ A,B,C });
	}

	for (int i = 1; i <= N; ++i)
	{
		costs[i] = INT_MAX;
	}

	costs[1] = 0;

	for (int i = 0; i < N - 1; ++i)
	{
		for (const auto& edge : edges)
		{
			if (costs[edge.A] != INT_MAX && costs[edge.A] + edge.C < costs[edge.B])
			{
				costs[edge.B] = costs[edge.A] + edge.C;
			}
		}
	}

	for (const auto& edge : edges)
	{
		if (costs[edge.A] != INT_MAX && costs[edge.A] + edge.C < costs[edge.B])
		{
			cout << -1 << '\n';
			return 0;
		}
	}

	for (int i = 2; i <= N; ++i)
	{
		if (costs[i] == INT_MAX) cout << -1 << '\n';
		else cout << costs[i] << '\n';
	}

	return 0;
}