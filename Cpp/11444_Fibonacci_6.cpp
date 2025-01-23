#include <iostream>   
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> mat;
const ll mod = 1'000'000'007;
const ll N = 2;

static mat prod(const mat &A, const mat &B) {
    mat C(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int x = 0; x < N; x++)
            {
                C[i][j] = (C[i][j] + A[i][x] * B[x][j] % mod) % mod;
            }
        }
    }
    return C;
}

static mat n_square(mat A, ll B) {
    mat result = { {1,0}, {0,1} };
    while (B > 0)
    {
        if (B & 1)
        {
            result = prod(result, A);
        }
        A = prod(A, A);
        B >>= 1;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >>n;

    mat A(N, vector<ll>(N, 0));
    ll aa[N][N] = { {1,1},{1,0} };


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = aa[i][j];
        }
    }

    mat X = n_square(A, n-1);
    ll ans;
    if (n == 0)  ans = 0;
    else if (n == 1) ans = 1;
    else ans = X[0][0];
    cout << ans << '\n';

    return 0;
}