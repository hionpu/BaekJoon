#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
const int QMAX = 100000;
struct SegTree {
	vector<int> count;
	vector<ll> sum;

	SegTree() {
		sum.resize(4 * QMAX);
		count.resize(4 * QMAX);
	}


private:
	void update(int node, int l, int r, int idx, int delta) {
		if (idx < l || idx > r) return;
		sum[node] += (ll)(idx * delta);
		count[node] += delta;
		if (l == r) return;
		int mid = (l + r) / 2;
		update(2 * node, l, mid, idx, delta);
		update(2 * node + 1, mid + 1, r, idx, delta);
	}

	ll query(int node, int l, int r, int ql, int qr) {
		if (qr < l || r > ql) return 0;
		if (ql <= l && r <= qr) return sum[node];
		int mid = (l + r) / 2;
		return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
	}

	int kth(int node, int l, int r, int k) {
		if (count[node] < k) return -1;
		if (l == r) return l;

		int mid = (l + r) / 2;
		if (count[node] >= k) return kth(2 * node, l, mid, k);
		else return kth(2 * node + 1, mid + 1, r, k - count[2*node]);
	}

public:
	void init() {
		sum.clear();
		sum.resize(4 * QMAX);
	}

	void qIns(int idx) {
		update(1, 1, QMAX, idx, 1);
	}

	void qDel(int idx) {
		update(1, 1, QMAX, idx, -1);
	}

	ll qSum(int qr) {
		return query(1, 1, QMAX, 1, qr);
	}

	int qRank(int k) {
		return kth(1, 1, QMAX, k);
	}

	int qCount() {
		return count[1];
	}

};


void qinit(SegTree& st, set<int> s, map<string, int>& ntov, map<int, string>& vton) {
	st.init();
	s.clear();
	ntov.clear();
	vton.clear();
}

void qinsert(SegTree& st, set<int> v, map<string, int>& ntov, map<int, string>& vton, string n, int val) {
	if (ntov.find(n) == ntov.end() || vton.find(val) == vton.end())
	{
		cout << 0 << '\n';
		return;
	}

	st.qIns(val);
	ntov[n] = val;
	vton[val] = n;
	v.insert(val);

	cout << 1 << '\n';
}

void qdel(SegTree& st, set<int>& s, map<string, int>& ntov, map<int, string>& vton, string name) {
	if (ntov.find(name) == ntov.end())
	{
		cout << 0 << '\n';
		return;
	}

	int val = ntov[name];
	vton.erase(val);
	ntov.erase(name);

	st.qDel(s.size());
	s.erase(val);

	cout << val << '\n';

}

void qrank(SegTree& st, map<int, string>& vton, int k) {
	if (st.qCount() <= k - 1)
	{
		cout << "None" << '\n';
		return;
	}

	cout << vton[st.qRank(k)] << '\n';
}

void qsum(SegTree& st, int k) {


	cout << st.qSum(k) << '\n';
}

int main() {

	int q; cin >> q;
	set<int> v;
	map<string, int> ntov;
	map<int, string> vton;
	SegTree st = SegTree();

	for (int i = 0; i < q; ++i)
	{
		string s; cin >> s;
		if (s == "init")
		{
			st.init();
		}
		else if (s == "insert")
		{
			string n;
			int val;
			cin >> n >> val;
			qinsert(st, v, ntov, vton, n, val);

			//cout << n << ' ' << val << '\n';
		}
		else if (s == "delete")
		{
			string n;
			cin >> n;
			qdel(st, v, ntov, vton, n);
		}
		else if (s == "rank")
		{
			int k;
			cin >> k;
			qrank(st, vton, k);
		}
		else if (s == "sum")
		{
			int k;
			cin >> k;
			qsum(st, k);
			//cout << k << '\n';
		}

	}
	/*for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << ' ';

	}
	cout << '\n';*/

	return 0;


}