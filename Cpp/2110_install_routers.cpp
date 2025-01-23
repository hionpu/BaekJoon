#include <iostream>   
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, C;
	cin >> N >> C;

	vector<int> locations(N);

	for (int i = 0; i < N; i++)
	{
		cin >> locations[i];
	}

	sort(locations.begin(), locations.end());

	int currentMax = *(locations.end() - 1) - *locations.begin();
	int left = 1, right = currentMax;

	while (left <= right)
	{
		int mid = (right + left) / 2;
		int numRouter = C - 1;
		bool isRouterZero = false;
		int lastInstalled = 0;
		for (int i = 1; i < N; i++)
		{
			if (locations[i] - locations[lastInstalled] >= mid)
			{
				lastInstalled = i;
				numRouter -= 1;
				if (numRouter == 0)
				{
					isRouterZero = true;
					break;
				}
			}
		}

		if (isRouterZero)
		{
			currentMax = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << currentMax << '\n';
	return 0;
}