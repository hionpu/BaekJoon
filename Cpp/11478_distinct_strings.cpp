#include <iostream>   
#include <set>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	set<string> t;

	cin >> s;

	for (int len = 1; len <= s.length(); len++)
	{
		for (int pos = 0; pos <= s.length()-len+1; pos++)
		{
			t.insert(s.substr(pos, len));
		}
	}
	t.erase("");
	cout << t.size() << '\n';

	return 0;
}