#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<int>> graph;
vector<int> id;
vector<bool> finished;
vector<int> sccIdx;
vector<int> sccInDegree;
stack<int> s;
int sccNum;
vector<vector<int>> SCC;
int idx;

int DFS(int n) {
	id[n] = ++idx;
	s.push(n);

	int result = id[n];
	for (auto& next : graph[n])
	{
		if (id[next] == 0) result = min(result, DFS(next));
		else if (!finished[next]) result = min(result, id[next]);
	}

	if (result == id[n])
	{
		vector<int> scc;
		while (true)
		{
			int top = s.top();
			s.pop();
			scc.push_back(top);
			finished[top] = true;
			sccIdx[top] = sccNum;
			if (top == n) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
		sccNum++;
	}


	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;

	for (int test = 0; test < T; ++test)
	{
		int N, M; cin >> N >> M;
		graph.assign(N, vector<int>());
		id.assign(N, 0);
		idx = 0;
		sccNum = 0;
		finished.assign(N, false);
		sccIdx.assign(N, 0);
		SCC.clear();
		while (!s.empty()) s.pop();

		for (int i = 0; i < M; ++i)
		{
			int A, B; cin >> A >> B;
			graph[A].push_back(B);
		}

		for (int i = 0; i < N; ++i)
		{
			if (id[i] == 0) DFS(i);
		}

		sccInDegree.assign(sccNum, 0);

		for (int i = 0; i < N; ++i)
		{
			for (auto& next : graph[i])
			{
				if (sccIdx[i] != sccIdx[next]) sccInDegree[sccIdx[next]]++;
			}
		}

		int zeroDegreeCount = 0;
		int zeroDegreeScc = -1;
		for (int i = 0; i < sccInDegree.size(); ++i)
		{
			if (sccInDegree[i] == 0)
			{
				zeroDegreeScc = i;
				zeroDegreeCount++;
			}
		}

		if (zeroDegreeCount != 1) cout << "Confused" << '\n';
		else
		{
			vector<int> scc = SCC[zeroDegreeScc];
			for (auto& node : scc)
			{
				cout << node << '\n';
			}

		}

		cout << '\n';

	}

	return 0;
}