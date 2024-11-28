#include <iostream>   
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i <= 1000; i++)
    {
        bool isPrime = true;
        for (auto prime : primes)
        {
            isPrime = isPrime && i % prime != 0;
        }
        if (isPrime) primes.push_back(i);
    }

    int N;
    cin >> N;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        if (find(primes.begin(), primes.end(), n) != primes.end())
        {
            count++;
        }
        
    }

    cout << count << '\n';
    return 0;
}
   