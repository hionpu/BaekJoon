#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include<map>
#include<sstream>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char d) : data(d), left(nullptr), right(nullptr) {}
};
map<char, Node*> nodes;

void buildTree(map<char, Node*>& nodes, string currentPost, string currentIn) {
    if (currentPost.empty() || currentIn.empty()) return;

    char root = *(currentPost.end() - 1);
    int rootPos = currentIn.find(root);
    string lsubIn = currentIn.substr(0, rootPos);
    string rsubIn = currentIn.substr(rootPos + 1);

    if (!nodes[root])
    {
        nodes[root] = new Node(root);
    }

    if (!lsubIn.empty())
    {
        string lsubPost = currentPost.substr(0, lsubIn.size());
        char leftRoot = *(lsubPost.end() - 1);
        if (!nodes[leftRoot])
        {
            nodes[leftRoot] = new Node(leftRoot);
        }
        nodes[root]->left = nodes[leftRoot];  // Link left child
        buildTree(nodes, lsubPost, lsubIn);
    }

    if (!rsubIn.empty())
    {
        string rsubPost = currentPost.substr(lsubIn.size(), rsubIn.size());
        char rightRoot = *(rsubPost.end() - 1);
        if (!nodes[rightRoot])
        {
            nodes[rightRoot] = new Node(rightRoot);
        }
        nodes[root]->right = nodes[rightRoot];  // Link right child
        buildTree(nodes, rsubPost, rsubIn);
    }
};

void static preorder(Node* node) {
    if (!node) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   
    int n; cin >> n;
    string inO;
    string postO;

    stringstream ss;
    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        ss << c;
    }
    inO = ss.str();

    ss.str("");
    ss.clear();

    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        ss << c;
    }
    postO = ss.str();

    buildTree(nodes, postO, inO);

    char root = *(postO.end() - 1);
    preorder(nodes[root]);
    cout << '\n';

    for (auto& p : nodes) delete p.second;
    return 0;
}