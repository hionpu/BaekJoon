#include <iostream>   

using namespace std;
int N;
bool columns[15];
bool diag1[29];
bool diag2[29];
int ans;
static void nqueen(int row) {
	if (row == N)
	{
		ans++;
		return;
	}
	for (int col = 0; col < N; col++)
	{
		if (!columns[col] && !diag1[row + col] && !diag2[row - col + N - 1])
		{
			columns[col] = true;
			diag1[row + col] = true;
			diag2[row - col + N - 1] = true;
			
			nqueen(row + 1);

			columns[col] = false;
			diag1[row + col] = false;
			diag2[row - col + N - 1] = false;
		}
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	ans = 0;
	fill(columns, columns + N, false);
	fill(diag1, diag1 + (2 * N - 1), false);
	fill(diag2, diag2 + (2 * N - 1), false);

	nqueen(0);

	cout << ans << '\n';
	return 0;
}