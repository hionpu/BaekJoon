#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;
const double PI = acos(-1);
vector<double> cos_vals(8);
vector<double> sin_vals(8);

bool is_convex(vector<int>& arr) {
    for (int i = 0; i < 8; ++i)
    {
        int j = (i + 1) % 8;
        int k = (i + 2) % 8;

        double x1 = arr[i] * cos_vals[i];
        double y1 = arr[i] * sin_vals[i];

        double x2 = arr[j] * cos_vals[j];
        double y2 = arr[j] * sin_vals[j];

        double x3 = arr[k] * cos_vals[k];
        double y3 = arr[k] * sin_vals[k];

        if ((x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2) < 0)
        {
            return false;
        }
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 8; ++i)
    {
        double ang = i * PI/4.0;
        cos_vals[i] = cos(ang);
        sin_vals[i] = sin(ang);
    }

    vector<int> stats(8);
    for (int i = 0; i < 8; ++i) cin >> stats[i];

    int count = 0;

    vector<int> indices = { 1,2,3,4,5,6,7 };

    do
    {
        vector<int> current(8);
        current[0] = stats[0];

        for (int i = 0; i < 7; ++i)
        {
            current[i + 1] = stats[indices[i]];
        }

        if (is_convex(current)) count++;
    } while (next_permutation(indices.begin(), indices.end()));


    cout << count * 8 << '\n';
    return 0;
}