#include <iostream>   
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> mat;
ll N;
ll B;
const ll mod = 1000;

static vector<vector<ll>> prod(mat A, mat B) {
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

static vector<vector<ll>> n_square(mat A, const ll B) {
    if (B == 1) return A;

    vector<vector<ll>> X = n_square(A, B / 2);
    if (B % 2 == 1) return prod(prod(X, X),A);
    else return prod(X,X);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> B;

    mat A(N, vector<ll>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int a; cin >> a;
            A[i][j]=a%mod;
        }
    }
        
    mat X= n_square(A, B);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << X[i][j] << " ";
            if (j == N - 1) cout << '\n';
        }
    }

    return 0;
}