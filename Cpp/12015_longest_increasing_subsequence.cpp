#include <iostream>   
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	vector<int> lis;
	lis.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int a; cin >> a;
		if (lis.empty() || a > lis.back()) lis.push_back(a);
		else
		{
			int index = lower_bound(lis.begin(), lis.end(), a) - lis.begin();
			lis[index] = a;
		}
	}

	cout << lis.size() << '\n';

	return 0;
}