#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

struct knight {
	int y;
	int x;
	int h;
	int w;
	int maxHP;
	int curHP;
	bool alive;

};

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

// 움직임 가능성 검증은 끝난상태
void moveKnight(knight& t, int dir) {
	int ny = t.y + dy[dir];
	int nx = t.x + dx[dir];
	t.y = ny;
	t.x = nx;
}

bool canGo(vector<vector<int>>& board, vector<vector<int>>& knightboard, map<int, knight>& knights, vector<int>& affected, int idx, int dir) {

	// 죽었는지 판단은 함수 호출하기 전에 하는것으로

	knight& s = knights[idx];
	affected.push_back(idx);

	int boardSize = board.size();
	 

	vector<pii> searchPoint;
	// 상
	if (dir == 0)
	{
		for (int w = 0; w < s.w; ++w)
		{
			int ny = s.y - 1;
			int nx = s.x + w;
			searchPoint.push_back({ ny,nx });
		}
	}

	// 우
	else if (dir == 1)
	{
		for (int h = 0; h < s.h; ++h)
		{
			int ny = s.y + h;
			int nx = s.x + s.w;
			searchPoint.push_back({ ny,nx });
		}
	}
	
	// 하
	else if (dir == 2)
	{
		for (int w = 0; w < s.w; ++w)
		{
			int ny = s.y + s.h;
			int nx = s.x + w;
			searchPoint.push_back({ ny,nx });
		}
	}
	// 좌
	else if (dir == 3)
	{
		for (int h = 0; h < s.h; ++h)
		{
			int ny = s.y + h;
			int nx = s.x - 1;
			searchPoint.push_back({ ny,nx });
		}
	}

	for (int i = 0; i < searchPoint.size(); ++i)
	{
		int ny = searchPoint[i].first;
		int nx = searchPoint[i].second;

		// 하나라도 벽 있으면 안됨
		if (ny<1 || ny>boardSize - 1 || nx<1 || nx > boardSize - 1 || board[ny][nx] == 2)
		{
			return false;
		}
	}
	
	bool nextKightCanMove = true;
	for (int i = 0; i < searchPoint.size(); ++i)
	{
		int ny = searchPoint[i].first;
		int nx = searchPoint[i].second;
		int nextIdx = knightboard[ny][nx];
		if (nextIdx > 0 && find(affected.begin(), affected.end(), nextIdx) == affected.end())
		{
			int nextIdx = knightboard[ny][nx];
			nextKightCanMove = nextKightCanMove && canGo(board, knightboard, knights, affected, nextIdx, dir); 
			if (!nextKightCanMove) return false;
		}
		
	}
	return nextKightCanMove;
}

void damage(vector<vector<int>>& board, map<int, knight>& knights, vector<int>& affected) {
	// 명령 받은 기사는 데미지 없음 => i =1부터 시작
	for (int i = 1; i < affected.size(); ++i)
	{
		knight& k = knights[affected[i]];
		int y = k.y;
		int x = k.x;
		int h = k.h;
		int w = k.w;

		bool trapInsideMe = false;
		/*for (int hh = 0; hh < h; ++hh)
		{
			for (int ww = 0; ww < w; ++ww)
			{
				if (board[y+ww][x+hh] == 1)
				{
					trapInsideMe = true;
					break;
				}
			}
		}*/
		//if (board[y][x] != 1) trapInsideMe = false;
		//if (!trapInsideMe) continue;

		for (int hh = 0; hh < h; ++hh)
		{
			if (!k.alive) break;
			for (int ww = 0; ww < w; ++ww)
			{
				if (board[y + hh][x + ww] == 1) k.curHP--;
				if (k.curHP <= 0)
				{
					k.alive = false;
					break;
				}
			}
		}
	}
}

void remapKnightboard(vector<vector<int>>& knightboard, map<int, knight>& knights) {
	for (int i = 0; i < knightboard.size(); ++i)
	{
		for (int j = 0; j < knightboard.size(); ++j)
		{
			knightboard[i][j] = 0;
		}
	}

	for (const auto& p : knights)
	{
		const knight& k = p.second;
		if (!k.alive) continue;

		int y = k.y;
		int x = k.x;
		int h = k.h;
		int w = k.w;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				knightboard[y + i][x + j] = p.first;
			}
		}
	}
}

int main() {
	int l, n, q;
	cin >> l >> n >> q;
	vector<vector<int>> board(l + 1, vector<int>(l + 1));
	vector<vector<int>> knightboard(l + 1, vector<int>(l + 1));
	map<int, knight> knights;

	/*for (int y = 1; y <= l; ++y)
	{
		for (int x = 1; x <= l; ++x)
		{

		}
	}*/

	for (int i = 1; i <= l; ++i)
	{
		for (int j = 1; j <= l; ++j)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		knight t;

		cin >> t.y >> t.x >> t.h >> t.w >> t.maxHP;
		t.curHP = t.maxHP;
		t.alive = true;

		knights[i] = t;

	}

	remapKnightboard(knightboard, knights);

	//cout << "Initial Board" << "\n";
	//for (int i = 1; i <= l; ++i)
	//{
	//	for (int j = 1; j <= l; ++j)
	//	{
	//		cout << board[i][j] << ' ';
	//	}
	//	cout << '\n';

	//}
	//cout << '\n';

	//cout << "Initial KnightBoard" << "\n";
	//for (int i = 1; i <= l; ++i)
	//{
	//	for (int j = 1; j <= l; ++j)
	//	{
	//		cout << knightboard[i][j] << ' ';
	//	}
	//	cout << '\n';

	//}
	//cout << '\n';

	for (int turn = 0;turn<q;++turn)
	{
		int idx, dir; cin >> idx >> dir;
		string direction[4] ={ "North", "East", "South", "West" };
		bool moved = false;
		

		// 죽은애한테 명령
		if (!knights[idx].alive) continue;

		vector<int> affected;
		if (canGo(board, knightboard, knights, affected, idx, dir))
		{
			for (int j = 0; j < affected.size(); ++j)
			{
				knight& k = knights[affected[j]];
				moveKnight(k, dir);
			}
			damage(board, knights, affected);
			remapKnightboard(knightboard, knights);
			moved = true;
		}
		
	/*	if (moved)
		{
		cout << "Knight " << idx << " moved to " << direction[dir] << '\n';
		cout << "Affected knights were: ";
		for (int i = 0; i < affected.size(); ++i)
		{
			cout << affected[i] << ' ';
		}
		cout << '\n';
		}
		else
		{
			cout << "Knight " << idx << "=failed to move= " << direction[dir] << '\n';
		}

		cout << "Board after turn " << turn+1 << "\n";
		for (int i = 1; i <= l; ++i)
		{
			for (int j = 1; j <= l; ++j)
			{
				cout << board[i][j] << ' ';
			}
			cout << '\n';

		}
		cout << '\n';

		cout << "KnightBoard" << "\n";
		for (int i = 1; i <= l; ++i)
		{
			for (int j = 1; j <= l; ++j)
			{
				cout << knightboard[i][j] << ' ';
			}
			cout << '\n';

		}
		cout << '\n';*/
	}

	int ans = 0;
	for (const pair<int, knight>& pair : knights)
	{
		const knight& k = pair.second;
		if (k.alive)
		{
			ans += k.maxHP - k.curHP;
		}
	}
	cout << ans << '\n';
	return 0;
}