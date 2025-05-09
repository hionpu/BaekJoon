#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

double ulen(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;


    vector<pair<long long, long long>> points(N);

    for (int i = 0; i < N; i++)
    {
        cin >> points[i].first >> points[i].second;
    }

    // 신발끈 공식(Shoelace formula) 사용
    long long sum1 = 0, sum2 = 0;

    for (int i = 0; i < N; i++)
    {
        sum1 += points[i].first * points[(i + 1) % N].second;
        sum2 += points[i].second * points[(i + 1) % N].first;
    }

    // 면적 계산 (절대값 취함)
    double area = abs(sum1 - sum2) * 0.5;

    cout << fixed << setprecision(1) << area << '\n';
    return 0;
}