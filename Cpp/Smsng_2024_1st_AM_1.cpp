#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;



int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int boardPoint(vector<vector<int>>& board) {
	int ans = 0;
	vector<vector<bool>> visited(5, vector<bool>(5, 0));
	queue<pii> connect;
	vector<pii> eraseQ;
	for (int y = 0; y < 5; ++y)
	{
		for (int x = 0; x < 5; ++x)
		{
			queue<pii> q;

			if (visited[y][x] == 1) continue;
			visited[y][x] = 1;
			q.push({ y,x });
			connect.push({ y,x });

			while (!q.empty())
			{
				pii f = q.front();
				int cy = f.first;
				int cx = f.second;
				q.pop();

				for (int i = 0; i < 4; ++i)
				{
					int ny = cy + dy[i];
					int nx = cx + dx[i];
					if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5 &&
						visited[ny][nx] == 0 &&
						board[cy][cx] == board[ny][nx])
					{
						q.push({ ny,nx });
						connect.push({ ny,nx });
						visited[ny][nx] = 1;
					}
				}
			}

			int len = connect.size();
			while (!connect.empty())
			{
				pii p = connect.front();
				connect.pop();
				if (len >= 3)
				{
					eraseQ.push_back(p);
				}
			}
		}
	}

	ans += eraseQ.size();
	for (pii p : eraseQ)
	{
		board[p.first][p.second] = 0;
	}

	return ans;
}

void copyRotateBoard(vector<vector<int>>& board, vector<vector<int>>& temp, int cy, int cx, int angle) {
	copy(board.begin(), board.end(), temp.begin());
	int tly = cy - 1;
	int tlx = cx - 1;
	if (angle == 0)
	{
		for (int y = 0; y <= 2; ++y)
		{
			for (int x = 0; x <= 2; ++x)
			{
				temp[x + tly][2 - y + tlx] = board[y + tly][x + tlx];
			}
		}
	}
	else if (angle == 1)
	{
		for (int y = 0; y <= 2; ++y)
		{
			for (int x = 0; x <= 2; ++x)
			{
				temp[2 - y + tly][2 - x + tlx] = board[tly + y][tlx + x];
			}
		}
	}
	else if (angle == 2)
	{
		for (int y = 0; y <= 2; ++y)
		{
			for (int x = 0; x <= 2; ++x)
			{
				temp[2 - x + tly][y + tlx] = board[tly + y][tlx + x];
			}
		}
	}

	/*cout << "===============\n";
	cout << "original" << '\n';
	for (int y = 0; y < 5; ++y)
	{
		for (int x = 0; x < 5; ++x)
		{
			cout << board[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	cout << "after rotate\n";
	for (int y = 0; y < 5; ++y)
	{
		for (int x = 0; x < 5; ++x)
		{
			cout << temp[y][x] << ' ';
		}
		cout << '\n';
	}*/

}

int main() {
	int k, m; cin >> k >> m;

	vector<vector<int>> board(5, vector<int>(5));
	vector<vector<int>> temp(5, vector<int>(5));

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> board[i][j];
		}
	}

	queue<int> pieceQ;

	for (int i = 0; i < m; ++i)
	{
		int x; cin >> x;
		pieceQ.push(x);
	}

	for (int i = 0; i < k; ++i)
	{
		int ans = 0;
		/* cout << boardPoint() << '\n';
		 for (int y = 0; y < 5; ++y)
		 {
			 for (int x = 0; x < 5; ++x)
			 {
				 cout << board[y][x] << ' ';
			 }
			 cout << '\n';
		 }*/
		 // calculate current board point and refill until current board point become 0

		int maxPointFromRotate = 0;
		int cy, cx, a;
		// 각도가 작은거부터
		for (int angle = 0; angle < 3; ++angle)
		{
			for (int x = 1; x <= 3; ++x)
			{
				for (int y = 1; y <= 3; ++y)
				{

					copyRotateBoard(board, temp, y, x, angle);
					int rotatePoint = boardPoint(temp);
					if (rotatePoint > maxPointFromRotate)
					{
						// 최대 점수 각도, 행, 열 발견
						cy = y;
						cx = x;
						a = angle;
						maxPointFromRotate = rotatePoint;
					}
				}
			}
		}
		if (maxPointFromRotate == 0)
		{
			break;
		}
		// 최대 점수 회전을 원본 보드에 복사하기 위한 임시 보드
		vector<vector<int>> newBoard(5, vector<int>(5));
		// 임시 보드를 회전
		copyRotateBoard(board, newBoard, cy, cx, a);
		// 회전한 보드로 원본 보드를 교체
		copy(newBoard.begin(), newBoard.end(), board.begin());

		while (true)
		{
			int bp = boardPoint(board);
			ans += bp;
			if (bp == 0) break;
			for (int x = 0; x < 5; ++x)
			{
				for (int y = 4; y >= 0; --y)
				{
					if (board[y][x] == 0)
					{
						int n = pieceQ.front();
						pieceQ.pop();
						board[y][x] = n;
					}
				}
			}
		}

		/*for (int y = 0; y < 5; ++y)
		{
			for (int x = 0; x < 5; ++x)
			{
				cout << board[y][x] << ' ';
			}
			cout << '\n';
		}*/
		cout << ans << ' ';
	}
	return 0;
}