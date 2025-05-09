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

    for (int i = 1; i <= N; i+=2)
    {
        v.push_back(i);
    }

    for (int i = 2 * (N / 2); i >=2; i -= 2)
    {
        v.push_back(i);
    }

    for (int i = 0; i < N; ++i)
    {
        cout << v[i] << ' ';
    }

    cout << '\n';

    return 0;
}