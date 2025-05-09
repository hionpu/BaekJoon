#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pdd;

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll cross = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (cross > 0) return 1;
    else if (cross < 0) return -1;
    else return 0;
}

int ccw(pdd a, pdd b, pdd c) {
    return ccw(a.first, a.second, b.first, b.second, c.first, c.second);
}

bool checkIntersection(pdd a, pdd b, pdd c,pdd d) {
    int abc = ccw(a, b, c);
    int abd = ccw(a, b, d);
    int cda = ccw(c, d, a);
    int cdb = ccw(c, d, b);

    if (abc * abd <= 0 && cda * cdb <= 0)
    {
        if (abc == 0 && abd == 0)
        {
            if (min(a.first, b.first) <= max(c.first, d.first) && min(c.first, d.first) <= max(a.first, b.first) &&
                min(a.second, b.second) <= max(c.second, d.second) && min(c.second, d.second) <= max(a.second, b.second))
                return true;
            return false;
        }
        return true;
    }
    return false;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll x1, y1, x2, y2, x3, y3, x4, y4;
    
    cin >> x1>> y1>> x2>>y2>> x3>> y3>> x4>> y4;

    bool intersect = checkIntersection({ x1,y1 }, { x2,y2 }, { x3,y3 }, { x4,y4 });
    cout << intersect <<'\n';

    

    return 0;
}