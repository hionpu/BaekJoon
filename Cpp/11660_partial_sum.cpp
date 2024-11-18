#include <iostream>   

using namespace std;
long long sum[1025][1025];
int arr[1025][1025];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			int t;
			cin >> t;

			arr[y][x] = t;
			sum[y][x] = sum[y - 1][x] + sum[y][x - 1] - sum[y - 1][x - 1] + arr[y][x];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sum[y2][x2] - sum[y1 - 1][x2] - sum[y2][x1 - 1] + sum[y1 - 1][x1 - 1] << '\n';
	}
	return 0;
}