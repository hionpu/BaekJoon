#include <iostream>   
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 1'000'000;

int arr[MAXN];
int freq[MAXN+1];
int ans[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    stack<int> st;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    for (int i = N - 1; i >= 0; --i)
    {
        while (!st.empty() && freq[arr[st.top()]] <= freq[arr[i]])
        {
            st.pop();
        }

        if (st.empty()) ans[i] = -1;
        else ans[i] = arr[st.top()];
        st.push(i);
    }

    for (int i = 0; i < N; ++i)
    {
        cout << ans[i] << " ";
    }

    return 0;
}