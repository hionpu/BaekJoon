#include <iostream>   
#include <algorithm>
#include <climits>

using namespace std;
int N;
int nums[11];
int ops[4];
int opArr[10];

int result_min;
int result_max;

static int oper(int a, int b, int oper) {
	switch (oper)
	{
	case 0: return a + b;
	case 1: return a - b;
	case 2: return a * b;
	case 3: return a / b;
	}
}

static bool go(int z) {
	if (z == N-1)
	{
		int result = nums[0];
		for (int i = 1; i < N; i++)
		{
			result = oper(result, nums[i], opArr[i - 1]);
		}
		result_min = min(result_min, result);
		result_max = max(result_max, result);
		return true;
	}

	for (int i = 0; i <= 3; i++)
	{
		if (ops[i] > 0)
		{
			ops[i]--;
			opArr[z] = i;
			go(z + 1);
			ops[i]++;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	result_min = INT_MAX;
	result_max = INT_MIN;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> nums[i];
	for (int i = 0; i < 4; i++) cin >> ops[i];
	fill(opArr, opArr + 10, -1);
	go(0);

	cout << result_max << '\n' << result_min << '\n';
	return 0;
}