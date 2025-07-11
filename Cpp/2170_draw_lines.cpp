#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct seg {
	int s;
	int e;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	vector<seg> segs(N);
	for (int i = 0; i < N; ++i)
	{
		int s, e; cin >> s >> e;
		segs[i] = { s,e };
	}

	sort(segs.begin(), segs.end(), [](seg a, seg b) -> bool
		{
			return a.s < b.s;
		});

	int ans = 0;
	int start = -1'000'000'001;
	int end = -1'000'000'001;

	for (int i = 0; i < N; ++i)
	{
		int ns = segs[i].s;
		int ne = segs[i].e;
		if (end < ns)
		{
			ans += ne - ns;
			start = ns;
			end = ne;
		}
		else if (end < ne)
		{
			ans += ne - end;
			end = ne;
		}
	}
	cout << ans << '\n';
	return 0;
}