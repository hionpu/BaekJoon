#include <iostream>   
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> pii;

const int MAX_V = 2000;

auto cmp = [](pii a, pii b)
    {
        return a.second > b.second;
    };

priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

int dists[MAX_V +1];
vector<pii> graph[MAX_V +1];
vector<int> destins;

int n;

void dijk(int start) {
    dists[start] = 0;
    pq.push({ start,0 });

    while (!pq.empty())
    {
        pii t = pq.top();
        pq.pop();

        int node = t.first;
        int cost = t.second;

        for (const auto& next : graph[node])
        {
            int nextNode = next.first;
            int totalCost = cost + next.second;

            if (dists[nextNode] > totalCost)
            {
                dists[nextNode] = totalCost;
                pq.push({ nextNode, totalCost });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T=0, m, t;

    cin >> T;


    auto cleanTable = []()-> void {
        while (!pq.empty()) pq.pop();
        fill(dists, dists + MAX_V + 1, INT_MAX);
    };

    while (T--)
    {   
        int start, g, h;
        cin >> n >> m >> t >> start >> g >> h;
        destins.clear();

        while (!pq.empty()) pq.pop();
        for (int i = 0; i <= n; ++i)
        {
            graph[i].clear();
        }
        fill(dists, dists + MAX_V + 1, INT_MAX);

        for (int i = 0; i < m; ++i)
        {
            int a, b, d; cin >> a >> b >> d;
            graph[a].push_back({ b,d });
            graph[b].push_back({ a,d });
        }

        for (int i = 0; i < t; ++i)
        {
            int dest; cin >> dest;
            destins.push_back(dest);
        }

        dijk(start);
        vector<pii> start_to_ends;

        for (int i = 0; i < t; ++i)
        {
            start_to_ends.push_back({ destins[i], dists[destins[i]] });
        }


        cleanTable();

        dijk(g);
        int g_to_start = dists[start];
        map<int, int> g_to_ends;
        int g_to_h = dists[h];

        for (int i = 0; i < t; ++i)
        {
            g_to_ends.insert({ destins[i], dists[destins[i]]});
        }
        
        cleanTable();

        dijk(h);
		int h_to_start = dists[start];
        map<int, int> h_to_ends;

        for (int i = 0; i < t; ++i)
        {
            h_to_ends.insert({ destins[i], dists[destins[i]] });
        }

        vector<int> ans;

        for (int i = 0; i < t; ++i)
        {
            int destin = start_to_ends[i].first;
            int shortest = start_to_ends[i].second;

            int start_h_g_end = h_to_start + g_to_h + g_to_ends[destin];
            int start_g_h_end = g_to_start + g_to_h + h_to_ends[destin];

            int shorter = min(start_h_g_end, start_g_h_end);

            if (shorter < INT_MAX && shorter == shortest) ans.push_back(destin);
        }

     

        sort(ans.begin(), ans.end());

        for (const auto& x : ans)
        {
            cout << x << '\n';
        }
        for (int i =0;i<6;i+=2){}
    }

    return 0;
}