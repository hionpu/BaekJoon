#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

void qinit(vector<int>& v, map<string, int>& ntov, map<int, string>& vton) {
	v.clear();
	ntov.clear();
	vton.clear();
}

void qinsert(set<int>& v, map<string, int>& ntov, map<int, string>& vton, string name, int value) {
	if (ntov.find(name) != ntov.end() || vton.find(value) != vton.end())
	{
		cout << 0 << '\n';
		return;
	}
	ntov[name] = value;
	vton[value] = name;
	v.insert(value);

	cout << 1 << '\n';

	//for (int i = 0; i < v.size(); ++i)
	//{
	//	cout << v[i] << ' ';

	//}
	//cout << '\n';
}

void qdel(set<int>& v, map<string, int>& ntov, map<int, string>& vton, string name) {
	if (ntov.find(name) == ntov.end())
	{
		cout << 0 << '\n';
		return;
	}

	int val = ntov[name];
	vton.erase(val);
	ntov.erase(name);

	vector<int>::iterator it = find(v.begin(), v.end(), val);
	v.erase(it);
	cout << val << '\n';

}

void qrank(set<int>& v, map<int, string>& vton, int k) {
	if (v.size() <= k - 1)
	{
		cout << "None" << '\n';
		return;
	}

	cout << vton[v[k - 1]] << '\n';
}

void qsum(set<int>& v, int k) {
	if (v.size() == 0 || v[0] > k)
	{
		cout << 0 << '\n';
		return;

	}
	vector<int>::iterator it = upper_bound(v.begin(), v.end(), k);
	long long ans = 0;
	int idx = it - v.begin();
	for (int i = 0; i < idx; ++i)
	{
		ans += v[i];
	}

	cout << ans << '\n';
}

int main() {

	int q; cin >> q;
	set<int> v;
	map<string, int> ntov;
	map<int, string> vton;

	for (int i = 0; i < q; ++i)
	{
		string s; cin >> s;
		if (s == "init")
		{
			qinit(v, ntov, vton);
		}
		else if (s == "insert")
		{
			string n;
			int val;
			cin >> n >> val;
			qinsert(v, ntov, vton, n, val);
			//cout << n << ' ' << val << '\n';
		}
		else if (s == "delete")
		{
			string n;
			cin >> n;
			qdel(v, ntov, vton, n);
		}
		else if (s == "rank")
		{
			int k;
			cin >> k;
			qrank(v, vton, k);
		}
		else if (s == "sum")
		{
			int k;
			cin >> k;
			qsum(v, k);
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