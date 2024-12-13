#include <iostream> 
#include <string>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int current = 1;
	int i = 0;
	while (true)
	{
		string s = to_string(current);
		if (s.find("666") != std::string::npos) i++;
		if (i == N) break;
		current++;
	}
	cout << current << '\n';
	return 0;
}