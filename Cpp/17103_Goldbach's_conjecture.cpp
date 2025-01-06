#include <iostream>   
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1'000'000;
bool sieve[MAX_N+1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fill(begin(sieve), end(sieve), true);

	sieve[0] = false;
	sieve[1] = false;

	for (int i = 2; i <= sqrt(MAX_N); i++)
	{
		if (sieve[i])
		{
			for (int k = 2; k * i <= MAX_N; k++)
			{
				sieve[k * i] = false;
			}
		}
	}

	vector<int> primes;

	for (int i = 0; i <= MAX_N; i++)
	{
		if (sieve[i]) primes.push_back(i);
	}

	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;
		int count = 0;

		int left = 0;
		int right = (int)primes.size() - 1;

		while (left <= right)
		{
			int sum = primes[left] + primes[right];
			if (sum == n)
			{
				count++;
				left++;
				right--;
			}
			else if (sum < n)
			{
				left++;
			}
			else
			{
				right--;
			}
		}

		cout << count << '\n';
	}

	return 0;
}