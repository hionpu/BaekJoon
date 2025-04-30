#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;

    vector<int> v;
    int start = N % 2 ==0 ? N / 2 : N / 2+1;
    v.push_back(start);
    for (int i = 1; i < N; ++i)
    {
        int mult = pow(-1, i + 1);
        int diff = i % 2 ? 0 : 1; 
        v.push_back(v[i - 1] + mult * (N / 2 + diff));
    }

    for (auto& x : v) cout << x << ' ';
    cout << '\n';

    return 0;
}