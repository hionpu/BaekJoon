#include <iostream>   

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int A, B, V;
    cin >> A >> B >> V;
    int ans = 0;
    ans = (int)((V - B-1) / (A-B)) + 1;
    cout << ans << '\n';
    


    return 0;
}