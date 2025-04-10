#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include<queue>

using namespace std;

int costs[100001];
int prevs[100001];
int N, K;
queue<int> q;
const int INF = 100001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    q.push(N);
    int maxPos = 100000;
    for (int i = 0; i < maxPos + 1; ++i) costs[i] = INF;
    costs[N] = 0;

    while (!q.empty())
    {
        int fr = q.front();
        q.pop();

        if (fr == K) break;

        if (fr-1>=0 && costs[fr - 1] > costs[fr] + 1)
        {
            costs[fr - 1] = costs[fr] + 1;
            prevs[fr - 1] = fr;
            q.push(fr - 1);
        }

        if ( fr+1 <= maxPos && costs[fr + 1] > costs[fr] + 1)
        {
            costs[fr + 1] = costs[fr] + 1;
            prevs[fr + 1] = fr;
            q.push(fr + 1);
        }

        if ( 2*fr <= maxPos && costs[2*fr] > costs[fr] + 1)
        {
            costs[2*fr] = costs[fr] + 1;
            prevs[2 * fr] = fr;
            q.push(2*fr);
        }
    }

    cout << costs[K] << '\n';

    vector<int> path;
    int cur = K;
    path.push_back(K);
    while (cur != N)
    {
        path.push_back(prevs[cur]);
        cur = prevs[cur];
    }

    reverse(path.begin(), path.end());

    for (auto& x : path) cout << x << " ";
    cout << '\n';

    return 0;
}