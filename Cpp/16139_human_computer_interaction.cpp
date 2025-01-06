#include <iostream>
#include <string>
using namespace std;

// 50점 맞은 이유는 서브태스크 1의 문자열 길이 2000자를 보고 문제를 풀어서 그럼, 위에 문제에서는 q가 200,000까지 가능하다고 해서 혹시나 해서 범위를 2001에서 200001로 키웠더니 100점 맞음
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    int q, start, end;
    int counts[27][200001];
    char letter;

    cin >> S >> q;
    counts[S[0] - 'a'][0] = 1;
    for (int i = 1; i < S.size(); i++)
    {
        for (int j = 0; j < 27; j++)
        {
            counts[j][i] = counts[j][i - 1];
        }
        counts[S[i] - 'a'][i]++;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> letter >> start >> end;
        int temp = letter - 'a';
        if (start == 0)
            cout << counts[letter - 'a'][end] << '\n';
        else
            cout << counts[letter - 'a'][end] - counts[letter - 'a'][start - 1] << '\n';
        // if (start == 0)
        //     cout << counts[temp][end] << '\n';
        // else
        //     cout << counts[temp][end] - counts[temp][start - 1] << '\n';
    }

    return 0;
}