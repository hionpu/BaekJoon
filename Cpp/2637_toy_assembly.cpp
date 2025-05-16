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

    // �׷��� ���� (���� ����Ʈ)
    vector<vector<pair<int, int>>> graph(N + 1);
    vector<int> inDegree(N + 1, 0);
    vector<bool> isBasePart(N + 1, true); // �⺻ ��ǰ ���� üũ

    for (int i = 0; i < M; ++i)
    {
        int X, Y, K;
        cin >> X >> Y >> K;
        graph[Y].push_back({ X, K }); // Y ��ǰ�� X�� ����µ� K�� �ʿ���
        inDegree[X]++;
        isBasePart[X] = false; // X�� �߰�/����ǰ
    }

    // DP ���̺�: dp[i][j] = i�� ��ǰ ����µ� ���� j�� �⺻ ��ǰ�� ����
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    // �⺻ ��ǰ �ĺ� �� �ʱ�ȭ
    for (int i = 1; i <= N; ++i)
    {
        if (isBasePart[i])
        {
            dp[i][i] = 1; // �⺻ ��ǰ�� �ڱ� �ڽ��� 1�� ���
        }
    }

    // ���� ����
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
            // current ��ǰ�� next ��ǰ�� ����µ� count�� �ʿ���
            for (int j = 1; j <= N; ++j)
            {
                if (dp[current][j] > 0)
                { // current�� j�� ��ǰ�� ����Ѵٸ�(�⺻ �Ǵ� �߰� ��ǰ)
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

    // ����ǰ�� ����µ� �ʿ��� �⺻ ��ǰ�� ���� ���
    for (int i = 1; i <= N; ++i)
    {
        if (isBasePart[i] && dp[N][i] > 0)
        {
            cout << i << " " << dp[N][i] << "\n";
        }
    }

    return 0;
}