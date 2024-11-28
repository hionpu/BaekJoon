#include <iostream>   

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
	cin >> T;

    for (int i = 0; i < T; i++)
    {
        int change;
        cin >> change;
        int Q, D, N, P;
        Q = 0; D = 0; N = 0; P = 0;
        while (change >= 25)
        {
            change -= 25;
            Q++;
        }
        while (change >= 10)
        {
            change -= 10;
            D++;
        }
        while (change >= 5)
        {
            change -= 5;
            N++;
        }
        P = change;

        cout << Q << ' ' << D << ' ' << N << ' ' << P << '\n';
    }

    return 0;
}