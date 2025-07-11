#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>
#include <functional>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int V, E; cin >> V >> E;
    vector<vector<int>> graph(V + 1);

    for (int i = 0; i < E; ++i)
    {
        int A, B; cin >> A >> B;
        graph[A].push_back(B);
    }

    vector<vector<int>> SCC;
    vector<int> id(V + 1);
    vector<bool> categorized(V + 1);
    vector<int> sccIdx(V + 1);
    stack<int> s;
    int idx = 0;
    int sccNum = 1;
    function<int(int)> DFS = [&](int a)-> int
        {
            id[a] = ++idx;
            s.push(a);

            int result = id[a];
            for (int next : graph[a])
            {
                if (id[next] == 0)
                {
                    result = min(result, DFS(next));
                }
                else if (!categorized[next])
                {
                    result = min(result, id[next]);
                }
            }

            if (result == id[a])
            {
                vector<int> scc;
                while (true)
                {
                    int top = s.top();
                    s.pop();
                    scc.push_back(top);
                    categorized[top] = true;
                    sccIdx[top] = sccNum;
                    if (a == top) break;
                }
                sort(scc.begin(), scc.end());
                SCC.push_back(scc);
                sccNum++;
            }

            return result;

        };

    auto comp = [](vector<int>& a, vector<int>& b)->bool
        {
            if (a.size() == 0 || b.size() == 0) return true;
            else return a[0] < b[0];
        };

    for (int i = 1; i <= V; ++i)
    {
        if (id[i] == 0) DFS(i);
    }

    sort(SCC.begin(), SCC.end(), comp);

    cout << SCC.size() << '\n';
    for (int i = 0; i < SCC.size(); ++i)
    {
        for (const auto& node : SCC[i])
        {
            cout << node << ' ';
        }
        cout << -1 << '\n';
    }

    return 0;
}