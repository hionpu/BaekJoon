#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct node {
    int parent;
    int num;
    vector<int> child;
    int count;
};

void make_tree(vector<node>& tree, vector<vector<int>>& graph, int current, int parent) {
    tree[current].parent = parent;

    for (int next : graph[current])
    {
        if (next != parent)
        {
            tree[current].child.push_back(next);
            make_tree(tree, graph, next, current);
        }
    }
}

int count_sub_tree(vector<node>& tree, int current) {
    tree[current].count = 1;
    for (int child : tree[current].child)
    {
        tree[current].count += count_sub_tree(tree, child);
    }

    return tree[current].count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, R, Q; cin >> N >> R >> Q;

    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < N-1; ++i)
    {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<node> tree(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        tree[i].num = i;
        tree[i].count = 0;
    }

    make_tree(tree, graph, R, 0);

    count_sub_tree(tree, R);

    for (int i = 0; i < Q; ++i)
    {
        int n; cin >> n;
        cout << tree[n].count << '\n';
    }

    return 0;
}