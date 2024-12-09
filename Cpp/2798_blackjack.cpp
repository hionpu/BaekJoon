#include <iostream>   

using namespace std;
int cards[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> cards[i];
    int minDiff = M;
    for (int i = 0; i < N-2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                int sum = cards[i] + cards[j] + cards[k];
                if (sum > M) continue;
                if (M-sum < minDiff) minDiff = M-sum;
            }
        }
    }
    cout << M - minDiff << '\n';
    return 0;
}