#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


struct DS {
private:
    vector<int> parent;
    vector<int> diff;
    
public:
    DS(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
        }
        diff.assign(n + 1, 0);
    }

    // 여기도 다시 봐야함
    int getParent(int a) {
        if (parent[a] == a) return a;
        int p = getParent( parent[a]);
        diff[a] += diff[parent[a]];
        parent[a] = p;
        return p;
    }
    
    // 이 부분 다시 봐야함
    void join(int c, int p, int w) {
        int rootC = getParent(c);
        int rootP = getParent(p);

        if (rootC == rootP) return;

        diff[rootC] = diff[p] - diff[c] + w;
        parent[rootC] = rootP;
    }

    bool sameSet(int a, int b) {
        return getParent(a) == getParent(b);
    }

    int getDiff(int a, int b) {
        if (!sameSet(a, b)) return -1;
        return diff[a] - diff[b];
    
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   
    while (true)
    {
        int N, M; cin >> N >> M;
        if (N == 0 && M == 0) break;
        DS ds(N);

        for (int i = 0; i < M; ++i)
        {
			char c;
			cin >> c;
			int a, b; cin >> a >> b;
			
			if (c == '!')
			{
				int w; cin >> w;
				ds.join(a, b, w);
			}
			else if (c == '?')
			{
				if (!ds.sameSet(a, b)) cout << "UNKNOWN" << '\n';
				else cout << ds.getDiff(a, b) << '\n';
			}

        }
    }
    
    return 0;
}