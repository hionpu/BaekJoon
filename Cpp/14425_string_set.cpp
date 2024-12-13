#include <iostream>   
#include <map>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	map<string, int> dic;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		dic.insert({ s, 0 });
	}
	int count = 0;
	for (int i = 0; i < M; i++)
	{
		string t;
		cin >> t;
		if (dic.find(t) != dic.end()) count++;
	}
	cout << count << '\n';
	return 0;
}