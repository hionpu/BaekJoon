#include <iostream>   
#include <map>
#include <deque>
#include <cmath>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	map<int, int> m;
	deque<int> dq;

	for (int i =1;i<=N;i++)
	{
		int n; cin >> n;
		dq.push_back(i);
		m.insert({ i,n });
	}


	while (!dq.empty())
	{
		int idx = dq.front();
		int val = m[idx];
		cout << idx << ' ';
		bool isPos = val > 0;
		// val > 0 �� ���� ���� idx�� ǳ���� ��Ʈ���� �ڵ����� front�� ��ĭ �̵��ϹǷ� ������ �̵��� Ƚ���� -1 ���ݴϴ�.
		int abNum = isPos ? abs(val)-1 : abs(val);
		dq.pop_front();

		if (dq.empty()) break;

		if (isPos)
		{
			while (abNum--)
			{
				idx = dq.front();
				dq.pop_front();
				dq.push_back(idx);
			}
		}
		else
		{
			while (abNum--)
			{
				idx = dq.back();
				dq.pop_back();
				dq.push_front(idx);
			}
		}
	}


	return 0;
}