#include <iostream>   

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int pos = 0;
	int numAlph = 0;
	string alphs[7] = { "c=", "c-", "d-", "lj", "nj", "s=", "z=" };
	while (pos < s.length())
	{
		if (pos < s.length() - 1)
		{

			string two = string(1, s[pos]) + string(1, s[pos + 1]);
			bool twoMatched = false;
			for (int i = 0; i < 7; i++)
			{
				if (two == (alphs[i]))
				{
					numAlph++;
					pos += 2;
					twoMatched = true;
					break;
				}
			}
			if (twoMatched) continue;
		}

		if (pos < s.length() - 2)
		{
			string three = string(1, s[pos]) + string(1, s[pos + 1]) + string(1, s[pos + 2]);
			if (three == "dz=")
			{
				numAlph++;
				pos += 3;
				continue;
			}
		}
		numAlph++;
		pos++;
		
	}

	cout << numAlph << '\n';
	return 0;
}