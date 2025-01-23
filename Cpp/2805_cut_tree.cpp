#include <iostream>   
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> trees(N, 0);
	int maxHeight = 0;
	int currentMax = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> trees[i];
		maxHeight = max(maxHeight, trees[i]);
	}

	int left = 0, right = maxHeight;

	while (left <= right)
	{
		int mid = (right + left) / 2;
		long long sumCut = 0;
		bool isOver = false;
		for (int i = 0; i < N; i++)
		{
			sumCut += trees[i] - mid > 0 ? trees[i] - mid : 0;
			if (sumCut >= M)
			{
				isOver = true;
				break;
			}
		}

		if (isOver)
		{
			currentMax = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << currentMax << '\n';
	return 0;
}