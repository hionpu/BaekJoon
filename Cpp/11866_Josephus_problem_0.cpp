#include <iostream>   
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K; cin >> N >> K;
    queue<int> result;
    queue<int> q;
    for (int i = 1; i <= N; i++) q.push(i);

    int counter = 1;
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        if (counter % K != 0) q.push(n);
        else result.push(n);
        counter++;
    }

    cout << '<';
    while (result.size() > 1)
    {
        cout << result.front() << ", ";
        result.pop();
    }
    cout << result.front() << '>' << '\n';
    return 0;
}