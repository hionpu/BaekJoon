#include <iostream>   
#include <queue>
#include <vector>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

auto comparator = [](pii a, pii b)
	{
		return a.second > b.second;
	};

priority_queue<pii, vector<pii>, decltype(comparator)> pq(comparator);

int costs[100001];
int dx[2] = { -1, 1 };

int N, K;

void bfs(int start) {
	costs[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		pii t = pq.top();
		int node = t.first;
		int cost = t.second;

		pq.pop();

		int next = -1;
		int totalCost = -1;
		for (int i = 0; i < 2; ++i)
		{
			next = node + dx[i];
			if (next < 0 || next >100000) continue;

			totalCost = cost + 1;
			if (costs[next] > totalCost)
			{
				costs[next] = totalCost;
				pq.push({ next,totalCost });
			}
		}
		next = 2 * node;
		totalCost = cost;
		while (next <= 100000 && next != 0)
		{
			if (costs[next] > totalCost)
			{
				costs[next] = totalCost;
				pq.push({ next, totalCost });
			}
			next *= 2;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	fill(costs, costs + 100001, INT_MAX);

	bfs(N);

	cout << costs[K] << '\n';

	return 0;
}