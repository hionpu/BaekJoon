#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using ll = long long;

struct disk {
    ll o;
    ll n;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

    vector<disk> v;

    for (int i = 0; i < n; ++i)
    {
        ll a, b; cin >> a >> b;
        v.push_back({ a,b });
    }

    sort(v.begin(), v.end(), [](disk a, disk b) -> bool {
        int diffA = a.n - a.o;
        int diffB = b.n - b.o;
        if (diffA >= 0 && diffB < 0) return true;
        if (diffA < 0 && diffB >= 0) return false;
        if (diffA < 0 && diffB < 0) return a.n > b.n;
        return a.o < b.o;
    });

    ll curCap = 0, totalExtra = 0;
    for (int i = 0; i < n; ++i)
    {
        ll additionalNeed = -min(0LL, curCap - v[i].o);
        totalExtra += additionalNeed;       // 총 extra drive 용량
        curCap += additionalNeed;           // 현재 용량에 반영
        curCap = curCap - v[i].o + v[i].n;  // 드라이브 처리
    }

    cout << totalExtra << '\n';

    return 0;
}