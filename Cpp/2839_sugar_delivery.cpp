#include <iostream>   

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int minPack = N;
	for (int i = 0; i <= N / 3+1; i++)
	{
		for (int j = 0; j <= N / 5+1; j++)
		{
			if (3 * i + 5 * j == N)
			{
				minPack = min(minPack, i + j);
			}
		}
	}
	if (minPack == N) minPack =-1;
	cout << minPack << '\n';
	return 0;
}