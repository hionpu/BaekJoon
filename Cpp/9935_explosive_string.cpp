#include <iostream>   
#include <stack>
#include <string>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s, e; cin >> s >> e;

	int exSize = e.size();
	stack<char> st;

	string revE = "";
	for (int i = e.size() - 1; i >= 0; --i)
	{
		revE += e[i];
	}

	int i = 0;
	while (i < s.size())
	{
		st.push(s[i++]);
		while (st.size() >= exSize)
		{
			string tail = "";
			for (int j = 0; j < exSize; j++)
			{
				tail += st.top();
				st.pop();
			}
			if (tail != revE)
			{
				for (int k = e.size() - 1; k >= 0; --k)
				{
					st.push(tail[k]);
				}

				break;
			}
		}

	}

	if (st.empty()) cout << "FRULA" << endl;
	else
	{
		stack<char> resultStack;
		string result = "";
		while (!st.empty())
		{
			resultStack.push(st.top());
			st.pop();
		}
		while (!resultStack.empty())
		{
			result += resultStack.top();
			resultStack.pop();
		}
		cout << result << endl;
	}

	return 0;
}