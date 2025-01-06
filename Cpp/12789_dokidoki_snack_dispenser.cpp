#include <iostream>  
#include <queue>
#include <stack>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	queue<int> q;
	stack<int> st;
	while (N--)
	{
		int n; cin >> n;
		q.push(n);
	}

	int index = 1;
	bool result = true;
	while (true)
	{
		bool poped = false;
		if (q.empty() && st.empty())
		{
			result = true;
			break;
		}
		// fail
		if (q.empty() && st.top() != index)
		{
			result = false;
			break;
		}


		if (!q.empty() && q.front() == index)
		{
			q.pop();
			poped = true;
			index++;

		}

		if (!st.empty() && st.top() == index)
		{
			st.pop();
			poped = true;
			index++;

		}

		if (!poped)
		{
			st.push(q.front());
			q.pop();
		}
	}
	string output = result ? "Nice" : "Sad";
	cout << output << '\n';
	return 0;
}