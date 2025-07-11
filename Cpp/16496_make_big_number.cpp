#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;

    auto comp = [](string a, string b) -> bool
        {
            return a + b < b + a;
        };

    priority_queue<string, vector<string>, decltype(comp)> pq(comp);

    for (int i = 0; i < N; ++i)
    {
        string n; cin >> n;
        pq.push(n);
    }

    if (pq.top() == "0")
    {
        cout << 0 << '\n';
        return 0;
    }

    while (!pq.empty())
    {
        string t = pq.top();
        pq.pop();
        cout << t;
    }

    cout << '\n';



    return 0;
}