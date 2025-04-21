#include <bits/stdc++.h>


using namespace std;


class DisjointSet {
private:
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;
    unordered_map<string, int> count;

public:
    DisjointSet() {
       
        
    }

    void insert(string a, string b) {

        if (parent.count(a) == 0)
        {
            parent[a] = a;
            rank[a] = 0;
            count[a] = 1;
        }

        if (parent.count(b) == 0)
        {
            parent[b] = b;
            rank[b] = 0;
            count[b] = 1;
        }

        string rootA = getParent(a);
        string rootB = getParent(b);
        
        if (rootA == rootB) return;

        if (rank[rootA] > rank[rootB])
        {
            parent[rootB] = rootA;
            count[rootA] += count[rootB];
            count[rootB] = 0;
        }
        else if (rank[rootA] < rank[rootB])
        {
            parent[rootA] = rootB;
            count[rootB]+=count[rootA];
            count[rootA] = 0;
        }
        else
        {
            parent[rootB] = rootA;
            count[rootA] += count[rootB];
            count[rootB] = 0;
            rank[rootA]++;
        }
        
        unite(a, b);
    }

    string getParent(string n) {
        if (parent[n] == n) return n;
        return parent[n] = getParent(parent[n]);
    }

    void unite(string a, string b) {
        string rootA = getParent(a);
        string rootB = getParent(b);
        if (rootA == rootB) return;

        if (rank[rootA] > rank[rootB])
        {
            parent[rootB] = rootA;
            count[rootA] += count[rootB];
            count[rootB] = 0;
        }
        else if (rank[rootA] < rank[rootB])
        {
            parent[rootA] = rootB;
            count[rootB]+= count[rootA];
            count[rootA] = 0;
        }
        else
        {
            parent[rootB] = rootA;
            count[rootA]+= count[rootB];
            count[rootB]=0;
            rank[rootA]++;
        }
    }

    int getCount(string n) {
        return count[getParent(n)];
    }

    bool same(string a, string b) {
        return getParent(a) == getParent(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, f; cin >> t;

    for (int tc = 0;tc < t; ++tc)
    {
        cin >> f;
        DisjointSet ds;
        for (int nw = 0; nw < f; ++nw)
        {
            string a, b; cin >> a >> b;
            ds.insert(a, b);
            cout << ds.getCount(a) << '\n';
        }
    }
    
    return 0;
}