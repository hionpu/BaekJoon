#include <iostream>   
#include <stack>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 500'001;
int h[MAXN];



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int people_num;
    cin >> people_num;

    stack<pair<int, int>> st;
    int now, cnt_same_height = 0;
    long long  cnt_pair = 0;

    for (int i = 0; i < people_num; ++i)
    {
        cin >> now;

        cnt_same_height = 1;
        while (!st.empty() && st.top().first < now)
        {
            cnt_pair += st.top().second;
            st.pop();
        }

        if (!st.empty())
        {
            if (st.top().first == now)
            {
                cnt_pair += st.top().second;
                cnt_same_height = (st.top().second + 1);
                if (st.size() > 1)
                    ++cnt_pair;

                st.pop();
            }
            else
            {
                ++cnt_pair;
            }
        }

        st.push(make_pair(now, cnt_same_height));
    }

    cout << cnt_pair << '\n';
    return 0;
}