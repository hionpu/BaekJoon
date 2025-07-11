#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

class TwoSAT {
private:
	int N;
	vector<vector<int>> graph;
	vector<bool> finished;
	stack<int> st;
	int idx;
	int sccNum;

	int DFS(int n) {
		id[n] = ++idx;
		st.push(n);
		int result = id[n];

		for (int next : graph[n])
		{
			if (id[next] == 0) result = min(result, DFS(next));
			else if (!finished[next]) result = min(result, id[next]);
		}

		if (result == id[n])
		{
			vector<int> scc;

			while (true)
			{
				int top = st.top();
				st.pop();
				finished[top] = true;
				scc.push_back(top);
				nodeToScc[top] = sccNum;

				if (top == n) break;
			}

			Scc.push_back(scc);
			sccNum++;
		}

		return result;
	}
	
public:
	vector<int> id;
	vector<int> nodeToScc;
	vector<vector<int>> Scc;

	TwoSAT(int n) {
		N = n;
		id.assign(2 * N, 0);
		graph.resize(2 * N);
		finished.assign(2 * N, false);
		nodeToScc.assign(2 * N, -1);
		idx = 0;
		sccNum = 0;
		addForcedEdge(1);
	}

	// n is not node or literal. it is actual variable.
	int pos(int n) { return 2 * (n - 1); }
	int neg(int n) { return 2 * (n - 1) + 1; }

	void addClause(int a, int b) {
		int nodeA, nodeB, notA, notB;

		if (a > 0)
		{
			nodeA = pos(a);
			notA = neg(a);
		}
		else
		{
			nodeA = neg(-a);
			notA = pos(-a);
		}

		if (b > 0)
		{
			nodeB = pos(b);
			notB = neg(b);
		}
		else
		{
			nodeB = neg(-b);
			notB = pos(-b);
		}

		graph[notA].push_back(nodeB);
		graph[notB].push_back(nodeA);
	}

	void findScc() {
		for (int i = 0; i < 2 * N; ++i)
		{
			if (id[i] == 0) DFS(i);
		}
	}
	
	void addForcedEdge(int n) {
		graph[neg(n)].push_back(pos(n));
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	while (cin >> n >> m)
	{
		

		TwoSAT ts(n);

		for (int i = 0; i < m; ++i)
		{
			int a, b; cin >> a >> b;
			ts.addClause(a, b);
		}

		// scc is ordered in reverse topological order.
		ts.findScc();

		bool flag = true;
		for (int i = 0; i < 2 * n; i+=2)
		{
			if (ts.nodeToScc[i] == ts.nodeToScc[i + 1])
			{
				flag = false;
				break;
			}
		}

		string ans = flag ? "yes" : "no";

		cout << ans << '\n';

		//vector<int> solution(n + 1, -1);
		//for (int i = 0; i < ts.Scc.size(); ++i)
		//{
		//	for (int node : ts.Scc[i])
		//	{
		//		int vari = node / 2;
		//		if (solution[vari] != -1)
		//		{
		//			// node is positive literal
		//			if (node % 2 == 0) solution[vari] = 1;
		//			else solution[vari] = 0;
		//		}
		//	}
		//}

	}


	return 0;
}