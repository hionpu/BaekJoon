#include <iostream>   
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int,int> tiii;
int toms[100][100][100];
int days[100][100][100];
int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

queue<tiii> q;
int M, N, H;
int unripe = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H;
	for (int k = 0; k < H; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				cin >> toms[k][i][j];
				if (toms[k][i][j] == 1)
				{
					days[k][i][j] = 1;
					q.push(make_tuple(k,i, j));
				}
			}
		}
	}

	int lastDay = 0;
	while (!q.empty())
	{
		tiii fr = q.front();
		int z = get<0>(fr);
		int x = get<1>(fr);
		int y = get<2>(fr);
		lastDay = days[z][x][y];
		// if (unripe <= 0) break;
		q.pop();

		for (int n = 0; n < 6; ++n)
		{
			int nz = z + dz[n];
			int nx = x + dx[n];
			int ny = y + dy[n];

			if (nx >= 0 && ny >= 0 && nz >= 0 
				&& nx < N && ny < M  && nz < H 
				&& toms[nz][nx][ny] == 0 && days[nz][nx][ny] == 0)
			{
				toms[nz][nx][ny] = 1;
				days[nz][nx][ny] = days[z][x][y] + 1;
				q.push(make_tuple(nz,nx,ny));
			}
		}
	}

	for (int k = 0; k < H; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (toms[k][i][j] == 0)
				{
					lastDay = 0;
					break;
				}
			}
		}
	}

	cout << lastDay - 1 << '\n';
	return 0;
}