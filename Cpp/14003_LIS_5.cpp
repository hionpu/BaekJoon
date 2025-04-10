#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

const int NMAX = 1'000'000;
int N;
int dp[NMAX];
int prev[NMAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // tails will store the last element of the smallest subsequence of each length.
	// 가장 작은 증가율을 가지도록: tails[i] = 길이 i+1인 수열이면서 i+1번째 수까지 고려했을 때 마지막 수가 가장 작을 때의 마지막 수
    vector<int> tails;

    // pos[i] stores the index in 'arr' of the last element of a subsequence with length i+1.
	// tails[i] = arr[pos[i]]
    vector<int> pos;
    // prev[i] will help in reconstructing the sequence by storing the predecessor index for arr[i]
    vector<int> prev(n, -1);
    // dp[i] stores the length of the LIS ending at i (for reconstruction use)
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++)
    {
        vector<int>::iterator it = lower_bound(tails.begin(), tails.end(), arr[i]);
        int idx = it - tails.begin();

        if (it == tails.end())
        {
            tails.push_back(arr[i]);
            pos.push_back(i);
        }
        else
        {
            *it = arr[i];
            pos[idx] = i;
        }

        dp[i] = idx + 1;

        if (idx > 0) prev[i] = pos[idx - 1];
    }

    int lisLength = tails.size();

    cout << lisLength << '\n';

    int trackIndex = *(pos.end() - 1);

    vector<int> lis;

    while (trackIndex != -1)
    {
        lis.push_back(arr[trackIndex]);
        trackIndex = prev[trackIndex];
    }

    reverse(lis.begin(), lis.end());
   
    for (int num : lis)
    {
        cout << num << " ";
    }

    cout << '\n';
  


    return 0;
}