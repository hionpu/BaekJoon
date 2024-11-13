#include <iostream>
#include <sstream>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int arr[100001] = { 0 };

	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		arr[i] = arr[i - 1] + k;
	}

	string result;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		result += to_string(arr[b] - arr[a - 1]) + '\n';
	}

	cout << result;
	
	return 0;
}