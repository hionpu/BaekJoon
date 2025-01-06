#include <iostream>   

using namespace std;
int pSum[2000][2000];
int A_MIN = 2000001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K; cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char color; cin >> color;
            int isWrong = 0;
            if (((i + j) % 2 == 0 && color != 'B') || ((i + j) % 2 == 1 && color == 'B')) isWrong = 1;
            pSum[i][j] = pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1] + isWrong;
        }
    }

    for (int i = K-1; i < N; i++)
    {
        for (int j = K-1; j < M; j++)
        {
            int paint = pSum[i][j] - pSum[i - K][j] - pSum[i][j - K] + pSum[i - K][j - K];
            int minPaint = min(paint, K * K - paint);
            A_MIN = min(A_MIN, minPaint);
        }
    }

    cout << A_MIN << '\n';
    return 0;
}