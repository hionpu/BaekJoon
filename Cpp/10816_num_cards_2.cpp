#include <iostream>   
#include <map>
#include <string>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	map<int, int> hand;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		int n;
		cin >> n;
		if (hand.find(n) == hand.end()) hand.insert({ n,1 });
		else hand[n] += 1;
	}
	cin >> M;
	for (int i = 1; i <= M; i++)
	{
		int m;
		cin >> m;
		cout << hand[m];
		if (i < M) cout << ' ';
	}
	return 0;
}