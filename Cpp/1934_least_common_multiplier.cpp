#include <iostream>   

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        int A,B,a, b;
        cin >> a >> b;
        A = max(a,b);
        B = min(a,b);
        int lcd = 1;

        while (true)
        {
            if (A%B == 0) break;
            int temp = A - B;
            A = max(temp, B);
            B = min(temp, B);
        }

        cout << a * b / B << '\n';

    }

    return 0;
}