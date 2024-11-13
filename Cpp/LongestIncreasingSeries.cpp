#include <iostream>   
#include <vector>

using namespace std;


int main() {             
    ios::sync_with_stdio(false);  
    cin.tie(0);                   
    cout.tie(0);
    int n;                     
    cin >> n;                 

    vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

    vector<int> tails;

    for (int num : arr)
    {
        if (tails.empty())
        {
            tails.push_back(num);
            continue;
        }

		auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end())
        {
			tails.push_back(num);
        }
        else
        {
            *it = num;
        }
    }

	cout << tails.size();

    return 0;                    
}