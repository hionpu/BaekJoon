#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    if (N == 1)
    {
        cout << 0 << '\n';
        return 0;
    }
        

    vector<int> primes;
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i* i<= N; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i*i; j <= N; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; ++i)
    {
        if (isPrime[i]) primes.push_back(i);
    }

    int start = 0;
    int end = 0;
    int sum = primes[0];

    int ans = 0;

    while (start <= end)
    {
        if (sum < N)
        {
            if (end == primes.size()-1)
                break;
            sum += primes[++end];
        }
        else
        {
            if (sum == N)
            {
                ans++;
            }
            sum -= primes[start++];
        }
    }

    cout << ans << '\n';
    return 0;
}