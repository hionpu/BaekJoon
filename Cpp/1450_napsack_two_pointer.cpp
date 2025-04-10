#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N, C;


vector<int> getSubset(vector<int> arr) {
    vector<int> result;
    
    for (int i = 0; i < (1 << arr.size()); ++i)
    {
        int sub_sum = 0;
        bool isOver = false;
        for (int j = 0; j < arr.size(); ++j)
        {
            if (i & (1 << j))
            {
                sub_sum += arr[j];
                if (sub_sum > C) break;
            }
        }
        if (!isOver) result.push_back(sub_sum);
    }
    sort(result.begin(), result.end());
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> C;
    vector<int> left;
    vector<int> right;
    left.reserve(N / 2);
    right.reserve(N - N / 2);

    for (int i = 0; i < N/2; ++i)
    {
        int x; cin >> x;
        left.push_back(x);
    }

    for (int i = 0; i < N - N / 2; ++i)
    {
        int x; cin >> x;
        right.push_back(x);
    }

    vector<int> lsub = getSubset(left);
    vector<int> rsub = getSubset(right);
    
    int lptr = 0;
    int rptr = rsub.size() - 1;

    int ans = 0;

    while (lptr <= lsub.size() - 1 && rptr >= 0)
    {
        if (lsub[lptr] + rsub[rptr] > C)
        {
            rptr--;
        }
        else 
        {
            lptr++;
            ans += rptr + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}