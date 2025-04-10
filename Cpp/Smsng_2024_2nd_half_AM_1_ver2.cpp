#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

struct anorm {
    bool active;
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

pii relocation(pii p, pii& tWallTL, int n, int m) {
    int lenT = tWallTL.first;
    int lenL = tWallTL.second;

    int y = p.first;
    int x = p.second;

    if (y >= lenT && y < lenT + m) y = y + m;
    else if (y >= lenT + m && y < n) y = y + 2 * m;

    if (x >= lenL && x < lenL + m) x = x + m;
    else if (x >= lenL + m && x < n) x = x + 2 * m;

    return { y,x };
}

void findPathByDij(vector<pii>& path, vector<vector<int>>& board, vector<vector<int>>& costs, pii start, pii end) {

    int n = board.size();
    int inf = n * n + 1;
    priority_queue<pair<pii, int>, vector<pair<pii,int>>, comparator> pq;
    vector<vector<int>> dist(n, vector<int>(n,inf));
    vector<vector<pii>> prev(n, vector<pii>(n));

    pq.push({ start, 0 });
    dist[start.first][start.second] = 0;

    while (!pq.empty())
    {
        pair<pii,int> t = pq.top();
        int cy = t.first.first;
        int cx = t.first.second;
        int cc = t.second;
        pq.pop();

        if (dist[cy][cx] < cc) continue;

        for (int i = 0; i < 4; ++i)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1 || board[ny][nx] != 0) continue;

            int nc = cc + costs[ny][nx];

            if (dist[ny][nx] > nc)
            {
                dist[ny][nx] = nc;
                pq.push({ {ny,nx}, nc });
                prev[ny][nx] ={cy,cx};
            }
        }
    }

    cout << "Dist board=========" << '\n';

    for (int i = 0; i < dist.size(); ++i)
    {
        for (int j = 0; j < dist.size(); ++j)
        {
            cout << dist[i][j];
            int pad = dist[i][j] == 0 ? 0 : log10(dist[i][j]);
            for (int k = 0; i < (3 - pad); ++i)
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    cout << "============================\n";

    pii current = { end.first, end.second };
    if (dist[end.first][end.second] == inf)
    {
        cout << "No path exists from start to end.\n";
        return;
    }

    while (current != start)
    {
        int y = current.first;
        int x = current.second;
        path.push_back({y,x});
        current = { prev[y][x].first, prev[y][x].second };
    }

    for (const auto& point : path)
    {
        cout << "(" << point.first << "," << point.second << ") ";
    }

   

}

void spread(vector<vector<int>>& board, vector<vector<int>>& aBoard, vector<vector<int>>& costs, anorm& a, int turn) {
    if (!a.active) return;
    int numA = turn/a.v;
    if (numA == 0) return;
    int n = board.size();
    int tdy[4] = { 0,0,1,-1 };
    int tdx[4] = { 1,-1,0,0 };

    int dy = tdy[a.d];
    int dx = tdx[a.d];

    for (int i = 1; i <= numA; ++i)
    {
        int ny = a.y + i*dy;
        int nx = a.x + i * dx;

        if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1 || board[ny][nx] != 0)
        {
            a.active = false;
            return;
        }

        if (costs[ny][nx] == 0)
        {
            while (true)
            {
                if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1 || board[ny][nx] != 0)
                {
                    a.active = false;
                    return;
                }
                aBoard[ny][nx] = turn;
                board[ny][nx] = 1;
                ny += dy;
                nx += dx;

                if (costs[ny][nx] == 1)
                {
                    aBoard[ny][nx] = turn;
                    board[ny][nx] = 1;
                    break;
                }
            }
        }
        else
        {
            aBoard[ny][nx] = turn;
            board[ny][nx] = 1;
        }
    }
}

