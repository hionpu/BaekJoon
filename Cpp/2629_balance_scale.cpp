#include <iostream>   
#include <cmath>

using namespace std;
const int WMAX = 30;
const int BMAX = 40000;

int weights[WMAX + 1];
bool balls[BMAX + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int W, B;
	int weightMax = 0;
	cin >> W;
	balls[0] = true;
	for (int i = 1; i <= W; ++i)
	{
		int w; cin >> w;
		weights[i] = w;
		weightMax += w;
	}
	for (int i = 1; i <= W; ++i)
	{
		int w = weights[i];
		for (int j = weightMax; j >=0 ; --j)
		{
			if (balls[j]) balls[j + w] = true;
		}
		for (int j = 0; j <= weightMax; ++j)
		{
			if (balls[j]) balls[abs(j - w)] = true;
		}

	}
	cin >> B;
	for (int i = 1; i <= B; ++i)
	{
		int b; cin >> b;
		balls[b] ? cout << "Y " : cout << "N ";
	}
	return 0;
}