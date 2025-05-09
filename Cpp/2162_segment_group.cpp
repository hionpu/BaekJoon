#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int cross = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    int ans = cross == 0 ? 0 : cross > 0 ? 1 : -1;
    return ans;
}

int ccw(pii a, pii b, pii c) {
    return ccw(a.first, a.second, b.first, b.second, c.first, c.second);
}

bool checkIntersection(pii a, pii b, pii c, pii d) {
    int abc = ccw(a, b, c);
    int abd = ccw(a, b, d);
    int cda = ccw(c, d, a);
    int cdb = ccw(c, d, b);

    if (abc * abd <= 0 && cda * cdb <= 0)
    {
        if (abc == 0 && abd == 0)
        {
            return max(min(a.first,b.first), min(c.first,d.first)) <=
                min(max(a.first,b.first),max(c.first,d.first)) &&
                max(min(a.second, b.second), min(c.second, d.second)) <=
                min(max(a.second, b.second), max(c.second, d.second));

        }
        return true;
    }
    return false;
}


struct segment {
    pii p1;
    pii p2;
};

class DS {
private:
    vector<int> parent;
    vector<int> count;
    vector<int> rank;
    vector<segment> segs;
public:
    DS(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
        count.assign(n, 1);
        rank.assign(n, 1);
    }

    int getParent(int n) {
        if (parent[n] == n) return n;
        return parent[n] = getParent(parent[n]);
    }

    void unite(int a, int b) {
        int rootA = getParent(a);
        int rootB = getParent(b);

        if (rootA == rootB) return;

        if (rank[rootA] > rank[rootB])
        {
            parent[rootB] = rootA;
            count[rootA] += count[rootB];
            count[rootB] = 0;
        }
        else
        {
            parent[rootA] = rootB;
            count[rootB] += count[rootA];
            count[rootA] = 0;

            if (rank[rootA] == rank[rootB])
            {
                rank[rootB]++;
            }
        }
    }

    void check(segment& seg) {
        int newIdx = segs.size();
        for (int i = 0; i < segs.size(); ++i)
        {
            if (checkIntersection(seg.p1, seg.p2, segs[i].p1, segs[i].p2)) {
                unite(newIdx, i);
            }
        }
        segs.push_back(seg);
    }

    int groupCount() {
        int gc = 0;
        for (int i = 0; i < count.size(); ++i)
        {
            if (count[i] != 0) gc++;
        }
        return gc;
    }

    int maxGroupSize() {
        int mgs = 0;
        for (int i = 0; i < count.size(); ++i)
        {
            if (mgs < count[i]) mgs = count[i];
        }
        return mgs;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    DS ds(N);
    for (int i = 0; i < N; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        segment seg = { {x1,y1},{x2,y2} };
        ds.check(seg);
    }

    cout << ds.groupCount() << '\n';
    cout << ds.maxGroupSize() << '\n';

    

    return 0;
}