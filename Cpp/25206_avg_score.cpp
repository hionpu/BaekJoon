#include <iostream>   
#include <map>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<string, float> scoreMap;
    float k = 4.5;
    scoreMap.insert(make_pair("A+", k));
    k -= 0.5;
    scoreMap.insert(make_pair("A0", k));
    k -= 0.5;
    scoreMap.insert(make_pair("B+", k));
    k -= 0.5;
    scoreMap.insert(make_pair("B0", k));
    k -= 0.5;
    scoreMap.insert(make_pair("C+", k));
    k -= 0.5;
    scoreMap.insert(make_pair("C0", k));
    k -= 0.5;
    scoreMap.insert(make_pair("D+", k));
    k -= 0.5;
    scoreMap.insert(make_pair("D0", k));
    k -= 1;
    scoreMap.insert(make_pair("F", k));

    float h = 0;
    float total = 0;
    for (int i = 0; i < 20; i++)
    {
        string subject;
        float m;
        string s;

        cin >> subject >> m >> s;
        if (s == "P") continue;
        h += m;
        total += m * scoreMap.find(s)->second;
    }
    cout << total / h << '\n';
    
    return 0;
}