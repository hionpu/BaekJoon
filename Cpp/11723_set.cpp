#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <set>
#include <map>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	set<int> s;

	int M; cin >> M;
	unsigned int bitmask = 0;
	map<string, int> commandMap;
	commandMap.insert({ "add", 0 });
	commandMap.insert({ "remove", 1 });
	commandMap.insert({ "check", 2 });
	commandMap.insert({ "toggle", 3 });
	commandMap.insert({ "all", 4 });
	commandMap.insert({ "empty", 5 });


	for (int i = 0; i < M; ++i)
	{
		string command;
		cin >> command;
		int x;
		switch (commandMap[command])
		{
		case (0):
			cin >> x;
			bitmask |= (1 << (x - 1));
			break;
		case (1):
			cin >> x;
			bitmask &= ~(1 << (x - 1));
			break;
		case (2):
			cin >> x;
			if ((bitmask & (1 << (x - 1))) > 0) cout << 1 << '\n';
			else cout << 0 << '\n';
			break;
		case (3):
			cin >> x;
			bitmask ^= (1 << (x - 1));
			break;
		case (4):
			s.clear();
			bitmask = (1 << 20) - 1;
			break;
		case (5):
			bitmask = 0;
			break;
		}
	}

	return 0;
}