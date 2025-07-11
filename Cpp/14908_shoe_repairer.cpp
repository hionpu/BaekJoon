#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct repair {
    int idx;
    double ratio;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;

    vector<repair> rp(N);

    for (int i = 1; i <= N; ++i)
    {
        double t, s; cin >> t >> s;
        repair r = { i, s/t };
        rp.push_back(r);
    }

    sort(rp.begin(), rp.end(), [](repair a, repair b)
        {
            if (a.ratio == b.ratio) return a.idx < b.idx;
            return a.ratio > b.ratio;
        });

    for (int i = 0; i < N; ++i)
    {
        cout << rp[i].idx << '\n';
    }

    return 0;
}