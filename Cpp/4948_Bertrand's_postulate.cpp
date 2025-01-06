#include <iostream>   
#include <set>
#include <cmath>

using namespace std;

const int MAX_N = 246912;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    set<int> sieve;

    for (int i = 2; i <= MAX_N; i++)
    {
        sieve.insert(i);
    }

    for (int i = 2; i <= sqrt(MAX_N); i++)
    {
        if (sieve.find(i) != sieve.end())
        {
            int k = 2;
            while (k*i <= MAX_N)
            {
                sieve.erase(k * i);
                k++;
            }
        }
    }

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0) break;

        int count = 0;
        for (const auto& p : sieve)
        {
            if (p <= 2 * n && p > n) count++;
            else if (p > 2 * n) break;
        }
        cout << count << '\n';
    }

    return 0;
}