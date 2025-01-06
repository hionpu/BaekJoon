#include <iostream>   
#include <climits>

using namespace std;

const int MAX_N = 100000;
int arr[MAX_N];
int sums[MAX_N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K; cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    
    int ans = INT_MIN;
    for (int i = 0; i < N - K + 1; i++)
    {
        int sum = 0;
        for (int j = 0; j < K; j++)
        {
            sum += arr[i + j];
        }
        ans = max(sum, ans);
    }
    cout << ans << '\n';
    return 0;
}