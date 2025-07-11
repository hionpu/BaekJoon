#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct seg {
    int start;
    int end;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M; cin >> N >> M;
    vector<seg> backwards;

    for (int i = 0; i < N; ++i)
    {
        int s, e; cin >> s >> e;
        if (s > e)
        {
            backwards.push_back({ e,s });
        }
    }

    sort(backwards.begin(), backwards.end(), [](seg a, seg b) -> bool
        {
            return a.start < b.start;
        });

    int start, end;
    start = end = -1;
    long long backLen = 0;
    for (auto& s : backwards)
    {
        if (end < s.start)
        {
            backLen += s.end - s.start;
            start = s.start;
            end = s.end;
        }
        else if (end < s.end)
        {
            backLen += s.end - end;
            end = s.end;
        }
    }
    long long ans = 2 * backLen + M;
    cout << ans << '\n';
    
    return 0;
}