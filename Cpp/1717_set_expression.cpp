#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    map<int, int> setInfo;
    vector<set<int>> sets;
    for (int i = 0; i <= n; ++i)
    {
        sets.push_back({i});
    }
    for (int i = 0; i < m; ++i)
    {
        int op, a, b; cin >> op >> a >> b;
        if (op == 0)
        {
            for (auto& s : sets)
            {
                if (s.contains(b))
                {
                    s.erase(b);
                    break;
                }
            }

            for (auto& s : sets)
            {
                if (s.contains(a))
                {
                    s.insert(b);
                    break;
                }
            }
        }
        else if (op == 1)
        {
            string ans = "NO";
            for (auto& s : sets)
            {
                if (s.contains(a) && s.contains(b)) ans = "YES";
            }
            cout << ans << '\n';
        }

    }
    return 0;
}