#include <iostream>   
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    // 그래프 구성 (인접 리스트)
    vector<vector<pair<int, int>>> graph(N + 1);
    vector<int> inDegree(N + 1, 0);
    vector<bool> isBasePart(N + 1, true); // 기본 부품 여부 체크

    for (int i = 0; i < M; ++i)
    {
        int X, Y, K;
        cin >> X >> Y >> K;
        graph[Y].push_back({ X, K }); // Y 부품이 X를 만드는데 K개 필요함
        inDegree[X]++;
        isBasePart[X] = false; // X는 중간/완제품
    }

    // DP 테이블: dp[i][j] = i번 부품 만드는데 들어가는 j번 기본 부품의 개수
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    // 기본 부품 식별 및 초기화
    for (int i = 1; i <= N; ++i)
    {
        if (isBasePart[i])
        {
            dp[i][i] = 1; // 기본 부품은 자기 자신을 1개 사용
        }
    }

    // 위상 정렬
    queue<int> q;
    for (int i = 1; i <= N; ++i)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (auto& [next, count] : graph[current])
        {
            // current 부품이 next 부품을 만드는데 count개 필요함
            for (int j = 1; j <= N; ++j)
            {
                if (dp[current][j] > 0)
                { // current가 j번 부품을 사용한다면(기본 또는 중간 부품)
                    dp[next][j] += dp[current][j] * count;
                }
            }

            inDegree[next]--;
            if (inDegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    // 완제품을 만드는데 필요한 기본 부품의 개수 출력
    for (int i = 1; i <= N; ++i)
    {
        if (isBasePart[i] && dp[N][i] > 0)
        {
            cout << i << " " << dp[N][i] << "\n";
        }
    }

    return 0;
}