#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

struct anorm {
    int y;
    int x;
    int d;
    int v;
};

struct comparator {
    bool operator()(pair<pii, int> a, pair<pii, int> b) {
        return a.second > b.second;
    }
};

void findTwallPath(vector<pii>& path, vector<vector<int>>& twall, vector<vector<int>>& costs, int m, pii pos, pii tExit) {
    priority_queue<pair<pii, int>, vector<pair<pii, int>>, comparator> pq;

    int inf = 9999999;
    vector<vector<int>> dist(3 * m, vector<int>(3 * m, inf));
    vector<vector<pii>> prev(3 * m, vector<pii>(3 * m));

    int y = pos.first;
    int x = pos.second;
    pq.push({ pos, 0 });
    dist[y][x] = 0;

    while (!pq.empty())
    {
        pair<pii, int> t = pq.top();
        int y = t.first.first;
        int x = t.first.second;
        int c = t.second;
        pq.pop();

        if (c > dist[y][x]) continue;

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            // boundary & wall condition
            if (ny >= 0 && ny < 3 * m && nx >= 0 && nx < 3 * m && twall[ny][nx] == 0)
            {
                int nc = c + costs[ny][nx];
                if (nc < dist[ny][nx])
                {
                    dist[ny][nx] = nc;
                    prev[ny][nx] = { y, x };
                    pq.push({ {ny,nx}, nc });
                }
                    
            }

        }
    }

    
    cout << "========dist========\n";

    for (int i = 0; i < 3 * m; ++i)
    {
        for (int j = 0; j < 3 * m; ++j)
        {
            int v = dist[i][j] == inf ? 0 : dist[i][j];
            cout << v << ' ';
        }
        cout << '\n';
    }
    cout << "=================\n";

    int curY = tExit.first;
    int curX = tExit.second;

    int a = 0;
    while (true)
    {
        a++;
        path.push_back({ curY,curX });
        if (curY == pos.first && curX == pos.second) break;
        int tempY = prev[curY][curX].first;
        int tempX = prev[curY][curX].second;
        curY = tempY;
        curX = tempX;
        
    }


}

int main() {
    int n, m, f;

    cin >> n >> m >> f;

    vector<vector<int>> board(n, vector<int>(n));
    vector<vector<int>> twall(3 * m, vector<int>(3 * m));
    vector<vector<int>> costs(3 * m, vector<int>(3 * m));
    vector<anorm> anorms;

    // last position before exit twall
    pii twallTL = { -1, -1 };
    pii tExit = { -1,-1 };
    // entrance twall -> board entrance
    pii ent = { -1,-1 };
    // board
    bool tlFound = false;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
            if (!tlFound && board[i][j] == 3)
            {
                tlFound = true;
                twallTL = { i,j };
            }
        }
    }
    int whichWall = -1;
    int exitPos = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == 3)
            {
                for (int k = 0; k < 4; ++k)
                {
                    if (board[i + dy[k]][j + dx[k]] == 0)
                    {
                        ent = { i + dy[k],j + dx[k] };
                    }
                }
                
            }
        }
    }

    pii ent_reduced = { ent.first - twallTL.first + 1, ent.second - twallTL.second + 1 };

    // north 
    if (ent_reduced.first == 0)
    {
        tExit.first = 0;
        tExit.second = m + ent_reduced.second - 1;
    }
    // south
    else if (ent_reduced.first == m+1) 
    {
        tExit.first = 3 * m - 1;
        tExit.second = m + ent_reduced.second - 1;
    }
    // west
    else if (ent_reduced.second == 0)
    {
        tExit.first = m + ent_reduced.first - 1;
        tExit.second = 0;
    }
    // east
    else if (ent_reduced.second == m + 1)
    {
        tExit.first = m + ent_reduced.first - 1;
        tExit.second = 3 * m - 1;
    }

   

    cout << "tExit on tWall: (" << tExit.first << ", " << tExit.second << ")\n";

    pii pos;
    //// twall
    vector<vector<int>> tempWall(m, vector<int>(m));
    // east
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            // ccw 90
            cin >> tempWall[m - 1 - j][i];
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            twall[m + i][2 * m + j] = tempWall[i][j];
            costs[m + i][2 * m + j] = 1;
        }
    }

    // west
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            // cw 90
            cin >> tempWall[j][m - 1 - i];
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            twall[m + i][j] = tempWall[i][j];
            costs[m + i][j] = 1;
        }
    }
    // south

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> twall[2 * m + i][m + j];
            costs[2 * m + i][m + j] = 1;
        }
    }
    // north
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            // cw 180
            cin >> tempWall[m - 1 - i][m - 1 - j];


        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            twall[i][m + j] = tempWall[i][j];
            costs[i][m + j] = 1;
        }
    }
    // top
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> twall[m + i][m + j];
            if (twall[m + i][m + j] == 2)
            {
                pos = { m + i, m + j };
            }
            costs[m + i][m + j] = 1;
        }
    }

    cout << "====twall=====" << '\n';
    for (int i = 0; i < 3 * m; ++i)
    {
        for (int j = 0; j < 3 * m; ++j)
        {
            cout << twall[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "====================";
    for (int i = 0; i < f; ++i)
    {
        anorm a;
        cin >> a.y >> a.x >> a.d >> a.v;
        anorms.push_back(a);
    }

    for (int i = 0; i < f; ++i)
    {
        cout << anorms[i].y << ' ' << anorms[i].x << '\n';
    }

    // SPECIFY WHICH FACE HAS TWALL EXIT
    // FIND WAY OUT FROM TWALL
    vector<pii> twallPath;
    findTwallPath(twallPath, twall, costs, m, pos, tExit);
    reverse(twallPath.begin(), twallPath.end());

    vector<int> twallTime;
    for (int i = 0; i < twallPath.size(); ++i)
    {
        cout << '(' << twallPath[i].first << ',' << twallPath[i].second << ") ";
    }
    cout << '\n';


    return 0;
}