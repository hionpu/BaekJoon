#include <iostream>   
#include <stack>
#include <algorithm>

using namespace std;
const int MAXN = 100002;
int his[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    stack<int> st;

    int N; cin >> N;
    st.push(0);
    his[N+1] = 0;
    int ans = 0;
    for (int i = 1; i <= N; ++i) cin >> his[i];

    for (int i = 1; i <= N+1; ++i)
    {
        // while로 계속 pop 하다가 현재 top이 his[i]보다 작아지면 그만함
        while (st.top() !=0 && his[i] < his[st.top()])
        {
            // 이번에 탐색할 i-th column의 값이 스택의 top보다 작아지면 현재 높이를 top 값으로 정하고
            int currentIdx = st.top();
            // 스택 하나 pop
            st.pop();
            // 현재 높이 * 너비(= (i-1)-th column부터 pop 한 이후의 top)
            // 첫번째 top은 현재 높이인 자기 자신이므로 자기자신 to 자기자신 하면 너비는 0이고
            // pop 이후 top은 자기 자신의 바로 이전 인덱스니까 너비 1부터 시작
            ans = max(ans, his[currentIdx] * (i - st.top() - 1));
        }
        st.push(i);
    }


    cout << ans;
    return 0;
}