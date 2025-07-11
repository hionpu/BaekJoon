#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	auto comp = [](ll a, ll b) -> bool
		{
			return a > b;
		};


	int T; cin >> T;

	for (int test = 0; test < T; ++test)
	{
		priority_queue<ll, vector<ll>, decltype(comp)> pq(comp);
		int K; cin >> K;

		if (K == 1)
		{
			int s; cin >> s;
			cout << s << '\n';
			continue;
		}

		for (int i = 0; i < K; ++i)
		{
			int s; cin >> s;
			pq.push(s);
		}

		ll ans = 0;
		while (pq.size() > 1)
		{
			ll first = pq.top(); pq.pop();
			ll second = pq.top(); pq.pop();

			ll combined = first + second;
			ans += combined;
			pq.push(combined);
		}

		cout << ans << '\n';
	}

	return 0;
}