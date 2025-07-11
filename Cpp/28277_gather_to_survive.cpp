#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <set>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, Q;
	cin >> N >> Q;

	vector<set<int>> sets(N);

	for (int i = 0; i < N; ++i)
	{
		int n; cin >> n;
		for (int j = 0; j < n; ++j)
		{
			int s; cin >> s;
			sets[i].insert(s);
		}
	}

	for (int i = 0; i < Q; ++i)
	{
		int command; cin >> command;
		if (command == 1)
		{
			int a, b; cin >> a >> b;
			set<int>& A = sets[--a];
			set<int>& B = sets[--b];

			if (A.size() >= B.size())
			{
				for (int s : B)
				{
					A.insert(s);
				}
				B.clear();
			}
			else
			{
				for (int s : A)
				{
					B.insert(s);
				}
				A.clear();
				swap(A, B);
			}
		}
		else if (command == 2)
		{
			int a; cin >> a;
			cout << sets[--a].size() << '\n';
		}
	}

	return 0;
}