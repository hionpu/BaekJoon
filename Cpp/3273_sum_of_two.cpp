#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int NMAX = 100000;

int n, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int a; cin >> a; v.push_back(a);
    }

    cin >> x;

    sort(v.begin(), v.end());

    auto start = v.begin();
    auto end = v.end() - 1;

    int ans = 0;

    while (start < end)
    {
        int currentSum = *start + *end;
        if (currentSum == x)
        {
            ans++;
            start++;
            end--;
        }
        else if (currentSum < x) start++;
        else end--;
    }

    cout << ans << '\n';

    return 0;
}