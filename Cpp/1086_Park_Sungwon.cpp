#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using ll = long long;

static int getRes(string& s, int K) {
    int ans = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        ans *= 10;
        ans += s[i] - '0';
        ans %= K;
    }
    return ans;
}

static ll GCD(ll a, ll b) {
    
    ll big = max(a, b);
    ll small = min(a, b);

    while (small != 0)
    {
        ll r = big % small;
        big = small;
        small = r;
    }

    return big;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K; cin >> N;
    vector<int> res(N);
    vector<int> tenPowRes(51);
    vector<string> numstr(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> numstr[i];
    }

    cin >> K;

    for (int i = 0; i < N; ++i)
    {
        res[i] = getRes(numstr[i], K);
    }
    tenPowRes[0] = 1 % K;
    for (int i = 1; i <= 50; ++i)
    {
        tenPowRes[i] = (tenPowRes[i - 1] * 10) % K;
    }

    vector<vector<ll>> dp(1 << N, vector<ll>(K, 0));

    dp[0][0] = 1;
    //dp[current][i] = current 상태로 뽑아서 조합한 수 중 나머지가 i인 수의 개수
    for (int current = 0; current < (1 << N); ++current)
    {
        for (int i = 0; i < N; ++i)
        {
            if ((current & (1 << i)) != 0) continue;
            int next = current | (1 << i);

            for (int j = 0; j < K; ++j)
            {
                int nextRes = ((j * tenPowRes[numstr[i].length()]) % K + res[i]) % K;
                dp[next][nextRes] += dp[current][j];
            }
        }
    }

    ll p, q;
    q = 1;
    for (int i = 2; i <= N; ++i) q *= i;
    p = dp[(1 << N)-1][0];

    ll gcd = GCD(p, q);
    p /= gcd;
    q /= gcd;

    if (p == 0) cout << 0 << '/' << 1 <<'\n';
    else cout << p << '/' << q << '\n';

    return 0;
}