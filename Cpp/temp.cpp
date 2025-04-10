#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, m, k, c;
int board[20][20];
int bomb[20][20];


int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int bombY[4] = { -1, -1, 1, 1 };
int bombX[4] = { 1, -1, -1, 1 };

void reduceBomb() {
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			if (bomb[y][x] > 0)
			{
				bomb[y][x]--;
			}
		}
	}
}

void growth() {
	// Calculate growth first with a temp array
	vector<vector<int>> growth(n, vector<int>(n, 0));

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; ++x)
		{
			if (board[y][x] > 0)
			{
				for (int k = 0; k < 4; ++k)
				{
					int ny = y + dy[k];
					int nx = x + dx[k];

					if (ny >= 0 && nx >= 0 && ny < n && nx < n)
					{
						if (board[ny][nx] > 0) growth[y][x]++;
					}
				}
			}
		}
	}

	// Apply growth after calculating all
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; ++x)
		{
			if (board[y][x] > 0)
			{
				board[y][x] += growth[y][x];
			}
		}
	}
}

void reproduce(vector<pii>& temp) {

	vector<vector<int>> tempBoard(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			tempBoard[i][j] = board[i][j];
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; ++x)
		{
			if (board[y][x] > 0)
			{
				temp.clear();
				int newTree = 0;
				for (int k = 0; k < 4; ++k)
				{
					int ny = y + dy[k];
					int nx = x + dx[k];

					// count how many empty adj's
					// boundary condition
					if (ny >= 0 && nx >= 0 && ny < n && nx < n &&
						// empty?
						board[ny][nx] == 0 &&
						// bomb condition
						bomb[ny][nx] == 0)
					{
						temp.push_back({ ny, nx });
						newTree++;
					}
				}
				if (newTree == 0) continue;

				int newTreeSize = board[y][x] / newTree;
				for (int i = 0; i < temp.size(); ++i)
				{
					tempBoard[temp[i].first][temp[i].second] += newTreeSize;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			board[i][j] = tempBoard[i][j];
		}
	}


}

void getBestPosition(vector<int>& container) {
	container.clear();

	int maxX = -1;
	int maxY = -1;
	int maxScore = 0;
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			if (board[y][x] > 0)
			{
				// score from center of bomb
				int currentScore = board[y][x];
				// diagonal direction
				for (int j = 0; j < 4; ++j)
				{
					// bomb length
					for (int i = 1; i <= k; ++i)
					{
						int ny = y + i * bombY[j];
						int nx = x + i * bombX[j];
						//wall condition
						if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1 ||
							bomb[ny][nx] == -1) break;
						if (board[ny][nx] > 0)
						{
							currentScore += board[ny][nx];
						}
						else break;
					}
				}
				if (currentScore > maxScore)
				{
					maxY = y;
					maxX = x;
					maxScore = currentScore;
				}
			}
		}
	}
	container.push_back(maxY);
	container.push_back(maxX);
	container.push_back(maxScore);
}

void dropBomb(int y, int x) {
	board[y][x] = 0;
	bomb[y][x] = c;
	// diagonal direction
	for (int j = 0; j < 4; ++j)
	{
		// bomb length
		for (int i = 1; i <= k; ++i)
		{
			int ny = y + i * bombY[j];
			int nx = x + i * bombX[j];
			//wall condition
			if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1 ||
				bomb[ny][nx] == -1) break;
			// Apply herbicide
			if (board[ny][nx] > 0)
			{
				board[ny][nx] = 0;
				bomb[ny][nx] = c;
			}
			else
			{
				bomb[ny][nx] = c;
				break; // Stop at empty cell
			}
		}
	}
}

int main() {

	int score = 0;
	cin >> n >> m >> k >> c;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == -1) bomb[i][j] = -1;
		}
	}

	// cout << "initial: =====" << '\n';
	// for (int y = 0; y < n; y++)
	// {
	//     for (int x = 0; x < n; ++x)
	//     {
	//         cout << board[y][x] << ' ';
	//     }
	//     cout << '\n';
	// }
	// cout << "========\n";
	for (int i = 0; i < m; ++i)
	{
		// bomb reduction
		reduceBomb();

		// growth
		growth();

		cout << "after growth  year:" << i << '\n';
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; ++x)
			{
				cout << board[y][x] << ' ';
			}
			cout << '\n';
		}
		cout << "============\n";
		// reproduce
		vector<pii> temp;
		reproduce(temp);

		cout << "after reproduce year:" << i << '\n';
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; ++x)
			{
				cout << board[y][x] << ' ';
			}
			cout << '\n';
		}
		cout << "============\n";
		// find best bomb position
		vector<int> container;
		getBestPosition(container);

		// drop bomb
		dropBomb(container[0], container[1]);

		score += container[2];

		cout << "Board after erase year: " << i << '\n';
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; ++x)
			{
				cout << board[y][x] << ' ';
			}
			cout << '\n';
		}
		cout << "----------------------------\n";

		cout << "Bomb map\n";
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; ++x)
			{
				cout << bomb[y][x] << ' ';
			}
			cout << '\n';
		}
		cout << "============================\n";
	}

	cout << score;
	return 0;
}