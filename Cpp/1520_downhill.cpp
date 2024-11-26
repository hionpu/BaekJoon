#include <iostream>   

using namespace std;
int dp[501][501];
int arr[501][501];
int M, N;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int DFS(int x, int y)
{
	if (x == M && y == N) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int newX = x + dx[i];
		int newY = y + dy[i];
		if (newX >= 1 && newY >= 1 && newX <= M && newY <= N)
		{
			if (arr[newX][newY] < arr[x][y])
			{
				dp[x][y] = dp[x][y] + DFS(newX, newY);
			}
		}
	}
	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}

	cout << DFS(1,1) << '\n';
	return 0;
}