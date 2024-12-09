#include <iostream>   
#include <string>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	
		cin >> N;
		bool found = false;
		string strN = to_string(N);
		int len = strN.length();
		int minSum = N;
		int start = max(1,N - len * 9);
		for (int i = start; i < N; i++)
		{
			int sum = i;
			int temp = i;

			while (temp > 0)
			{
				sum += temp % 10;
				temp /= 10;
			}
			if (sum == N)
			{
				minSum = i;
				found = true;
				break; 
			}

		}
		cout << (found?minSum:0) << '\n';

	
	return 0;
}