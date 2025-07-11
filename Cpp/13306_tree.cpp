#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

struct DS {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DS(int n) {
        parent.resize(n+1, 0);
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
        }

        rank.resize(n + 1);
    }

    int getParent(int a) {
        if (parent[a] == a) return a;
        else return parent[a] = getParent(parent[a]);
    }

    void join(int c, int p) {
        int cp = getParent(c);
        parent[cp] = getParent(p);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q; cin >> N >> Q;
    map<int, int> edge;

    for (int i = 1; i < N; ++i)
    {
        int a; cin >> a;
        edge[i + 1]=a;
    }

    vector<int> commands(N-1+Q);
    vector<vector<int>> params(N-1+Q);

    for (int i = 0; i < N - 1 + Q; ++i)
    {
        int x; cin >> x;
        commands[i] = x;
        if (x == 0)
        {
            int b; cin >> b;
            params[i].push_back(b);
        }
        else if (x == 1)
        {
            int c, d; cin >> c >> d;
            params[i].push_back(c);
            params[i].push_back(d);
        }
    }

    DS ds(N);
    vector<bool> answers;
    for (int i = N - 1 + Q - 1; i >= 0; --i)
    {
        if (commands[i] == 0)
        {
            int b = params[i][0];
            ds.join(b, edge[b]);
        }
        else if (commands[i] == 1)
        {
            int c = params[i][0];
            int d = params[i][1];
            
            answers.push_back(ds.getParent(c) == ds.getParent(d));
        }
    }

    const string y = "YES";
    const string n = "NO";
    for (int i = answers.size() - 1; i >= 0; --i)
    {
        if (answers[i]) cout << y << '\n';
        else cout << n << '\n';
    }

    return 0;
}