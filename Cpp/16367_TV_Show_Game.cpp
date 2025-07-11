#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>


using namespace std;

class TwoSAT {
private:
    int N;
    vector<vector<int>> graph;
    vector<bool> finished;

    stack<int> st;
    int idx;
    int sccNum;

    int DFS(int n) {
        id[n] = ++idx;
        st.push(n);

        int result = id[n];

        for (int next : graph[n])
        {
            if (id[next] == 0) result = min(result, DFS(next));
            else if (!finished[next]) result = min(result, id[next]);
        }

        if (result == id[n])
        {
            vector<int> scc;

            while (true)
            {
                int top = st.top();
                st.pop();
                finished[top] = true;
                nodeToScc[top] = sccNum;
                scc.push_back(top);
                if (top == n) break;
            }
            Scc.push_back(scc);
            sccNum++;
        }

        return result;
    }

public:
    vector<int> id;
    vector<vector<int>> Scc;
    vector<int> nodeToScc;

    TwoSAT(int n) {
        N = n;
        id.assign(2 * N, 0);
        graph.resize(2 * N);
        finished.assign(2 * N, false);
        nodeToScc.assign(2 * N, -1);
        idx = 0;
        sccNum = 0;
    }

    int pos(int n) { return 2 * (n - 1); }
    int neg(int n) { return 2 * (n - 1) + 1; }

    void addClauseMaxOneFalse(int a, int b, int c) {
        int nodeA, nodeB, nodeC, notA, notB, notC;
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
        if (c > 0)
        {
            nodeC = pos(c);
            notC = neg(c);
        }
        else
        {
            nodeC = neg(-c);
            notC = pos(-c);
        }

        graph[notA].push_back(nodeB);
        graph[notB].push_back(nodeA);
        graph[notB].push_back(nodeC);
        graph[notC].push_back(nodeB);
        graph[notC].push_back(nodeA);
        graph[notA].push_back(nodeC);

    }

    void findScc() {
        for (int i = 0; i < 2 * N; ++i)
        {
            if (id[i] == 0) DFS(i);
        }
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k, n; cin >> k >> n;
    TwoSAT ts(k);

    for (int i = 0; i < n; ++i)
    {
        vector<int> v(3);
        for (int j = 0; j < 3; ++j)
        {
            char c; cin >> v[j] >> c;
            int sign = c == 'R' ? 1 : -1;
            v[j] *= sign;
        }

        ts.addClauseMaxOneFalse(v[0], v[1], v[2]);
    }

    ts.findScc();

    for (int i = 0; i < 2 * k; i += 2)
    {
        if (ts.nodeToScc[i] == ts.nodeToScc[i + 1])
        {
            cout << -1 << '\n';
            return 0;
        }
    }

    // Fix: Properly handle variable assignment
    vector<int> solution(k + 1, -1);

    // Process SCCs in REVERSE order
    for (int i = ts.Scc.size() - 1; i >= 0; --i)
    {
        for (int node : ts.Scc[i])
        {
            int var = node / 2 + 1; // Convert to 1-indexed variable
            if (solution[var] == -1)
            {
                // Positive literal (even node) maps to Red (R)
                // Negative literal (odd node) maps to Blue (B)
                solution[var] = (node % 2 == 0) ? 0 : 1;
            }
        }
    }

    // Output results
    for (int i = 1; i <= k; ++i)
    {
        char c = (solution[i] == 1) ? 'R' : 'B';
        cout << c;
    }
    cout << '\n';

    return 0;
}