#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    vector<int> v;
    v.push_back(1);
    int mult = 1;
    for (int i = 1; i < N; ++i)
    {
        v.push_back(v[i - 1]+ mult * (N - i));
        mult = mult * -1;
    }

    for (auto& n : v) cout << n << ' ';
    cout << '\n';

    return 0;
}