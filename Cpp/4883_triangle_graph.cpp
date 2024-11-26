#include <iostream>   

using namespace std;
int dp[100001][4];
int map[100001][4];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int numCase = 1;
	while (true)
	{
		cin >> N;
		if (N == 0) break;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				cin >> map[i][j];
			}
		}
		dp[1][1] = 2e9;
		dp[1][2] = map[1][2];
		dp[1][3] = map[1][2] + map[1][3];

		for (int x = 2; x <= N; x++)
		{
			dp[x][1] = min(dp[x - 1][1], dp[x - 1][2]) + map[x][1];
			dp[x][2] = min({ dp[x - 1][1], dp[x - 1][2], dp[x - 1][3], dp[x][1] }) + map[x][2];
			dp[x][3] = min({ dp[x][2], dp[x - 1][2], dp[x - 1][3] }) + map[x][3];
 		}

		cout << numCase++ << ". " << dp[N][2] << '\n';


	}



	return 0;
}