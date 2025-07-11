#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <set>
using namespace std;
struct TwoSAT {
    int n;
    vector<vector<int>> graph;
    vector<int> id, nodeToScc;
    vector<bool> finished;
    TwoSAT(int n) : n(n) {
        graph.resize(2 * n);
        id.resize(2 * n, 0);
        nodeToScc.resize(2 * n);
        finished.resize(2 * n, false);
    }
    // x should always >0
    int pos(int x) { return 2 * (x - 1); }
    int neg(int x) { return 2 * (x - 1) + 1; }
    void addClause(int a, int b) {
        int nodeA, nodeB, notA, notB;
        if (a > 0)
        {
            nodeA = pos(a);
            notA = neg(a);
        }
        else
        {
            nodeA = neg(-a);
            notA = pos(-a);
        }
        if (b > 0)
        {
            nodeB = pos(b);
            notB = neg(b);
        }
        else
        {
            nodeB = neg(-b);
            notB = pos(-b);
        }
        graph[notA].push_back(nodeB);
        graph[notB].push_back(nodeA);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M; cin >> N >> M;
    TwoSAT ts(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b; cin >> a >> b;
        ts.addClause(a, b);
    }
    auto& id = ts.id;
    auto& nodeToScc = ts.nodeToScc;
    auto& finished = ts.finished;
    auto& graph = ts.graph;
    vector<vector<int>> Scc;
    int idx = 0;
    int sccNum = 0;
    stack<int> s;
    function<int(int)> DFS = [&](int n) -> int
        {
            id[n] = ++idx;
            s.push(n);
            int result = id[n];
            for (auto& next : graph[n])
            {
                if (id[next] == 0) result = min(result, DFS(next));
                else if (!finished[next]) result = min(result, id[next]);
            }
            if (result == id[n])
            {
                vector<int> scc;
                while (true)
                {
                    int top = s.top();
                    s.pop();
                    scc.push_back(top);
                    finished[top] = true;
                    nodeToScc[top] = sccNum;
                    if (top == n) break;
                }
                Scc.push_back(scc);
                sccNum++;
            }
            return result;
        };
    for (int i = 0; i < 2 * N; ++i)
    {
        if (id[i] == 0) DFS(i);
    }
    for (int i = 0; i < 2 * N; i += 2)
    {
        if (nodeToScc[i] == nodeToScc[i + 1])
        {
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << 1 << '\n';
    vector<int> solution(N, -1);
    for (int sccId = sccNum - 1; sccId >= 0; --sccId)
    {
        vector<int> nodes = Scc[sccId];
        sort(nodes.begin(), nodes.end());  // 노드 번호 순 정렬
        for (const int x : nodes)
        {
            int original = x / 2;
            if (solution[original] == -1)
            {
                solution[original] = (x % 2 == 1);  // negative면 true, positive면 false
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        cout << solution[i] << ' ';
    }
    cout << '\n';

    return 0;
}