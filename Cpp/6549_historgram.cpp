#include <iostream>   
#include <vector>

using namespace std;

typedef long long ll;

static ll mid_span_area(const vector<ll>& hist, ll start, ll mid, ll end) {
	ll maxArea = hist[mid];
	ll left = mid;
	ll right = mid;
	ll minHeight = hist[mid];

	while (left > start || right < end)
	{
		if (left == start)
		{
			right++;
			minHeight = min(minHeight, hist[right]);
		}
		else if (right == end)
		{
			left--;
			minHeight = min(minHeight, hist[left]);
		}
		else
		{
			if (hist[left - 1] > hist[right + 1])
			{
				left--;
				minHeight = min(minHeight, hist[left]);
			}
			else
			{
				right++;
				minHeight = min(minHeight, hist[right]);
			}
		}
		maxArea = max(maxArea, minHeight * (right - left + 1));
	}
	return maxArea;
}

static ll max_area(const vector<ll>& hist, ll start, ll end) {
	if (start > end) return 0;
	if (start == end) return hist[start];

	ll mid = (start + end) / 2;

	ll leftMax = max_area(hist, start, mid - 1);
	ll rightMax = max_area(hist, mid + 1, end);
	ll midSpanMax = mid_span_area(hist, start, mid, end);

	return max({ leftMax, rightMax, midSpanMax });
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{

		ll N; cin >> N;

		if (N == 0) break;

		vector<ll> hist(N, 0);
		for (ll i = 0; i < N; i++)
		{
			cin >> hist[i];
		}
		cout << max_area(hist, 0, N - 1) <<'\n';
	}

	return 0;
}