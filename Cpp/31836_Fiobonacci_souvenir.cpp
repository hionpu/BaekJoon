#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N; cin >> N;
    int r = N % 3;
    int d = N / 3;
    switch (r)
    {
    case 0:
        cout << d << '\n';
        for (int i = 3; i <= N; i+=3)
        {
            cout << i << ' ';
        }
        cout << '\n';
        cout << 2 * d << '\n';
        for (int i = 1; i <= N; ++i)
        {
            if (i % 3 != 0) cout << i << ' ';
        }
        cout << '\n';
        break;
    case 1:
        cout << d << '\n';
        for (int i = 4; i <= N; i += 3)
        {
            cout << i << ' ';
        }
        cout << '\n';
        cout << 2 * d << '\n';
        for (int i = 1; i <= N; ++i)
        {
            if (i % 3 != 1) cout << i << ' ';
        }
        cout << '\n';

        break;
    case 2:
        cout << d+1 << '\n';
        cout << 1 << ' ';
        for (int i = 5; i <= N; i += 3)
        {
            cout << i << ' ';
        }
        cout << '\n';
        cout << 2 * d +1<< '\n';
        cout << 2 << ' ';
        for (int i = 3; i <= N; ++i)
        {
            if (i % 3 != 2) cout << i << ' ';
        }
        cout << '\n';

        break;
    }
    return 0;
}