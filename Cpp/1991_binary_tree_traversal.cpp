#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char d) : data(d), left(nullptr), right(nullptr) {}
};

void buildTree(map<char, Node*>& nodes, char parent, char left, char right) {
    if (!nodes[parent]) nodes[parent] = new Node(parent);
    if (left != '.' && !nodes[left]) nodes[left] = new Node(left);
    if (right != '.' && !nodes[right]) nodes[right] = new Node(right);

    nodes[parent]->left = (left != '.') ? nodes[left] : nullptr;
    nodes[parent]->right = (right != '.') ? nodes[right] : nullptr;
};

void preorder(Node* root) {
    if (!root) return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    map<char, Node*> nodes;

    for (int i = 0; i < n; ++i)
    {
        char p, l, r; cin >> p >> l >> r;
        buildTree(nodes, p, l, r);
    }

    Node* root = nodes['A'];

    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';

    for (auto& pair : nodes) delete pair.second;

    return 0;
}