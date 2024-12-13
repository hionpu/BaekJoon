#include <iostream>   
#include <map>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	map<string, int, std::greater<std::string>> att;

	for (int i = 0; i < n; i++)
	{
		string name, io;
		cin >> name >> io;
		if (io == "enter")
		{
			att.insert({ name,0 });
		}
		else
		{
			att.erase(name);
		}
		
	}
	for (auto iter : att)
	{
		cout << iter.first << '\n';
	}
	return 0;
}