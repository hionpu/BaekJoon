#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m; cin >> m;
    int MAX_LOG = log2(500000) + 1;
    vector<vector<int>> sparse_tbl(MAX_LOG, vector<int>(m + 1));

    for (int i = 1; i <= m; ++i)
    {
        cin >> sparse_tbl[0][i];
    }

    int Q; cin >> Q;

    for (int i = 1; i < sparse_tbl.size(); ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            sparse_tbl[i][j] = sparse_tbl[i - 1][sparse_tbl[i - 1][j]];
        }
    }

    for (int i = 0; i < Q; ++i)
    {
        int n, x; cin >> n >> x;
        int cur = x;
        for (int i = MAX_LOG; i >= 0; --i)
        {
            if (n & (1 << i)) cur = sparse_tbl[i][cur];
        }
        cout << cur << '\n';
    }
    return 0;
}