#include <iostream>   
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#include <tuple>


using namespace std;

typedef pair<int, int> pii;

int V;
vector<pii> graph[20001];
int dist[20001];

auto comparator = [](pii a, pii b)
    {
        return a.second > b.second;
    };
priority_queue<pii, vector<pii>, decltype(comparator)> pq(comparator);


void dijkstra(int start) {
    pq.push({ start,0 });
    dist[start] = 0;

    while (!pq.empty())
    {
        pii fr = pq.top();
        int curNode = fr.first;
        int curCost = fr.second;

        pq.pop();

        for (const auto& next : graph[curNode])
        {
            int nextNode = next.first;
            int nextCost = next.second;
            int totalCost = dist[curNode] + nextCost;

            if (dist[nextNode] > totalCost)
            {
                dist[nextNode] = totalCost;
                pq.push({ nextNode, totalCost });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int E; cin >> V >> E;
    int start; cin >> start;

    fill(dist+1, dist + V+1, INT_MAX);

    for (int i = 0; i < E; ++i)
    {
        int s, e, c; cin >> s >> e >> c;
        graph[s].push_back(make_pair(e, c));
        //graph[e].push_back(make_pair(s, c));
    }

    dijkstra(start);

    for (int i = 1; i <= V; ++i)
    {

        if (dist[i] == INT_MAX) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}