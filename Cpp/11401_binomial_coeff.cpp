#include <iostream>   

using namespace std;

typedef long long ll;
ll N, K;
ll mod = 1'000'000'007;

static ll go(ll a, ll p, ll mod) {
    if (p == 1) return a % mod;
    ll b = go(a, p / 2, mod);
    if (p % 2 == 0) return b * b % mod;
    else return b * b % mod * a % mod;
}

static ll fact(ll a) {
    if (a == 0) return 1;
    ll ans = a;
    
    while (--a > 0)
    {
        ans = ans * a % mod;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    
    ll ans = 1;
    
    ll nFact = fact(N);
    ll kFact = fact(K);
    ll nkFact = fact(N - K);
    
    ll knk = kFact * nkFact % mod;
    
    ans = nFact * go(knk, mod - 2, mod) % mod;
    cout << ans;

    return 0;
}