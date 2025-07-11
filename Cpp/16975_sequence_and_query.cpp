// segment tree
// difference array


#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using ll = long long;

// segment tree version
struct segTree {
private:
    int n;
    vector<ll> arr;
    vector<ll> tree;

    void init(int start, int end, int node) {
        if (start == end)
        {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        init(start, mid, node * 2);
        init(mid + 1, end, node * 2 + 1);
    }

    void addDiffHelper(int start, int end, ll node, int left, int right, int diff) {
        if (right < start || end < left) return;
        if (left <= start && end <= right)
        {
            tree[node] += diff;
            return;
        }

        int mid = (start + end) / 2;
        addDiffHelper(start, mid, node * 2, left, right, diff);
        addDiffHelper(mid + 1, end, node * 2 + 1, left, right, diff);
    }

    ll getLeafHelper(int start, int end, ll node, int idx) {
        if (idx < start || end < idx) return 0;
        if (start == end) return tree[node];
        
        int mid = (start + end) / 2;
        return tree[node] + getLeafHelper(start, mid, node * 2, idx) + getLeafHelper(mid + 1, end, node * 2 + 1, idx);
    }

public:
    segTree(vector<ll>& arr) {
        this->n = arr.size();
        this->arr = arr;
        tree.resize(4 * n);

        init(0, n - 1, 1);
    }

    void addDiff(int left, int right, int diff) {
        return addDiffHelper(0, n - 1, 1, left, right, diff);
    }

    ll getLeaf(int idx) {
        return getLeafHelper(0, n - 1, 1, idx);
    }
};

//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//
//    int N; cin >> N;
//    vector<ll> arr(N);
//    
//    for (int i = 0; i < N; ++i)
//    {
//        cin >> arr[i];
//    }
//    segTree st(arr);
//    int M; cin >> M;
//
//    while (M--)
//    {
//        int q; cin >> q;
//        if (q == 1)
//        {
//            int left, right, diff;
//            cin >> left >> right >> diff;
//            st.addDiff(left-1, right-1, diff);
//        }
//        else if (q == 2)
//        {
//            int x; cin >> x;
//            cout << st.getLeaf(x-1) << '\n';
//        }
//    }
//
//    return 0;
//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    vector<int> arr(N);
    vector<int> diff(N + 1);
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int M; cin >> M;
    
    while (M--)
    {
        int q; cin >> q;
        if (q == 1)
        {
            int i, j, k; cin >> i >> j >> k;
            diff[i - 1] += k;
            diff[j] -= k;
        }
        else if (q == 2)
        {
            int x; cin >> x;
            ll ans = arr[x - 1];
            for (int d = 0; d < x;++d) 
            {
                ans += diff[d];
            }
            cout << ans << '\n';
        }
    }
}
