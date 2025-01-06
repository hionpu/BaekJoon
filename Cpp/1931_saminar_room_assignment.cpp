#include <iostream>   
#include <vector>
#include <algorithm>

using namespace std;
int N;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<pair<int, int>> times;

    for (int i = 0; i < N; i++)
    {
        int s, e;
        cin >> s >> e;
        times.push_back(make_pair(s, e));
    }

    sort(times.begin(), times.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool
        {
            if (a.second != b.second)
                return a.second < b.second;
            else
                return a.first < b.first;
        });
    
    int count = 1;
    pair<int, int> currentSem = times[0];

    for (int i = 1; i < N; i++)
    {
        auto nextSem = times[i];
        if (nextSem.first >= currentSem.second)
        {
            currentSem = nextSem;
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}