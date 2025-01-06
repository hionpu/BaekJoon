#include <iostream>   

using namespace std;

typedef long long ll;
const int MAX_N = 100000;
int dists[MAX_N - 1];
int prices[MAX_N];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> dists[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> prices[i];
	}

	ll price = prices[0];
	ll total = price*dists[0];

	for (int i = 1; i < N-1; i++)
	{
		if (prices[i] < price)
		{
			price = prices[i];
		}
		total += price * dists[i];
	}

	cout << total << '\n';
	return 0;
}