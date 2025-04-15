#include <iostream>
#include <vector>
using namespace std;

const int baseScore = 1'000'000;

int GetMaxPoint(vector<int>& v, int m) {
    vector<int> lis;
    int ans = 0;

        int firstAddedAtTail = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), v[i]);
        int idx = it - lis.begin();;
        if (it == lis.end())
        {
            lis.push_back(v[i]);
            firstAddedAtTail = v[i];
        }
        else
        {
            lis[idx] = v[i];
        }
        // use cable car, destination will be determined after find LIS for full v
        if (i == m - 1)
        {
            // idx = m까지의 길이 -1 = 등산의 횟수
            // 거기에 케이블카 사용점수
            ans += baseScore *(idx+1);
        }
    }
    int last = lis.back();
    
    // lis의 길이 - 1 = 등산의 횟수
    ans += baseScore * ( lis.size()-1) + firstAddedAtTail;

    return ans;
}

int main() {

    // max point =    (LIS with endPoint=arr.size()-1) 
    //              + (LIS with endPoint = m_index-1) 
    //              + (cable car point)

    int Q; cin >> Q;

    vector<int> mntn;
    for (int i = 0; i < Q; ++i)
    {
        int cmd; cin >> cmd;

        if (cmd == 100)
        {
            int n; cin >> n;
            for (int i = 0; i < n; ++i)
            {
                int h; cin >> h;
                mntn.push_back(h);
            }
        }
        else if (cmd == 200)
        {
            int h; cin >> h;
            mntn.push_back(h);
        }
        else if (cmd == 300)
        {
            mntn.pop_back();
        }
        else if (cmd == 400)
        {
            int m; cin >> m;
            cout << GetMaxPoint(mntn, m) << '\n';
        }
    }
    return 0;
}