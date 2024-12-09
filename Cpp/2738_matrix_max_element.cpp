#include <iostream>   

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int max, r, c;
	r = 0;
	c = 0;
	max = -1;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			int n; cin >> n;
			if (n > max)
			{
				max = n;
				r = i; c = j;
			}

		}
	}
	cout << max << '\n' << r << ' ' << c << '\n';


	return 0;
}