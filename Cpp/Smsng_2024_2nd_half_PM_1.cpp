#include <iostream>
using namespace std;

struct medu {
    int y;
    int x;
    int d;
}

struct war {
    int y;
    int x;
    bool alive;
}

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
    int n, m; cin >> n, m;

    vector<n, vector<int>(n)> town;

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