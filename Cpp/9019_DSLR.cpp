#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int D(int x) {
    return (2 * x) % 10000;
}

int S(int x) {
    return x - 1 >= 0 ? x - 1 : x - 1 + 10000;
}

int L(int x) {
    int d1, d2, d3, d4;
    d1 = x / 1000;
    d2 = (x%1000) / 100;
    d3 = (x % 100) / 10;
    d4 = (x % 10);
    return d2 * 1000 + d3 * 100 + d4 * 10 + d1;
}

int R(int x) {
    int d1, d2, d3, d4;
    d1 = x / 1000;
    d2 = (x % 1000) / 100;
    d3 = (x % 100) / 10;
    d4 = (x % 10);
    return d4 * 1000 + d1 * 100 + d2 * 10 + d3;
}
pair<int, char> prevs[10001];
bool visited[10001];
char funcs[4] = { 'D', 'S', 'L','R' };
queue<int> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int T; cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int A, B; cin >> A >> B;
        q.push(A);
        for (int i = 0; i <= 10000; ++i)
        {
            visited[i] = false;
        }
        while (!q.empty())
        {
            int fr = q.front();
            q.pop();
            visited[fr] = true;
            if (fr == B) break;
            int d = D(fr);
            int s = S(fr);
            int l = L(fr);
            int r = R(fr);

            int arr[4] = {d,s,l,r};

            for (int i = 0; i < 4; ++i)
            {
                if (visited[arr[i]]) continue;

                visited[arr[i]] = true;
                
                prevs[arr[i]] = { fr, funcs[i] };
                q.push(arr[i]);
            }
        }

        int current = B;
        vector<char> path;
        while (current != A)
        {
            auto p = prevs[current];
            current = p.first;
            path.push_back(p.second);
        }

        reverse(path.begin(), path.end());

        for (auto& c : path)
        {
            cout << c;
        }

        cout << '\n';

        while (!q.empty()) q.pop();
    }
    return 0;
}