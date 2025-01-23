#include <iostream>   
#include <vector>
#include <climits>

using namespace std;

const int N_MAX = 501;
int dp[N_MAX][N_MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;

	vector<pair<int, int>> mats(N+1, make_pair(0,0));

	for (int i = 1; i <= N; ++i)
	{
		int r, c; cin >> r >> c;
		mats[i] = make_pair(r, c);
		dp[i][i] = 0;
	}

	for (int len = 2; len <= N; ++len)
	{
		for (int i = 1; i <= N - len + 1; ++i)
		{
			int j = i + len - 1;
			dp[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mats[i].first * mats[k].second* mats[j].second);
			}
		}
	}

	cout << dp[1][N] << '\n';


	return 0;
}