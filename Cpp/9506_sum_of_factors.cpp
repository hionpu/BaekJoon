#include <iostream>   
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> factors;

    while (true)
    {
        int n;
        cin >> n;
        if (n == -1) break;
        else
        {
            factors.clear();
            int sum = 0;
            for (int i = 1; i <= n / 2; i++)
            {
                if (n % i == 0)
                {
                    factors.push_back(i);
                    sum += i;
                }
            }
            if (sum == n)
            {
                cout << n << " = ";
                for (size_t i = 0; i < factors.size(); i++)
                {
                    cout << factors[i];
                    if (i != factors.size() - 1)
                    {
                        cout << " + ";
                    }
                }
                cout << '\n';
            }
            else cout << n << " is NOT perfect." << '\n';
        }
    }
    return 0;
}