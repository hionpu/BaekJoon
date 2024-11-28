#include <iostream>   

using namespace std;
int arr[16];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    arr[1] = 3;
    for (int i = 2; i <= N; i++)
    {
        arr[i] = arr[i - 1] * 2 - 1;
    }

    cout << arr[N]*arr[N] << '\n';


    return 0;
}