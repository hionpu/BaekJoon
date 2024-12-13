#include <iostream>   
#include <map>
#include <string>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	map<string, int> nameToNum;
	map<int, string> numToName;
	for (int i = 1; i <= N; i++)
	{
		string name;
		cin >> name;
		nameToNum.insert({ name, i });
		numToName.insert({ i, name });
	}

	for (int i = 1; i <= M; i++)
	{
		string s;
		int num = 0;
		cin >> s;
		if (isdigit(s[0]))
		{
			num = stoi(s);
			cout << numToName[num] << '\n';
		}
		else
		{
			cout << nameToNum[s] << '\n';
		}

	}

	return 0;
}