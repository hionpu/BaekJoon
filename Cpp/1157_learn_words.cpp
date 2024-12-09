#include <iostream>   

using namespace std;
int arr[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string word;
    cin >> word;

    for (char c : word)
    {
        if (c >= 97) c = c - 32;
        arr[c - 65]++;
    }

    int maxNum = 0;
    int maxIndex = 0;
    for (int i = 0; i < 26;i++)
    {
        if (arr[i] > maxNum)
        {
            maxNum = arr[i];
            maxIndex = i;
        }
    }
    int maxCount = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == maxNum)
        {
            maxCount++;
        }
    }
    if (maxCount > 1) cout << '?' << '\n';
    else cout << (char)(maxIndex+65);
    return 0;
}