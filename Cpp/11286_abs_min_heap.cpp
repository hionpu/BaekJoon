#include <iostream>   
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    auto comp = [](int lhs, int rhs)
        {
            if (abs(lhs) == abs(rhs)) return lhs > rhs;
            return abs(lhs) > abs(rhs);
        };

    priority_queue<int, vector<int>, decltype(comp)> pq(comp);

    auto couter = [](const int& x) { cout << x << '\n'; };

    int N; cin >> N;

    vector<int> output;
    output.reserve(N);

    while (N--)
    {
        int x; cin >> x;

        if (x == 0)
        {
            if (pq.empty()) output.push_back(0);
            else
            {
                output.push_back(pq.top());
                pq.pop();
            }
        }
        else
        {
            pq.push(x);
        }
    }

    for_each(output.begin(), output.end(), couter);

    return 0;
}