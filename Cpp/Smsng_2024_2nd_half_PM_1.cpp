#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct medu {
	int y;
	int x;
	int d;
};

struct war {
	int y;
	int x;
	bool stone;
	bool alive;
};

typedef pair<int, int> pii;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int dy2[4] = { 0,0,-1,1 };
int dx2[4] = { -1,1,0,0 };

int findPathByBFS(vector<vector<int>>& board, vector<pii>& path, int sr, int sc, int er, int ec) {
	int n = board.size();
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	vector<vector<pii>> prev(n, vector<pii>(n));

	queue<pii> q;

	q.push({ sr, sc });
	visited[sr][sc] = true;

	bool found = false;

	while (!q.empty())
	{
		pii f = q.front();
		int cy = f.first;
		int cx = f.second;
		q.pop();

		if (cy == er && cx == ec)
		{
			found = true;
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && board[ny][nx] == 0)
			{
				q.push({ ny,nx });
				visited[ny][nx] = true;
				prev[ny][nx] = { cy,cx };
			}
		}
	}

	if (found)
	{
		int cy = er;
		int cx = ec;

		while (true)
		{
			path.push_back({ cy,cx });
			if (cy == sr && cx == sc) break;
			pii next = prev[cy][cx];
			cy = next.first;
			cx = next.second;
		}
		reverse(path.begin(), path.end());
		return 1;
	}
	else
	{
		return -1;
	}

}

