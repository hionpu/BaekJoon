#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int N; cin >> N;
        vector<int> parent(N + 1);
        parent[0] = -1;
        for (int i = 1; i <= N - 1; ++i)
        {
            int A, B; cin >> A >> B;
            parent[B] = A;
        }

        int a, b; cin >> a >> b;
        int root = 0;
        for (int i = 1; i <= N; ++i)
        {
            if (parent[i] == 0)
            {
                root = i;
                break;
            }
        }

        vector<int> parentPathA;
        vector<int> parentPathB;

        int current = a;
        while (current != 0)
        {
            parentPathA.push_back(current);
            current = parent[current];
        }

        current = b;
        while (current != 0)
        {
            parentPathB.push_back(current);
            current = parent[current];
        }

        int LCA = 0;
        for (int nodeA : parentPathA)
        {
            for (int nodeB : parentPathB)
            {
                if (nodeA == nodeB)
                {
                    LCA = nodeA;
                    goto found; // Break out of both loops
                }
            }
        }

    found:

        cout << LCA << '\n';

    }

    return 0;
}