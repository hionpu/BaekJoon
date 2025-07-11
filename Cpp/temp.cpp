#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



#define MAX_N 75001

int tree[MAX_N * 4];

vector<pair<int, int> > vec;

vector<int> y_vec;



void init_tree(int now, int start, int end) {

	if (start > end) return;

	if (start == end)
	{

		tree[now] = 0;

		return;

	}

	tree[now] = 0;

	int mid = (start + end) / 2;

	init_tree(now * 2, start, mid);

	init_tree(now * 2 + 1, mid + 1, end);

}



void update_tree(int now, int target, int start, int end) {

	if (target > end || target < start) return;

	if (start == end)
	{

		tree[now]++;

		return;

	}

	int mid = (start + end) / 2;

	update_tree(now * 2, target, start, mid);

	update_tree(now * 2 + 1, target, mid + 1, end);

	tree[now] = tree[now * 2] + tree[now * 2 + 1];

}



int query(int now, int left, int right, int start, int end) {

	if (left > end || right < start) return 0;

	if (left <= start && end <= right)
	{

		return tree[now];

	}

	int mid = (start + end) / 2;

	return (

		query(now * 2, left, right, start, mid) +

		query(now * 2 + 1, left, right, mid + 1, end)

		);

}



bool cmp_x_y(pair<int, int> a, pair<int, int> b) {

	if (a.first == b.first) return a.second > b.second;

	return a.first < b.first;

}



bool cmp_y(int a, int b) {

	return a > b;

}



int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	int T; cin >> T;

	while (T--)
	{

		int N; cin >> N;

		vec.clear();

		y_vec.clear();

		init_tree(1, 0, N - 1);

		for (int i = 0; i < N; i++)
		{

			int x, y; cin >> x >> y;

			vec.push_back({ x,y });

			y_vec.push_back(y);

		}

		long long  ret = 0;

		sort(vec.begin(), vec.end(), cmp_x_y);

		sort(y_vec.begin(), y_vec.end(), cmp_y);

		for (int i = 0; i < vec.size(); i++)
		{

			int x = vec[i].first, y = vec[i].second;

			int index = upper_bound(y_vec.begin(), y_vec.end(), y, cmp_y) - y_vec.begin() - 1;

			ret += query(1, 0, index, 0, N - 1);

			update_tree(1, index, 0, N - 1);

		}

		cout << ret << "\n";

	}

}
