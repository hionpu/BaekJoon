#include <iostream>   
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;


static bool found(const vector<ll>& s, ll b) {
    
    int left = 0;
    int right = s.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (s[mid] == b) return true;
        else if (s[mid] < b)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N;
    vector<ll> s(N,0);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        s[i]=a;
    }

    sort(s.begin(), s.end());

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        ll b;
        cin >> b;
        if (found(s, b)) cout << 1;
        else cout << 0;
        cout << '\n';
    }

    return 0;
}