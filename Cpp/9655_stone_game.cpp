#include <iostream>   

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
	cin >> n;
	if (n % 2 == 0)
	{
		cout << "CY";
	}
	else
	{
		cout << "SK";
	}

    return 0;
}
