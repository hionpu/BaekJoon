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
		// val > 0 인 경우는 현재 idx의 풍선을 터트리면 자동으로 front가 한칸 이동하므로 앞으로 이동할 횟수를 -1 해줍니다.
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