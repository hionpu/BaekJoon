#include <iostream>   

using namespace std;

bool arr[50][50];
int N, M;

bool white[8][8] = {
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0}
};

bool black[8][8] = {
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = s[j] == 'B' ? true : false;
		}
	}

	int currentmin = 32;
	for (int n = 0; n <= N - 8; n++)
	{
		for (int m = 0; m <= M - 8; m++)
		{
			int forblack = 0, forwhite = 0;
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					//forwhite
					if (arr[n + i][m + j] != white[i][j]) forwhite++;

					//forblack
					if (arr[n + i][m + j] != black[i][j]) forblack++;
				}
			}
			currentmin = min(currentmin, min(forwhite, forblack));
		}
	}

	cout << currentmin << '\n';
	return 0;
}