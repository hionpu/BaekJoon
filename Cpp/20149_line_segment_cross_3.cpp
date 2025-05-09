#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int ccw(pll a, pll b, pll c) {
    ll cross = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
    if (cross > 0) return 1;
    else if (cross < 0) return -1;
    else return 0;
}

bool checkIntersection(pll a, pll b, pll c, pll d) {
    int abc = ccw(a, b, c);
    int abd = ccw(a, b, d);
    int cda = ccw(c, d, a);
    int cdb = ccw(c, d, b);

    if (abc * abd <= 0 && cda * cdb <= 0)
    {
        if (abc == 0 && abd == 0)
        {
            if (min(a, b) <= max(c, d) && min(c, d) <= max(a, b))
                return true;
            return false;
        }
        return true;
    }
    return false;
}

pll getIntersection(pll a, pll b, pll c, pll d) {
    ll A1 = b.second - a.second;
    ll B1 = a.first - b.first;
    ll C1 = A1 * a.first + B1 * a.second;

    ll A2 = d.second - c.second;
    ll B2 = c.first - d.first;
    ll C2 = A2 * c.first + B2 * c.second;

    ll det = A1 * B2 - A2 * B1;

    if (det == 0) return { LLONG_MAX, LLONG_MAX }; // Parallel lines

    ll x = (B2 * C1 - B1 * C2) / det;
    ll y = (A1 * C2 - A2 * C1) / det;

    return { x, y };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    pll a = { x1, y1 }, b = { x2, y2 }, c = { x3, y3 }, d = { x4, y4 };

    bool intersect = checkIntersection(a, b, c, d);
    cout << intersect << '\n';

    if (intersect)
    {
        pll intersection = getIntersection(a, b, c, d);
        if (intersection.first != LLONG_MAX)
        {
            cout << fixed << setprecision(10) << intersection.first << ' ' << intersection.second << '\n';
        }
    }

    return 0;
}