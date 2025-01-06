#include <iostream>   
#include <vector>

using namespace std;
int N;
int white = 0;
int blue = 0;
const int MAX_N = 128;

static bool okay(vector<vector<int>> paper, int size) {
	bool result = true;
	int first = paper[0][0];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (paper[i][j] != first)
			{
				result = false;
				break;
			}
		}
	}
	return result;
}

static void go(vector<vector<int>> paper, const int size) {
	if (size == 1 || okay(paper, size))
	{
		if (paper[0][0] == 1) blue++;
		else white++;
		return;
	}

	vector<vector<int>> tl(size, vector<int>(size, 0));
	vector<vector<int>> tr(size, vector<int>(size, 0));
	vector<vector<int>> br(size, vector<int>(size, 0));
	vector<vector<int>> bl(size, vector<int>(size, 0));

	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			tl[i][j] = paper[i][j];
		}
	}
	for (int i = size/2; i < size ; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			tr[i-size/2][j] = paper[i][j];
		}
	}
	for (int i = size / 2; i < size ; i++)
	{
		for (int j = size / 2; j < size; j++)
		{
			br[i- size / 2][j- size / 2] = paper[i][j];
		}
	}
	for (int i = 0; i < size / 2; i++)
	{
		for (int j = size / 2; j < size; j++)
		{
			bl[i][j- size / 2] = paper[i][j];
		}
	}

	go(tl, size / 2);
	go(tr, size / 2);
	go(br, size / 2);
	go(bl, size / 2);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	vector<vector<int>> paper(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> paper[i][j];
		}
	}

	go(paper, N);

	cout << white << '\n' << blue;

	return 0;
}