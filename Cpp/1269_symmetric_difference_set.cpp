#include <iostream>   
#include <set>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	set<int> diffSet;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		diffSet.insert(x);
	}

	for (int j = 1; j <= m; j++)
	{
		int y;
		cin >> y;
		if (diffSet.find(y) != diffSet.end())
		{
			diffSet.erase(y);
		}
		else
		{
			diffSet.insert(y);
		}
	}

	cout << diffSet.size() << '\n';

	return 0;
}