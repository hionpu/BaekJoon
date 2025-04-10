#include <iostream>   
#include <queue>
#include <map>

using namespace std;

queue<int> q;
map<int, int> m;

int moves[101];

void bfs(int x) {
    q.push(x);
    moves[x] = 1;

    while (!q.empty())
    {
        int fr = q.front();
        q.pop();

        int nx = 0;
       
            for (int i = 1; i <= 6; ++i)
            {
                nx = fr + i;
                if (nx <= 100)
                {
                    while (m.find(nx) != m.end())
                    {
                        nx = m[nx];
                    }
                    if (moves[nx] == 0)
                    {
                        moves[nx] = moves[fr] + 1;
                        q.push(nx);
                    }
                }
            }
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    moves[0] = -1;

    int N, M;
    cin >> N >> M;

    for (int i= 0; i < N; ++i) 
    {
        int a, b; cin >> a >> b;
        m.insert({a,b});
    }

    for (int i = 0; i < M; ++i)
    {
        int a, b; cin >> a >> b;
        m.insert({ a,b });
    }

    bfs(1);

    cout << moves[100] - 1 << '\n';

    return 0;
}