#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	auto cmp = [](int a, int b)
		{
			return a < b;
		};

	sort(v.begin(), v.end(), cmp);

	vector<int>::iterator start = v.begin();
	vector<int>::iterator end = v.end() - 1;

	if (*start > 0)
	{
		cout << v[0] << " " << v[1] << '\n';
		return 0;
	}
	else if (*end < 0)
	{
		cout << *(end-1) << " " << *end << '\n';
		return 0;
	}

	int pv = 2e9;
	int s1 = 1e9, s2 = 1e9 + 1;

	while (start < end)
	{
		int currentSum = *start + *end;
		if (abs(currentSum) < pv)
		{
			pv = abs(currentSum);
			s1 = *start;
			s2 = *end;
		}
		if (currentSum < 0) ++start;
		else if (currentSum > 0) --end;
		else break;
	}

	cout << s1 << " " << s2 << '\n';

	return 0;
}