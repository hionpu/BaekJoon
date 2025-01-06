#include <iostream>   
#include <stack>
#include <string>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        bool balanced = true;
        string s; getline(cin, s);
        if (s == ".") break;
        stack<char> st;
        for (const auto& c : s)
        {
            if (c == '(' || c == '[')
            {
                st.push(c);
            }
            if (c == ')')
            {
                if (st.empty())
                {
                    balanced = false;
                    break;
                }
                if (st.top() == '(') st.pop();
                else
                {
                    balanced = false;
                    break;
                }
            }
            if (c == ']')
            {
                if (st.empty())
                {
                    balanced = false;
                    break;
                }
                if (st.top() == '[') st.pop();
                else
                {
                    balanced = false;
                    break;
                }
            }
        }
        if (!st.empty()) balanced = false;
        if (balanced) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
    return 0;
}