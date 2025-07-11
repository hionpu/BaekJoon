#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;



struct cow {
	int s;
	int e;
};

auto cowComp = [](cow x, cow y) -> bool
	{
		if (x.e == y.e) return x.s > y.s;
		return x.e > y.e; // Priority queue is max heap by default, so reverse for min ending time
	};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int C, N; cin >> C >> N;

	multiset<int> ch;
	vector<cow> cw;
	priority_queue<cow, vector<cow>, decltype(cowComp)> pq(cowComp);

	for (int i = 0; i < C; ++i)
	{
		int t; cin >> t;
		ch.insert(t);
	}

	for (int i = 0; i < N; ++i)
	{
		int a, b; cin >> a >> b;
		cow c = { a,b };
		pq.push(c);
	}

	int ans = 0;

	while (!pq.empty())
	{
		cow top = pq.top();
		pq.pop();

		auto it = ch.lower_bound(top.s);

		if (it != ch.end() && *it <= top.e)
		{
			ch.erase(it);
			ans++;
		}


	}

	cout << ans << '\n';

	return 0;
}