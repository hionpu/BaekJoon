#include <iostream>   
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int groupWordCount = 0;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		vector<char> group;
		bool isGroupWord = true;
		char prev = ' ';
		for (int pos = 0; pos < s.length(); pos++)
		{
			if (prev == s[pos]) continue;

			if (find(group.begin(), group.end(), s[pos]) == group.end())
			{
				group.push_back(s[pos]);
			}
			else
			{
				isGroupWord = false;
				break;
			}
			prev = s[pos];
		}
		if (isGroupWord) groupWordCount++;
	}

	cout << groupWordCount << '\n';
	return 0;
}