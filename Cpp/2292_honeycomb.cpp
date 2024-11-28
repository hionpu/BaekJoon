#include <iostream>   

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int d = 0;
	while (true)
	{
		if (3 * d * d - 3 * d + 1 < N && 3 * d * d + 3 * d + 1 >= N) break;
		d++;
	}
	if (N == 1) cout << 1 << '\n';
	else
	{
		cout << d +1 << '\n';
	}
	return 0;
}