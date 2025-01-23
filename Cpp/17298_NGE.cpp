#include <iostream>   
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 1'000'000;

int arr[MAXN];
int ans[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    stack<int> st;
    
    for (int i = 0; i < N;  ++i) cin >> arr[i];

    for (int i = N-1; i >=0 ; --i)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        if (st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(arr[i]);
    }

    for (int i = 0; i < N; ++i)
    {
        cout << ans[i] << " ";
    }

    return 0;
}