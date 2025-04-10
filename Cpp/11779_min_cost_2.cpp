#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 100'000'001;

typedef pair<int, int> pii;

auto comp = [](pii a, pii b)
    {
        return a.second > b.second;
    };

priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);
int costs[1001];
int prevs[1001];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> n >> m;
    vector<vector<pii>> graph(1001);

    for (int i = 0; i <= n; ++i) costs[i] = INF;
    for (int i = 0; i < m; ++i)
    {
        int s, e, c; cin >> s >> e >> c;
        graph[s].push_back({ e,c });
    }

    int A, B; cin >> A >> B;

    pq.push({ A,0 });

    while (!pq.empty())
    {
        pii t = pq.top();
        int curNode = t.first;
        int curCost = t.second;
        pq.pop();

        if (curNode == B) break;

        for (auto& n : graph[curNode])
        {
            int nextNode = n.first;
            int nextCost = n.second + curCost; 

            if (nextCost < costs[nextNode])
            {
                pq.push({ nextNode, nextCost });
                costs[nextNode] = nextCost;
                prevs[nextNode] = curNode;
            }
        }
    }
    cout << costs[B] << '\n';

    int curNode = B;
    int numCity = 1;
    vector<int> path;
    path.push_back(B);
    while (curNode != A)
    {
        curNode = prevs[curNode];
        path.push_back(curNode);
        numCity++;
    }
    cout << numCity << '\n';
    reverse(path.begin(), path.end());

    for (int& n : path)
    {
        cout << n << " ";
    }

    cout << '\n';

    return 0;
}