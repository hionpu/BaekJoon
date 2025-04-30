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

    int need = sqrt(2 * N)+2;
    if (need % 2 ==0) need++;

    for (int i = 1; i <= need / 2; ++i)
    {
        cout << i << ' ';
        cout << need - i << ' ';
    }
    
    return 0;
}