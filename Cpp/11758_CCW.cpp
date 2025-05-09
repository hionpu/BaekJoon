#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    pii P1, P2, P3; 
    cin >> P1.first >> P1.second >> P2.first >> P2.second >> P3.first >> P3.second;

    pii P1P2 = { P2.first - P1.first, P2.second - P1.second };
    pii P2P3 = { P3.first - P2.first, P3.second - P2.second };

    double z;
    z = P1P2.first * P2P3.second - P1P2.second * P2P3.first;

    if (z == 0) cout << z << '\n';
    else cout << z / abs(z) << '\n';
    
    return 0;

}