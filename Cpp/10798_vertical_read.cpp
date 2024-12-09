#include <iostream>   
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<string> lines;
    int maxLength = 0;
    string result;
    for (int i = 0; i < 5; i++)
    {
        string line;
        cin >> line;
        lines.push_back(line);
        if (maxLength < line.length()) maxLength = line.length();
    }

    for (int i = 0; i < maxLength; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i > lines[j].length() - 1) continue;
            result += lines[j][i];
        }
    }
    cout << result << '\n';
    return 0;
}