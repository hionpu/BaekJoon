#include <iostream>   
#include <map>

using namespace std;
int N, M;
bool check[9];
int arr[9];

void backTrack(int len) {
    if (len == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int j = 1; j <= N; j++)
    {
        if (arr[len - 1] <= j)
        {
            check[j] = true;
            arr[len] = j;
            backTrack(len + 1);
            check[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        check[i] = false;
    }
    backTrack(0);



    return 0;
}