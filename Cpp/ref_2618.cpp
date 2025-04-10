#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

pair<int, int> c[1010];
int d[1010];
int linkk[1010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, w; cin >> n >> w;
    vector<pair<int, int>> v;
    c[0] = { 1, 1 };
    c[1] = { n, n };
    pair<int, int> prev;
    const int INF = 1'000'0000;
    for (int i = 2; i <= w + 1; ++i)
    {
        int x, y; cin >> x >> y;
        c[i] = { x, y };
        if (i == 2)
        {
            d[0] += abs(x - n) + abs(y - n);
            d[1] += abs(x - 1) + abs(y - 1);
        }
        else
        {
            // �ܼ��� transition�� ���� �ʱ����� d[0], d[1]�� �����ϱ� ���� i�� 2���� �����ϴ� ���̰� ����
			// for loop���� i�� i-1��° ��Ǳ��� ó���� ���¸� �ǹ��Ѵ�.
            d[i - 1] = INF;
            for (int j = i - 2; j >= 0; --j)
            {
                // �̺κа�(j��° ��Ǳ��� ������ �ִ� � �������� �̹� i-1��°���� ���� ����� ó���ϴ� ���)
                int cost = d[j] + abs(x - c[j].first) + abs(y - c[j].second);
                if (d[i - 1] > cost)
                    d[i - 1] = cost, linkk[i - 1] = j;
                // �̺κ��� �и��ؼ� �����ؾ���(j��° ��Ǳ��� ������ �ִ� � �������� ������ ������ �ְ� �ٸ� ���� ó���ϴ� ���)
                d[j] += abs(x - prev.first) + abs(y - prev.second);
            }
        }
        prev = { x, y };
    }
    int ans = INF, ind;
    for (int j = 0; j <= w; ++j)
        if (ans > d[j])
            ans = d[j], ind = j;
    cout << ans << '\n';
    vector<int> ret;
    for (; ind > 1; ind = linkk[ind])
        ret.push_back(ind);
    ret.push_back(ind);
    int num = 2 - ret.back(); ret.pop_back();
    for (int i = 1; i <= w; ++i)
    {
        if (!ret.empty() && i == ret.back())
            num ^= 3, ret.pop_back();
        cout << num << '\n';
    }
}