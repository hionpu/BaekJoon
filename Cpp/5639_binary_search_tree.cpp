#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void postorder(vector<int>& preorder, int start, int end) {
    if (start > end) return;

    int i = start + 1;
    for (; i <= end; ++i)
    {
        if (preorder[start] < preorder[i]) break;
    }

    postorder(preorder, start + 1, i - 1);
    postorder(preorder, i, end);
    cout << preorder[start] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> preorder;
    int x;
    while (cin >> x)
    {
        if (x == -1) break;
        preorder.push_back(x);
    }

    postorder(preorder, 0, preorder.size() - 1);

    return 0;
}