int main() {
    int n, m, f;

    cin >> n >> m >> f;

    vector<vector<int>> oBoard(n, vector<int>(n));
    vector<vector<int>> tWall(3 * m, vector<int>(3 * m));
    vector<vector<int>> tWallCosts(3 * m, vector<int>(3 * m));
    vector<vector<int>> board(n+2*m, vector<int>(n + 2 * m));
    vector<vector<int>> costs(n+2*m, vector<int>(n + 2 * m));
    vector<vector<int>> aBoard(board.size(), vector<int>(board.size()));

    vector<anorm> anorms;

    // input board
    pii tWallTL;
    pii bExit;
    bool tlFound = false;
    bool exitFound = false;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> oBoard[i][j];
            if (!tlFound && oBoard[i][j] == 3)
            {
                tlFound = true;
                tWallTL = { i,j };
            }
            if (!exitFound && oBoard[i][j] == 4)
            {
                exitFound = true;
                bExit = { i,j };
            }
        }
    }

    cout << "Original board=========" << '\n';

    for (int i = 0; i < oBoard.size(); ++i)
    {
        for (int j = 0; j < oBoard.size(); ++j)
        {
            cout << oBoard[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "============================\n";

    pii pos;

    //// twall calculation and rotate
    vector<vector<int>> tempWall(m, vector<int>(m));
    vector<vector<int>> adjust(m, vector<int>(m));
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
            tWall[m + i][2 * m + j] = tempWall[i][j];
            tWallCosts[m + i][2 * m + j] = 1;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            adjust[i][j] = tWall[i + m][j];

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
            tWall[m + i][j] = tempWall[i][j];
            tWallCosts[m + i][j] = 1;
        }
    }
    // south

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> tWall[2 * m + i][m + j];
            tWallCosts[2 * m + i][m + j] = 1;
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
            tWall[i][m + j] = tempWall[i][j];
            tWallCosts[i][m + j] = 1;
        }
    }

    // top
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> tWall[m + i][m + j];
            if (tWall[m + i][m + j] == 2)
            {
                pos = { m + i, m + j };
            }
            tWallCosts[m + i][m + j] = 1;
        }
    }

    for (int i = 0; i < f; ++i)
    {
        anorm a;
        cin >> a.y >> a.x >> a.d >> a.v;
        a.active = true;
        anorms.push_back(a);
    }

    

    int boardLen = n + 2 * m;

    int lenT = tWallTL.second;
    int lenL = tWallTL.first;
    int lenR = boardLen - lenL - 3 * m;
    int lenB = boardLen - lenT - 3 * m;

    // copy board to extended board and fill wall on 0-cost area
    // 1 2 3
    // 4 X 5
    // 6 7 8
    // 
    // to
    // 
    // 1 0 2 0 3
    // 0 N X N 0
    // 4 X X X 5
    // 0 N X N 0
    // 6 0 7 0 8
    // where
    // 0: padded 0 cost area
    // X: twall
    // N: twall's 0 cost area
    
    // range y: 0 -> lenT   -> lenT+m  -> n
    //          0 -> lenT+m -> lenT+3m -> n+2m
    // range x: 0 -> lenL   -> lenL+m  -> n
    //          0 -> lenL+m -> lenL+3m -> n+2m


    // twall
  
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            pii newPos = relocation({ y,x }, tWallTL, n, m);
            board[newPos.first][newPos.second] = oBoard[y][x];
            costs[newPos.first][newPos.second] = 1;
        }
    }

    for (int y = 0; y < tWall.size(); ++y)
    {
        for (int x = 0; x < tWall.size(); ++x)
        {
            board[lenT + y][lenL + x] = tWall[y][x];
            costs[lenT + y][lenL + x] = tWallCosts[y][x];
        }
    }

    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board.size(); ++x)
        {
            if (y == lenT - 1 || y==lenT+3*m)
            {
                if (x >= lenL && x < lenL + m)
                {
                    board[y][x] = 1;
                }
                else if (x >= lenL + 2 * m && x < lenL + 3 * m)
                {
                    board[y][x] = 1;
                }
            }

            if (x == lenL - 1 || x == lenL + 3 * m)
            {
                if (y >= lenT && y < lenT + m)
                {
                    board[y][x] = 1;
                }
                else if (y >= lenT + 2 * m && y < lenT + 3 * m)
                {
                    board[y][x] = 1;
                }
            }
        }
    }

    for (anorm& a : anorms)
    {
        pii newLoc = relocation({ a.y,a.x }, tWallTL, n,m);
        a.y = newLoc.first;
        a.x = newLoc.second;

        board[a.y][a.x] = 1;
        aBoard[a.y][a.x] = -1;
    }

    

    cout << "cost board=========" << '\n';

    for (int i = 0; i < costs.size(); ++i)
    {
        for (int j = 0; j < costs.size(); ++j)
        {
            cout << costs[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "============================\n";

    //vector<vector<int>> pBoard(n + 2 * m, vector<int>(n + 2 * m));
   
    //cout << "board=========" << '\n';

    //for (int i = 0; i < board.size(); ++i)
    //{
    //    for (int j = 0; j < board.size(); ++j)
    //    {
    //        cout << board[i][j] << ' ';
    //    }
    //    cout << '\n';
    //}
    //cout << "============================\n";

    //cout << "====twall=====" << '\n';
    //for (int i = 0; i < 3 * m; ++i)
    //{
    //    for (int j = 0; j < 3 * m; ++j)
    //    {
    //        cout << tWall[i][j] << ' ';
    //    }
    //    cout << '\n';
    //}
    //cout << "====================";
   


    // SPECIFY WHICH FACE HAS TWALL EXIT
    // FIND WAY OUT FROM TWALL
    vector<pii> path;
    pos = relocation(pos, tWallTL, n, m);
    bExit = relocation(bExit, tWallTL, n, m);
    board[bExit.first][bExit.second] = 0;
    findPathByDij(path, board, costs, pos, bExit);

    reverse(path.begin(), path.end());


    for (int i = 1; i <= path.size(); ++i)
    {
        for (anorm &a : anorms)
        {
            spread(board, aBoard, costs, a, i);
        }
    }

    cout << "anormaly board=========" << '\n';

    for (int i = 0; i < aBoard.size(); ++i)
    {
        for (int j = 0; j < aBoard.size(); ++j)
        {
            cout << aBoard[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "============================\n";

    for (int i = 0; i < path.size(); ++i)
    {
        cout << '(' << path[i].first << ',' << path[i].second << ") ";
    }
    cout << '\n';


    return 0;
}