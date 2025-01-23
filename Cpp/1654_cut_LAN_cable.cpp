#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int K, N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K >> N;
    vector<ll> lans(K);  // Use long long for cable lengths
    ll maxLength = 0;

    for (int i = 0; i < K; i++)
    {
        cin >> lans[i];
        maxLength = max(maxLength, lans[i]);
    }

    ll left = 1;
    ll right = maxLength;  // Max cable length as upper bound
    ll result = 0;         // To store the final answer

    while (left <= right)
    {
        ll mid = (left + right) / 2;
        ll cuts = 0;

        for (int i = 0; i < K; i++)
        {
            cuts += lans[i] / mid;  // Calculate number of pieces
        }

        if (cuts >= N)
        {
            // mid is a valid length; try for longer
            result = mid;  // Store the valid length
            left = mid + 1;
        }
        else
        {
            // mid is too big; try shorter lengths
            right = mid - 1;
        }
    }

    cout << result << '\n';
    return 0;
}
