#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> pii;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int r, c, k;

int sy[3] = { 1,2,1 };
int sx[3] = { -1,0,1 };

int ey[5] = { -1,0,1,1,2 };
int ex[5] = { 1,2,1,2,1 };

int wy[5] = { -1,0,1,1,2 };
int wx[5] = { -1,-2,-1,-2,-1 };
bool canMoveDown(vector<vector<int>>& board, vector<vector<int>>& exit, int y, int x) {
	bool canMove = true;
	for (int k = 0; k < 3; ++k)
	{
		int ny = y + sy[k];
		int nx = x + sx[k];
		if (ny > board.size() - 1 || board[ny][nx] > 0)
		{
			canMove = false;
			break;
		}
	}
	return canMove;

}

pii golem_move(vector<vector<int>>& board, vector<vector<int>>& exit, vector<pii>& v, int i) {

	int x = v[i].first;
	// 임시로 밖에 있는거로 처리 y < 2면 밖임
	int y = 0;
	int d = v[i].second;

	int boardHeight = board.size();
	int boardWidth = board[0].size();

	bool canMove = true;


	int t = 0;
	while (canMove)
	{
		// move -> y, x 
			// 1. 그냥 내려감
		if (canMoveDown(board, exit, y, x))
		{
			y++;
			continue;
		}

		// 2. 서쪽으로 우회 / 출구 += -1
		bool canMoveWest = true;

		for (int k = 0; k < 5; ++k)
		{
			int ny = y + wy[k];
			int nx = x + wx[k];
			if (ny < 0 || ny > boardHeight - 1 || nx < 0 || nx > boardWidth - 1 || board[ny][nx] > 0)
			{
				canMoveWest = false;
				break;
			}
		}
		if (canMoveWest)
		{
			x--; y++;
			d = (d - 1 + 4) % 4;
			continue;
		}
		// 3. 동쪽으로 우회 / 출구 += 1
		bool canMoveEast = true;
		for (int k = 0; k < 5; ++k)
		{
			int ny = y + ey[k];
			int nx = x + ex[k];
			if (ny < 0 || ny > boardHeight-1 || nx < 0 || nx > boardWidth - 1 || board[ny][nx] > 0)
			{
				canMoveEast = false;
				break;
			}
		}
		if (canMoveEast)
		{
			x++; y++;
			d = (d + 1) % 4;
			continue;
		}

		// 이동 못하는 상태인데 삐져나온 경우
		if (y <= 1)
		{
			for (int a = 0; a < boardHeight; ++a)
			{
				for (int b = 0; b < boardWidth; ++b)
				{
					board[a][b] = 0;
					exit[a][b] = 0;
					y = -1;
					x = -1;
				}
			}
			break;
		}
		// 이동할 공간 없음 -> 종료
			// board에 골렘 크기만큼 값 i 할당
			// exit에 골렘 출구 값 i로 할당
		canMove = false;
		for (int k = 0; k < 4; ++k)
		{
			board[y + dy[k]][x + dx[k]] = i + 1;
		}
		board[y][x] = i + 1;
		exit[y + dy[d]][x + dx[d]] = i + 1;
	}
	cout << "Golem #" << i+1 << '\n';
	for (int a = 0; a < boardHeight; ++a)
	{
		for (int b = 0; b < boardWidth; ++b)
		{
			cout << board[a][b] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	++t;
	return { y,x };
}

void spirit_move(vector<vector<int>>& board, vector<vector<int>>& exit, vector<vector<int>>& visited, set<int>& points, pii& start, int spirit_idx) {
	int cy = start.first;
	int cx = start.second;

	int boardHeight = board.size();
	int boardWidth = board[0].size();
	if (cy == boardHeight - 1)
	{
		points.insert(cy);
		return;
	}
			visited[cy][cx] = 1;
	bool canMove = false;
	for (int i = 0; i < 4; ++i)
	{
		int ny = cy + dy[i];
		int nx = cx + dx[i];
			// 경계조건													 // 골렘있는위치만			// 방문 안한곳
		if (ny >= 0 && ny < boardHeight && nx >= 0 && nx < boardWidth && board[ny][nx] > 0 && !visited[ny][nx])
		{       // 다른 골렘으로 갈아타려 하는데    현재 자리가 출구가 아닌 경우
			if (board[cy][cx] != board[ny][nx] && exit[cy][cx] != board[cy][cx]) continue;

			pii next = { ny,nx };
			spirit_move(board, exit, visited, points, next, spirit_idx);

			canMove = true;
		}
	}
	if (!canMove) points.insert(cy);
			visited[cy][cx] = 0;
}

int main() {
	// Please write your code here.
	cin >> r >> c >> k;

	vector<vector<int>> board(r + 2, vector<int>(c));
	vector<vector<int>> exit(r + 2, vector<int>(c));
	vector<pii> v;

	int ans = 0;

	for (int i = 0; i < k; ++i)
	{
		int x, d; cin >> x >> d;
		pii g = { x - 1, d };
		v.push_back(g);
	}


	for (int i = 0; i < k; ++i)
	{
		// golem move
		pii spirit = golem_move(board, exit, v, i);
		if (spirit.first == -1 && spirit.second == -1) continue;
		// spirit move
		vector<vector<int>> visited(r+2, vector<int>(c));
		set<int> points;
		spirit_move(board, exit, visited, points, spirit, i);
		set<int>::iterator it = --points.end();
		cout << i + 1 << "-th Exit======" << i << '\n';
		for (int a = 0; a < r+2; ++a)
		{
			for (int b = 0; b < c; ++b)
			{
				cout << exit[a][b] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';

		ans += *it - 1;
	}

	cout << ans << '\n';

	return 0;
}