#include <iostream>   
#include <vector>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N,M;
	map<int, int> arr;
	vector<int> ans;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int n; cin >> n;
		arr.insert({ n,0 });
	}
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int m; cin >> m;

		ans.push_back(arr.find(m) == arr.end() ? 0 : 1);
	}

	for (auto m : ans)
	{
		cout << m << ' ';
	}

	return 0;
}