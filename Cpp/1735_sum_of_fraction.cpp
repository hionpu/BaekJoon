#include <iostream>   

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int A, B, a, b,c,d;
	cin >> c >> a >> d >> b;
	A = max(a, b);
	B = min(a, b);

	while (true)
	{
		if (A % B == 0) break;
		int temp = A - B;
		A = max(temp, B);
		B = min(temp, B);
	}

	int deno = a * b / B;
	int numer = c * b / B + d * a / B;

	int C, D;
	C = max(deno, numer);
	D = min(deno, numer);

	while (true)
	{
		if (C % D == 0) break;
		int temp = C - D;
		C = max(temp, D);
		D = min(temp, D);
	}
	
	cout << numer/D << ' ' << deno/D << '\n';



	return 0;
}