#include <iostream>   

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll N, k;
	cin >> N >> k;

	ll left = 1, right = N * N, ans = 1;;
	while (left <= right)
	{
		ll currentCount = 0;
		ll mid = (left + right) / 2;
		for (int i = 1; i <= N; i++)
		{
			currentCount += min(N, mid / i);
		}
		
		if (currentCount < k)
		{
			left = mid + 1;
		}
		else
		{
			ans = mid;
			right = mid - 1;
		}
	}

	cout << ans << '\n';
	return 0;
}