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
        // while�� ��� pop �ϴٰ� ���� top�� his[i]���� �۾����� �׸���
        while (st.top() !=0 && his[i] < his[st.top()])
        {
            // �̹��� Ž���� i-th column�� ���� ������ top���� �۾����� ���� ���̸� top ������ ���ϰ�
            int currentIdx = st.top();
            // ���� �ϳ� pop
            st.pop();
            // ���� ���� * �ʺ�(= (i-1)-th column���� pop �� ������ top)
            // ù��° top�� ���� ������ �ڱ� �ڽ��̹Ƿ� �ڱ��ڽ� to �ڱ��ڽ� �ϸ� �ʺ�� 0�̰�
            // pop ���� top�� �ڱ� �ڽ��� �ٷ� ���� �ε����ϱ� �ʺ� 1���� ����
            ans = max(ans, his[currentIdx] * (i - st.top() - 1));
        }
        st.push(i);
    }


    cout << ans;
    return 0;
}