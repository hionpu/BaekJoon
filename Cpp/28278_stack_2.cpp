#include <iostream>   
#include <stack>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    stack<int> s;
    int N;
    cin >> N;

    while (N--)
    {
        int command;
        cin >> command;

        switch (command)
        {
        case 1:
            int X; cin >> X;
            s.push(X);
            break;
        case 2:
            if (s.empty()) cout << -1 << '\n';
            else
            {
                cout << s.top() << '\n';
                s.pop();
            }
            break;
        case 3:
            cout << s.size() << '\n';
            break;

        case 4:
            cout << s.empty() << '\n';
            break;

        case 5:
            if (s.empty()) cout << -1 << '\n';
            else
            {
                cout << s.top() << '\n';
            }
            break;

        }
    }
    return 0;
}