pii findBestDirection(vector<vector<int>>& board, vector<war>& wars, int my, int mx) {
	int d = 0;
	int n = board.size();
	vector<vector<vector<int>>> stone(4, vector<vector<int>>(n, vector<int>(n, 0)));
	vector<vector<int>> warPos(n, vector<int>(n, 0));
	stone[0][my][mx] = 4;
	

	vector<int> points(4, 0);
	int ans = 0;

	for (war& w : wars)
	{
		if (!w.alive) continue;
		warPos[w.y][w.x] += 1;
	}
	/*cout << "Warrior Position" << '\n';
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << warPos[i][j] << ' ';
		}
		cout << "\n";
	}
	cout << "============\n";*/
	// north
	for (int l = 1; l < n; ++l)
	{
		for (int w = -l; w <= l; ++w)
		{
			int sy = my - l;
			int sx = mx + w;
			if (sy >= 0 && sy < n && sx >= 0 && sx < n) stone[0][sy][sx] = 1;
		}
	}

	/*cout << "North stone area" << '\n';
	stone[0][my][mx] = 4;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << stone[0][i][j] << ' ';
		}
		cout << "\n";
	}*/

	for (int l = 1; l < n; ++l)
	{
		for (int w = -l; w <= l; ++w)
		{
			int sy = my - l;
			int sx = mx + w;
			if (sy >= 0 && sy < n && sx >= 0 && sx < n && stone[0][sy][sx] == 1 && warPos[sy][sx] > 0)
			{
				points[0] += warPos[sy][sx];
				for (int xl = 1; xl <n; ++xl)
				{
					
						for (int xw = -xl; xw <= xl; ++xw)
						{
							// w>0 : medusa ray is going through right position
							if (w > 0 && xw < 0) continue;
							if (w < 0 && xw > 0) continue;
							if (w == 0 && abs(xw) != 0) continue;
							int y = sy - xl;
							int x = sx + xw;
							if (y >= 0 && y < n && x>=0 && x < n)
							{
								stone[0][y][x] = 0;
								
							}
						}
					
				
				}
			}
		}
	}

	/*cout << "North stone area after ray calculated" << '\n';
	stone[0][my][mx] = 4;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << stone[0][i][j] << ' ';
		}
		cout << "\n";
	}*/
	
	


	// south

	for (int l = 1; l < n; ++l)
	{
		for (int w = -l; w <= l; ++w)
		{
			int sy = my + l;
			int sx = mx + w;
			if (sy >= 0 && sy < n && sx >= 0 && sx < n) stone[1][sy][sx] = 1;
		}
	}

	for (int l = 1; l < n; ++l)
	{
		for (int w = -l; w <= l; ++w)
		{
			// down dir
			int sy = my + l;
			int sx = mx + w;
			if (sy >= 0 && sy < n && sx >= 0 && sx < n && stone[1][sy][sx]==1 && warPos[sy][sx] > 0)
			{
				points[1] += warPos[sy][sx];
				for (int xl = 1; xl < n; ++xl)
				{

					for (int xw = -xl; xw <= xl; ++xw)
					{
						if (w > 0 && xw < 0) continue;
						if (w < 0 && xw > 0) continue;
						if (w == 0 && abs(xw) != 0) continue;
						int y = sy + xl;
						int x = sx + xw;
						if (y >= 0 && y < n && x >= 0 && x < n)
						{
							stone[1][y][x] = 0;
						}
					}
				}
			}
		}
	}
	/*cout << "South stone area" << '\n';
	stone[1][my][mx] = 4;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << stone[1][i][j] << ' ';
		}
		cout << "\n";
	}*/

	// west


	for (int l = 1; l < n; ++l)
	{
		for (int w = -l; w <= l; ++w)
		{
			int sy = my + w;
			int sx = mx - l;
			if (sy >= 0 && sy < n && sx >= 0 && sx < n) stone[2][sy][sx] = 1;
		}
	}

	for (int l = 1; l < n; ++l)
	{
		for (int w = -l; w <= l; ++w)
		{
			// left dir
			int sy = my + w;
			int sx = mx - l;
			if (sy >= 0 && sy < n && sx >= 0 && sx < n && stone[2][sy][sx]==1 && warPos[sy][sx] > 0)
			{
				points[2] += warPos[sy][sx];
				for (int xl = 1; xl < n; ++xl)
				{

					for (int xw = -xl; xw <= xl; ++xw)
					{
						if (w > 0 && xw < 0) continue;
						if (w < 0 && xw > 0) continue;
						if (w == 0 && abs(xw) != 0) continue;
						int y = sy + xw;
						int x = sx - xl;
						if (y >= 0 && y < n && x >= 0 && x < n)
						{
							stone[2][y][x] = 0;
						}
					}
				}
			}
		}
	}
	/*cout << "West stone area" << '\n';
	stone[2][my][mx] = 4;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << stone[2][i][j] << ' ';
		}
		cout << "\n";
	}*/

	// east


	for (int l = 1; l < n; ++l)
	{
		for (int w = -l; w <= l; ++w)
		{
			int sy = my + w;
			int sx = mx + l;
			if (sy >= 0 && sy < n && sx >= 0 && sx < n) stone[3][sy][sx] = 1;
		}
	}
	for (int l = 1; l < n; ++l)
	{
		for (int w = -l; w <= l; ++w)
		{
			// right dir
			int sy = my + w;
			int sx = mx + l;
			if (sy >= 0 && sy < n && sx >= 0 && sx < n && stone[3][sy][sx]==1 && warPos[sy][sx] > 0)
			{
				points[3] += warPos[sy][sx];
				for (int xl = 1; xl < n; ++xl)
				{
					// sy, sx : current warrior position
					for (int xw = -xl; xw <= xl; ++xw)
					{
						if (w > 0 && xw < 0) continue;
						if (w < 0 && xw > 0) continue;
						if (w == 0 && abs(xw) != 0) continue;
						int y = sy + xw;
						int x = sx + xl;
						if (y >= 0 && y < n && x >= 0 && x < n)
						{
							stone[3][y][x] = 0;
						}
					}
				}
			}
		}
	}


	/*cout << "East stone area" << '\n';*/
	stone[3][my][mx] = 4;
	/*for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << stone[3][i][j] << ' ';
		}
		cout << "\n";
	}*/

	for (int i = 0; i < 4; ++i)
	{
		if (points[i] > ans)
		{
			ans = points[i];
			d = i;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			board[i][j] = stone[d][i][j];
		}
	}
	return { ans, d };
}

