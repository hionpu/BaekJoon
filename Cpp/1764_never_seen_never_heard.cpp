#include <iostream>   
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M; cin >> N >> M;

	map<string, int> heard;
	vector<string> ans;

	for (int n = 1; n <= N; n++)
	{
		string s; cin >> s;
		heard.insert({ s,0 });
	}

	for (int m = 1; m <= M; m++)
	{
		string t; cin >> t;
		if (heard.find(t) != heard.end()) ans.push_back(t);
	}

	cout << ans.size() << '\n';

	sort(ans.begin(), ans.end());
	for (const auto& name : ans)
	{
		cout << name << '\n';
	}
	return 0;
}