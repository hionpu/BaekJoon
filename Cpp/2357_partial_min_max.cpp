// DataStructure
// SegementTree

#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using minMax = pair<int, int>;


struct segTree {

private:
    const int gMIN = 0;
    const int gMAX = 1'000'000'001;
    int n;
    vector<int> arr;
    vector<minMax> minMaxTree;

    minMax minMaxHelper(int start, int end, int node, int left, int right) {
        if (right < start || end < left) return { gMAX, gMIN };
        
        if (left <= start && end <= right) return minMaxTree[node];

        int mid = (start + end) / 2;
        minMax leftNode = minMaxHelper(start, mid, node * 2, left, right);
        minMax rightNode = minMaxHelper(mid + 1, end, node * 2 + 1, left, right);
        return { min(leftNode.first, rightNode.first), max(leftNode.second, rightNode.second) };
    }

public:
    segTree(vector<int>& arr) {
        this->n = arr.size();
        this->arr = arr;
        minMaxTree.resize(4 * n);
        init(0, n - 1, 1);
    }

    void init(int start, int end, int node) {
        if (start == end)
        {
            minMaxTree[node] = { arr[start], arr[start] };
            return;
        }

        int mid = (start + end) / 2;
        init(start, mid, node * 2);
        init(mid + 1, end, node * 2 + 1);

        minMaxTree[node] = { min(minMaxTree[node * 2].first, minMaxTree[node * 2 + 1].first), 
            max(minMaxTree[node * 2].second, minMaxTree[node * 2 + 1].second) };
    }

    minMax getMinMax(int left, int right) {
        return minMaxHelper(0, n - 1, 1, left, right);
    }

};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M; cin >> N >> M;
    vector<int> arr(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    
    segTree st(arr);

    for (int i = 0; i < M; ++i)
    {
        int a, b; cin >> a >> b;
        minMax mm = st.getMinMax(a-1, b-1);
        cout << mm.first << ' ' << mm.second << '\n';
    }

    return 0;
}