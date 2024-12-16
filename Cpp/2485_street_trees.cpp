#include <iostream>   
#include <set>

using namespace std;

long long  static gcd(long long  a, long long  b) {
    long long  A = max(a, b);
    long long B = min(a, b);
    while (true)
    {
        if (A % B == 0) break;
        long long temp = A - B;
        A = max(temp, B);
        B = min(temp, B);
    }
    return B;
}
    long long trees[100000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i <N; i++)
    {
        cin >> trees[i];
    }
    long long a = trees[1] - trees[0];
    long long b = 0;
    for (int j = 2; j < N; j++)
    {
        b = trees[j] - trees[j - 1];
        a = gcd(a, b);
    }
    int g = a;

    
    long long result = 0;
    for (int k = 1; k < N; k++)
    {
        result += (trees[k] - trees[k - 1]) / g - 1;
    }
    
    cout << result << '\n';
    return 0;
}