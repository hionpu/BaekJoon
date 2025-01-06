#include <iostream>   
#include <vector>

typedef long long ll;

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M; cin >> N >> M;
	ll count = 0;
	ll pSum = 0;
	vector<ll> freq(M, 0);
	freq[0] = 1;

	for (int i = 0; i < N; i++)
	{
		int a; cin >> a;
		pSum = (pSum + a % M) % M;
		count += freq[pSum];
		freq[pSum]++;
	}

	cout << count << '\n';


	return 0;
}