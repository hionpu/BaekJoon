#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

vector<pii> graph[801];
ll dist[801];
int N;

auto comparator = [](pii a, pii b)
    {
        return a.second > b.second;
    };

priority_queue<pii, vector<pii>, decltype(comparator)> pq(comparator);

int V1, V2;

void dijkstra(int start) {
    pq.push({ start,0 });
    dist[start] = 0;

    while (!pq.empty())
    {
        pii t = pq.top();
        int node = t.first;
        int cost = t.second;

        pq.pop();

        for (const auto & n : graph[node]) {
            int nNode = n.first;
            int totalCost = cost + n.second;

            if (dist[nNode] > totalCost)
            {
                pq.push({ nNode, totalCost });
                dist[nNode] = totalCost;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int E; cin >> N >> E;

    fill(dist + 1, dist + N + 1, INT_MAX);

    for (int i = 0; i < E; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }
    
    cin >> V1 >> V2;

    dijkstra(V1);
    ll v1_1 = dist[1];
    ll v1_v2 = dist[V2];
    ll v1_n = dist[N];

    while (!pq.empty()) pq.pop();
    fill(dist + 1, dist + N + 1, INT_MAX);

    dijkstra(V2);
    ll v2_1 = dist[1];
    ll v2_n = dist[N];

    ll start_v1_v2_n = v1_1 + v1_v2 + v2_n;
    ll start_v2_v1_n = v2_1 + v1_v2 + v1_n;

    ll ans = min(start_v1_v2_n, start_v2_v1_n);

    if (ans >= INT_MAX) ans = -1;

    cout << ans << '\n';

    return 0;
}