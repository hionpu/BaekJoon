#include <iostream>   

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int A, B;

    while (true)
    {
        cin >> A >> B;
        if (A == 0 && B == 0) break;
        else
        {
            if (A > B)
            {
                while (A >= B)
                {
                    A -= B;
                }
                if (A == 0) cout << "multiple" << '\n';
                else cout << "neither" << '\n';
            }
            else
            {
                while (B >= A)
                {
                    B -= A;
                }
                if (B == 0) cout << "factor" << '\n';
                else cout << "neither" << '\n';
            }
        }
    }
    return 0;
}