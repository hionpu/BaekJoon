#include <iostream>   
#include <stack>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--)
    {
    stack<bool> st;
        string s; cin >> s;
        for (const auto& c : s)
        {
            if (c == '(') st.push(0);
            else if (c == ')' && st.empty())
            {
                st.push(0);
                break;
            }
            else st.pop();
        }
        if (st.empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}