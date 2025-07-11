#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct DS {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DS(int n) {
        parent.assign(n+1, 0);
        for (int i = 0; i < n + 1; ++i) parent[i] = i;
        rank.assign(n + 1, 0);
    }

    int getParent(int n) {
        if (parent[n] == n) return n;
        else return parent[n] = getParent(parent[n]);
    }

    void join(int a, int b) {
        parent[getParent(a)] = getParent(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int G, P; cin >> G >> P;

    DS ds(G);
    int ans = P;
    for (int i = 1; i <= P; ++i)
    {

        int p; cin >> p;
        int available = ds.getParent(p);
        
        if (available == 0)
        {
            ans = i - 1;
            break;
        }
        
        ds.join(available, available - 1);
    }

    cout << ans << '\n';

    return 0;
}