#include <iostream>   
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K; cin >> N >> K;
    vector<int> coins(N,0);
    int startIdx = N-1;
    int coinCount = 0;
    bool found = false;
    for (int i = 0; i<N; i++) 
    {
        int a; cin >> a;
        coins[i]=a;
        if (a > K && i > 0 && !found)
        {
            startIdx = i;
            found = true;
        }
    }

    for (int i = startIdx; i >= 0; --i)
    {
        if (coins[i] <= K)
        {
            coinCount += K / coins[i];
            K %= coins[i];
        }
        if (K == 0) break;
    }
    cout << coinCount << '\n';
    return 0;
}