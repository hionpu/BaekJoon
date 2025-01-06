#include <iostream>   
#include <stack>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int K; cin >> K;
    stack<int> st;
    while (K--)
    {
        int n; cin >> n;
        if (n == 0) st.pop(); 
        else st.push(n);

    }
    int sum = 0;
    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    cout << sum << '\n';

    return 0;
}