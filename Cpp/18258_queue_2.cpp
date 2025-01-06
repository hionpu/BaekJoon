#include <iostream>   
#include <map>
#include <queue>


using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	map<string, int> command;
	command.insert({ "push", 1 });
	command.insert({ "pop",2 });
	command.insert({ "size",3 });
	command.insert({ "empty",4 });
	command.insert({ "front",5 });
	command.insert({ "back",6 });

	queue<int> q;

	while (N--)
	{
		string s; cin >> s;

		switch (command[s])
		{
		case 1:
			int x; cin >> x;
			q.push(x);
			break;
		case 2:
			if (q.empty()) cout << -1 << '\n';
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
			break;
		case 3:
			cout << q.size() << '\n';
			break;
		case 4:
			cout << q.empty() << '\n';
			break;
		case 5:
			if (q.empty()) cout << -1 << '\n';
			else
			{
				cout << q.front() << '\n';
			}
			break;
		case 6:
			if (q.empty()) cout << -1 << '\n';
			else
			{
				cout << q.back() << '\n';
			}
			break;
		}
	}

	return 0;
}