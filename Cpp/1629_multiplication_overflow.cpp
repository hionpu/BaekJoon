#include <iostream>   
#include <cmath>

using namespace std;
long long int A, B, C;
long long int twos[32];
long long int residues[32];
long long int maxPow;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B >> C;
	long long int ans = 1;
	A = A % C;

	int i = 0;
	long long int n = 1;
	long long int residue = A;
	while (n <= B)
	{
		twos[i] = n;
		residues[i] = residue % C;
		residue = residue * residue % C;
		n = n * 2;
		maxPow = i++;
	}

	while (B > 0 && maxPow >= 0)
	{
		if (twos[maxPow] <= B)
		{
			ans = (ans * residues[maxPow]) % C;
			B -= twos[maxPow];
		}
		maxPow--;
	}

	cout << ans << '\n';
	return 0;
}
