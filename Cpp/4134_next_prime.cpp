#include <iostream>   
#include <cmath>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        long long n;
        cin >> n;
        if (n <= 2) cout << 2 << '\n';
        else if (n == 3) cout << 3 << '\n';
        else if (n <=5) cout << 5 << '\n';
        else
        {
            while (true)
            {
                bool found = true;
                for (long long i = 2; i <= sqrt(n); i++)
                {
                    if (n % i == 0)
                    {
                        found = false;
                        break;
                    }
                }
                if (found) break;
                n++;
            }
            cout << n << '\n';
        }
    }

    return 0;
}