int main() {
	int n, m; cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(n));
	vector<war> wars;
	vector<pii> path;

	int sr, sc, er, ec; cin >> sr >> sc >> er >> ec;

	for (int i = 0; i < m; ++i)
	{
		int y, x; cin >> y >> x;
		war w;
		w.y = y;
		w.x = x;
		w.alive = true;
		w.stone = false;
		wars.push_back(w);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int a; cin >> a;
			board[i][j] = a;
		}

	}



	int pathExist = findPathByBFS(board, path, sr, sc, er, ec);
	if (pathExist == -1)
	{
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 0; i < path.size(); ++i)
	{
		board[path[i].first][path[i].second] = i + 2;
	}

	/*cout << "board======\n";
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board.size(); ++j)
		{
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}*/


	int my = path[0].first;
	int mx = path[0].second;
	int md = -1;

	int sight[3] = { -1,0,1 };
	for (int turn = 1; turn < path.size(); ++turn)
	{
		// med move -> UDLR
		my = path[turn].first;
		mx = path[turn].second;

		int attackPt = 0;
		for (war& w : wars)
		{
			if (w.y == my && w.x == mx)
			{
				w.alive = false;
				
			}
		}

		if (my == er && mx == ec)
		{
			cout << 0 << '\n';
			return 0;
		}
		// med view
		vector<vector<int>> stone(n, vector<int>(n));
		pii ans;
		ans = findBestDirection(stone, wars, my, mx);

		int stonePt = ans.first;
		int sumMove = 0;

		int dir = ans.second;


		vector<vector<int>> warPos(n, vector<int>(n, 0));
		

		for (war& w : wars)
		{
			if (!w.alive) continue;
			warPos[w.y][w.x] += 1;
			//stone[w.y][w.x] += 2;
		}
		//stone[my][mx] = 9;
		/*cout << "Warrior Position" << '\n';
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << warPos[i][j] << ' ';
			}
			cout << "\n";
		}
		cout << "============\n";
		

		
		cout << " stone area" << '\n';
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << stone[i][j] << ' ';
		}
		cout << "\n";
	}
	cout << "===========\n";*/

		// warrior stoned
		for (war& w : wars)
		{
			if (!w.alive) continue;
			if (stone[w.y][w.x] == 1)
			{
				w.stone = true;
			}
		}
		// warrior move 1 -> UDLR
		for (war& w : wars)
		{
			if (!w.alive) continue;
			if (!w.stone)
			{
				for (int i = 0; i < 4; ++i)
				{
					int ny = w.y + dy[i];
					int nx = w.x + dx[i];
					if (ny >= 0 && ny < n && nx >= 0 && nx < n && stone[ny][nx] != 1)
					{
						if (abs(my - ny) + abs(mx - nx) < abs(my - w.y) + abs(mx - w.x))
						{
							w.y = ny;
							w.x = nx;
							sumMove++;
							break;
						}
					}
				}
			}
		}
		// warrior attack
		for (war& w : wars)
		{
			if (!w.alive || w.stone) continue;
			if (w.y == my && w.x == mx)
			{
				attackPt++;
				w.alive = false;
			}
		}
		// warrior move 2 -> LRUD
		for (war& w : wars)
		{
			if (!w.alive) continue;
			if (!w.stone)
			{
				for (int i = 0; i < 4; ++i)
				{
					int ny = w.y + dy2[i];
					int nx = w.x + dx2[i];
					if (ny >= 0 && ny < n && nx >= 0 && nx < n && stone[ny][nx] != 1)
					{
						if (abs(my - ny) + abs(mx - nx) < abs(my - w.y) + abs(mx - w.x))
						{
							w.y = ny;
							w.x = nx;
							sumMove++;
							break;
						}
					}
				}
			}
		}
		// warrior attack
		for (war& w : wars)
		{
			if (!w.alive || w.stone) continue;
			if (w.y == my && w.x == mx)
			{
				attackPt++;
				w.alive = false;
			}
		}
		// for each turn, 
		// sum of warrior's move dist 
		// warrior stoned
		// warrior die

		// warrior recovery from stone
		for (war& w : wars)
		{
			if (!w.alive) continue;
			w.stone = false;
		}

		cout << sumMove << ' ' << stonePt << ' ' << attackPt << '\n';
	}
	return 0;
}