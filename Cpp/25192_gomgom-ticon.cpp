#include <iostream>   
#include <set>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    set<string> gom;
    int count = 0;
    while (N--)
    {
        string s; cin >> s;
        if (s == "ENTER") { gom.clear(); }
        else if (gom.find(s) == gom.end()) { gom.insert(s); count++; }
    }

    cout << count << '\n';

    return 0;
}