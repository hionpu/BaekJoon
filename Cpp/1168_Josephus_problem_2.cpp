#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <functional>

using namespace std;

struct segTree {
private:
    int n;
    vector<int> tree;

    void init(int start, int end, int node) {
        if (start == end)
        {
            tree[node] = 1;
            return;
        }

        int mid = (start + end) / 2;
        init(start, mid, node * 2);
        init(mid + 1, end, node * 2 + 1);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int jDeleteHelper(int start, int end, int node, int rank) {
        if (start == end)
        {
            tree[node]--;
            return start;
        }

        int mid = (start + end) / 2;
        int target = 0;
        if (rank <= tree[node * 2])
        {
            target = jDeleteHelper(start, mid, node * 2, rank);
        }
        else target = jDeleteHelper(mid + 1, end, node * 2 + 1, rank - tree[node * 2]);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
        return target;
    }

public:
    segTree(int n) {
        this->n = n;
        tree.resize(4 * n);
        
        init(0, n - 1, 1);
    }

    int jDelete(int rank) {
        return jDeleteHelper(0, n - 1, 1, rank);
    }

    function<int()> numRemain = [&]() -> int { return tree[1]; };

    
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K; cin >> N >> K;

    segTree st(N);
    vector<int> ans;
    int currentPos = 0;

    while (st.numRemain() > 0)
    {
        int d = st.numRemain();
        currentPos = (currentPos + K - 1) % d;
        int rank = currentPos + 1;

        int removed = st.jDelete(rank);
        ans.push_back(removed+1);
    }

    cout << '<';
    for (int i = 0; i<ans.size(); ++i)
    {
        cout << ans[i];
        if (i < ans.size() - 1) cout << ", ";
    }
    cout << '>' << '\n';

    return 0;
}