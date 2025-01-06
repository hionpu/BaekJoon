#include <iostream>   
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    queue<int> q;
    for (int i = 1; i <= N; i++) q.push(i);

    while (true)
    {
        if (q.size() == 1) break;
        q.pop();
        int front = q.front();
        q.pop();
        q.push(front);
    }
    cout << q.front() << '\n';
    return 0;
}