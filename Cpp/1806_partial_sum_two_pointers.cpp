#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N, S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    vector<int> arr(N , 0);
    
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    
   
    int start = 0;
    int end = 0;

    int sum = arr[0];
    int len = N + 1;

    while (start <N)
    {
        if (sum < S)
        {
            if (end == N - 1) break;
            sum += arr[++end];
        }
        else
        {
            len = min(len, end - start + 1);
            if (len == 1) break;
            sum -= arr[start++];
        }
    }

    if (len == N + 1) len = 0;

    cout << len << '\n';

    return 0;
}