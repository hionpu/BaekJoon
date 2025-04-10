#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> inorder, postorder;
vector<int> position;

void static preorder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return;

    int root = postorder[postEnd];
    cout << root << ' ';

    int p = position[root];
    int leftLength = p - inStart;
    
    // left part
    preorder(inStart, p - 1, postStart, postStart + leftLength - 1);

    // right part
    preorder(p + 1, inEnd, postStart + leftLength, postEnd - 1);
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    inorder.resize(n);
    postorder.resize(n);
    position.resize(n + 1);

    for (int i = 0; i < n; ++i)
    {
        cin >> inorder[i];
        position[inorder[i]] = i;
    }

    for (int i = 0; i < n; ++i) cin >> postorder[i];

    preorder(0, n - 1, 0, n - 1);

    return 0;
}