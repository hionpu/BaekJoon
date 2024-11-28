#include <iostream>   

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    int factorNum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0) factorNum += 1;
        if (factorNum == K)
        {
            cout << i << '\n';
            break;
        }
        if (i == N && factorNum < K) cout << 0 << '\n';
    }

    return 0;
}