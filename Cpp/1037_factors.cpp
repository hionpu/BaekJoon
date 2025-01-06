#include <iostream>   
#include <set>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    set<int> s;
    while (N--) { int n; cin >> n; s.insert(n); }
    cout << *s.begin() * *(--s.end()) << '\n';

    return 0;
}