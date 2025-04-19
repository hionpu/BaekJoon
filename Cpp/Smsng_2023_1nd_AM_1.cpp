#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int dCannonY[8] = { 0,-1,-1,-1,0,1,1,1 };
int dCannonX[8] = { 1,1,0,-1,-1,-1,0,1 };
struct tower {
	int att;
	int lastAttack;
	int y;
	int x;
	bool attacked;
};

// 비교 함수를 별도로 정의
struct TowerCompare {
	bool operator()(const tower& a, const tower& b) const {
		if (a.att != b.att) return a.att < b.att; // Ascending by 'att'
		if (a.lastAttack != b.lastAttack) return a.lastAttack > b.lastAttack; // Descending by 'lastAttack'
		if ((a.y + a.x) != (b.y + b.x)) return (a.y + a.x) > (b.y + b.x); // Descending by sum of 'y + x'
		return a.x > b.x; // Descending by 'x'
	}
};

bool pathExist(vector<pii>& path, vector<vector<int>>& board, int ay, int ax, int defy, int defx) {
	bool exist = false;

	queue<pii> q;
	int n = board.size();
	int m = board[0].size();
	vector<vector<pii>> prev(n, vector<pii>(m));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	q.push({ ay, ax });
	visited[ay][ax] = true;

	while (!q.empty())
	{
		pii fr = q.front();
		int cy = fr.first;
		int cx = fr.second;
		q.pop();

		if (cy == defy && cx == defx)
		{
			exist = true;
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0) ny = n - 1;
			if (ny > n - 1) ny = 0;
			if (nx < 0) nx = m - 1;
			if (nx > m - 1) nx = 0;

			if (!visited[ny][nx] && board[ny][nx] != 0)
			{
				visited[ny][nx] = true;
				q.push({ ny,nx });
				prev[ny][nx] = { cy, cx };
			}
		}
	}

	if (exist)
	{
		int cy = defy;
		int cx = defx;

		while (true)
		{
			path.push_back({ cy,cx });

			if (cy == ay && cx == ax) break;

			pii next = prev[cy][cx];
			cy = next.first;
			cx = next.second;
		}

		reverse(path.begin(), path.end());
	}

	return exist;
}

int main() {
	int n, m, k; cin >> n >> m >> k;

	vector<vector<int>> board(n, vector<int>(m));
	vector<tower> towers;

	// 타워 초기화
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int att; cin >> att;
			board[i][j] = att;

			if (att > 0)
			{ // 공격력이 0보다 큰 경우에만 타워 객체 생성
				tower t;
				t.att = att;
				t.lastAttack = 0;
				t.y = i;
				t.x = j;
				t.attacked = false;

				towers.push_back(t);
			}
		}
	}

	for (int turn = 1; turn <= k; ++turn)
	{
		// 공격자 선정
		sort(towers.begin(), towers.end(), TowerCompare());

		// 공격력이 0인 타워 제거
		while (!towers.empty() && towers.front().att == 0)
		{
			towers.erase(towers.begin());
		}

		if (towers.size() <= 1)
		{
			// 남은 타워가 1개 이하면 게임 종료
			break;
		}

		// 디버깅용 출력
	   /* for (const auto& t : towers)
		{
			cout << t.att << ' ' << t.y << ' ' << t.x << ' ' << t.lastAttack << ' ' << t.attacked << '\n';
		}*/

		// 공격자와 수비자 참조
		tower& attacker = towers.front();
		tower& defender = towers.back();

		// 공증
		attacker.att += n + m;
		board[attacker.y][attacker.x] = attacker.att;
		// 마지막 공격 턴 값
		attacker.lastAttack = turn;

		// 공격
		vector<pii> sideVictim;
		string weapon;
		int dmg = attacker.att;

		

		if (pathExist(sideVictim, board, attacker.y, attacker.x, defender.y, defender.x))
		{
			weapon = "LASER";
			// 자기 자신은 공격 X
			for (int i = 1; i < sideVictim.size() - 1; ++i)
			{
				pii pos = sideVictim[i];
				int y = pos.first;
				int x = pos.second;

				// 해당 위치에 있는 타워 찾기
				for (auto& t : towers)
				{
					if (t.y == y && t.x == x)
					{
						t.attacked = true;
						t.att = max(0, t.att - dmg / 2);
						// 보드 업데이트
						board[y][x] = t.att;
						break;
					}
				}
			}

			/*for (int i = 0; i < sideVictim.size(); ++i)
			{
				cout << sideVictim[i].first << ", " << sideVictim[i].second << '\n';
			}*/
		}
		// 포탄 시도
		else
		{
			weapon = "CANNON";
			for (int i = 0; i < 8; ++i)
			{
				int ny = defender.y + dCannonY[i];
				int nx = defender.x + dCannonX[i];

				if (ny < 0) ny = n - 1;
				if (ny > n - 1) ny = 0;
				if (nx < 0) nx = m - 1;
				if (nx > m - 1) nx = 0;

				if (ny == attacker.y && nx == attacker.x) continue;
				// 해당 위치에 있는 타워 찾기
				for (auto& t : towers)
				{
					if (t.y == ny && t.x == nx && t.att > 0)
					{
						t.att = max(0, t.att - dmg / 2);
						t.attacked = true;
						// 보드 업데이트
						board[ny][nx] = t.att;
						break;
					}
				}
			}
		}

		// 메인 공격 대상은 레이저든 포탄이든 풀뎀
		defender.att = max(0, defender.att - dmg);
		defender.attacked = true;
		board[defender.y][defender.x] = defender.att;

		// 공격 결과에 따른 보드 상태 출력
		/*cout << "turn " << turn << " " << weapon
			<< " tower at ("
			<< attacker.y << ", " << attacker.x << ")"
			<< " attacks  ("
			<< defender.y << ", " << defender.x << ")" << '\n';
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';*/

		// 정비
		// 공격 당하지 않고, 살아있는 포탑은 +1
		for (auto& t : towers)
		{
			if (t.att == 0 || t.lastAttack == turn) continue;

			if (t.attacked)
			{
				t.attacked = false;
			}
			else
			{
				t.att++;
				board[t.y][t.x] = t.att;
			}
		}

		/*cout << "turn " << turn << " after maintanence" << '\n';
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';*/
	}

	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			ans = max(board[i][j], ans);
		}
	}
	cout << ans << '\n';

	return 0;
}
