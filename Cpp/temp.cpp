#include <iostream>   
#include <cmath>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K, numer = 1, deno = 1; cin >> N >> K;
    
    while (K--)
    {
        numer *= N-- ;
        deno *= K + 1;
    }
    cout << numer/deno;
    return 0;
}