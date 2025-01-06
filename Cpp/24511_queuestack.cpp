#include <iostream>   
#include <deque>

using namespace std;

const int N_MAX = 100000;
int sq[N_MAX];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M; cin >> N;
    
    deque<int> dq;
    for (int i = 0; i < N; i++)
    {
        int n; cin >> n; sq[i] = n;
    }

    for (int i = 0; i < N; i++)
    {
        int n; cin >> n;
        if (!sq[i]) dq.push_back(n);
    }

    cin >> M;

    while (M--)
    {
        int m; cin >> m;
        dq.push_front(m);
        cout << dq.back() << ' ';
        dq.pop_back();
    }
    

    return 0;
}