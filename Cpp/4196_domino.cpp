#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

using namespace std;
vector<vector<int>> graph;
vector<int> id;
vector<bool> categorized;
stack<int> s;
vector<vector<int>> SCC;
vector<int> sccIdx;
vector<int> sccInDegree;
int idx;
int sccNum;

int DFS(int n) {
    id[n] = ++idx;
    s.push(n);

    int result = id[n];

    for (auto& next : graph[n])
    {
        if (id[next] == 0) result = min(result, DFS(next));
        else if (!categorized[next]) result = min(result, id[next]);
    }

    if (result == id[n])
    {
        vector<int> scc;
        while (true)
        {
            int top = s.top();
            s.pop();
            scc.push_back(top);
            categorized[top] = true;
            sccIdx[top] = sccNum;
            if (top == n) break;
        }
        SCC.push_back(scc);
        sccNum++;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int N, M; cin >> N >> M;
        idx = 0;
        sccNum = 0; // Fix: SCC index starts from 0

        graph.assign(N + 1, vector<int>());
        id.assign(N + 1, 0);
        categorized.assign(N + 1, false);
        sccIdx.assign(N + 1, 0);
        SCC.clear();

        while (!s.empty()) s.pop();

        for (int i = 0; i < M; ++i)
        {
            int x, y; cin >> x >> y;
            graph[x].push_back(y);
        }

        for (int i = 1; i <= N; ++i)
        {
            if (id[i] == 0) DFS(i);
        }

        sccInDegree.assign(sccNum, 0); // Fix: size is sccNum

        for (int i = 1; i <= N; ++i)
        {
            for (auto& next : graph[i])
            {
                if (sccIdx[i] != sccIdx[next])
                {
                    sccInDegree[sccIdx[next]]++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < sccNum; ++i) // Fix: loop from 0
        {
            if (sccInDegree[i] == 0) ans++;
        }

        cout << ans << '\n';
    }
    return 0;
}