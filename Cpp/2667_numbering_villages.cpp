#include <iostream>   
#include <vector>
#include <algorithm>

using namespace std;

int graph[25][25];
bool visited[25][25];
vector<int> villages;
int vNum = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N;
void dfs(int r, int c) {
    visited[r][c] = 1;
    villages[vNum]++;

    for (int i = 0; i < 4; ++i)
    {
        int rr = r + dx[i];
        int cc = c + dy[i];
        if (rr >=0 && rr < N && cc >=0 && cc < N && !visited[rr][cc] && graph[rr][cc] == 1)
        {
            dfs(rr, cc);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string row; cin >> row;
        for (int j = 0;j<N;++j) 
        {
            graph[i][j] = row[j] - '0';
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (!visited[i][j] && graph[i][j] == 1)
            {
                villages.push_back(0);
                dfs(i, j);
                vNum++;
            }
        }
    }
    sort(villages.begin(), villages.end());

    cout << villages.size() << '\n';
    for (int i = 0; i < villages.size(); ++i)
    {
        cout << villages[i] << '\n';
    }
    return 0;
}