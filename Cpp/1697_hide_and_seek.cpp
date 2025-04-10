#include <iostream>   
#include <queue>


using namespace std;

const int XMAX = 100'000;
int visited[XMAX + 1];
queue<int> q;
int N, K;

void bfs(int start) {
	q.push(start);
	visited[start] = 0;

	while (!q.empty())
	{
		int fr = q.front();
		if (fr == K) break;
		q.pop();

		if (fr - 1 >= 0 && visited[fr-1] ==0)
		{
			q.push(fr - 1);
			visited[fr - 1] = visited[fr] + 1;
		}
		if (fr + 1 <= XMAX && visited[fr + 1] == 0)
		{
			q.push(fr + 1);
			visited[fr + 1] = visited[fr] + 1;
		}
		if (2 * fr <= XMAX && visited[2*fr] == 0)
		{
			q.push(2 * fr);
			visited[2 * fr] = visited[fr] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	bfs(N);
	cout << visited[K] << '\n';

	return 0;
}