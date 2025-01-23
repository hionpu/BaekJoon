#include <iostream>   
#include <vector>
#include <climits>

using namespace std;

const int NMAX = 100;
int mems[NMAX + 1];
int costs[NMAX + 1];
int dp[NMAX + 1][NMAX * NMAX + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int totalMem = 0;
	int totalCost = 0;
	int N, M; cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> mems[i];
		totalMem += mems[i];
	}

	dp[0][0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> costs[i];
		totalCost += costs[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j <= totalCost; ++j)
		{
			if (j - costs[i] >= 0)
			{
				dp[i][j] = max(dp[i-1][j], dp[i - 1][j - costs[i]] + mems[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	for (int i = 0; i <= totalCost;++i)
	{
		if (dp[N][i] >= M)
		{
			cout << i << endl;
		break;
		}
	}

	return 0;
}