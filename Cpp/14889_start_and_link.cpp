#include <iostream>   
#include <algorithm>
#include <climits>

using namespace std;
int N;
int stats[20][20];
int pairSum[20][20];
bool player[20];
int ans;
static void go(int p, int chosen) {
	if (chosen == N / 2)
	{
		int s = 0;
		int l = 0;
		for (int i = 0; i < N - 1; i++)
		{
			if (player[i])
			{
				for (int j = i + 1; j < N; j++)
				{
					if (player[j])
					{
						s += pairSum[i][j];
					}
				}
			}

			if (!player[i])
			{
				for (int j = i + 1; j < N; j++)
				{
					if (!player[j])
					{
						l += pairSum[i][j];
					}
				}
			}
		}
		ans = min(ans, abs(s - l));
		if (ans == 0) return;
	}

	if (p >= N) return;
	if ((N - p) < (N / 2 - chosen)) return;



	player[p] = true;
	go(p + 1, chosen + 1);
	player[p] = false;
	if (ans == 0) return;

	go(p+1, chosen);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	ans = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> stats[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			pairSum[i][j] = stats[i][j] + stats[j][i];
		}
	}


	fill(player, player + N, false);
	player[0] = true;

	go(1, 1);

	cout << ans << '\n';

	return 0;
}