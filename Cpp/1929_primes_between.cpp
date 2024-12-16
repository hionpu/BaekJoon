#include <iostream>   
#include <cmath>
#include <set>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M, N;
    cin >> M >> N;

    int maxP = sqrt(N);
    set<int> sieve;
    for (int i = 2; i <= N; i++)
    {
        sieve.insert(i);
    }

    for (int i = 2; i <= maxP; i++)
    {
        if (sieve.find(i) != sieve.end())
        {
            int k = 2;
            while (i * k <= N)
            {
                sieve.erase(i * k);
                k++;
            }
        }
    }

    for (auto& prime : sieve)
    {
        if (prime >= M) cout << prime << '\n';
    }

    return 0;
}