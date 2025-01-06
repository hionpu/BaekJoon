#include <iostream>   
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
int dp[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> left;
	vector<int> right;
	map<int, int> wires;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		wires.insert({ a,b });
		left.push_back(a);
	}

	sort(left.begin(), left.end());

	for (const auto& n : left)
	{
		right.push_back(wires[n]);
	}

	int currentMax = 1;
	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (right[i] > right[j]) dp[i] = max(dp[j] + 1, dp[i]);
		}
		currentMax = max(currentMax, dp[i]);
	}
	cout << N - currentMax << '\n';
	return 0;
}