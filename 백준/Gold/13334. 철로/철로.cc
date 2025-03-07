#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

bool compare(pair<ll,ll>& x, pair<ll,ll>& y) {
	return x.second < y.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int answer = 0;
	vector<pair<ll, ll>> tmp, pos;
	for (int i = 0; i < n; i++) {
		ll h, o;
		cin >> h >> o;
		if (h > o)
			tmp.emplace_back(make_pair(o, h));
		else
			tmp.emplace_back(make_pair(h, o));
	}
	long long d;
	cin >> d;
	for (const auto& p:tmp) {
		if (p.second - p.first <= d)
			pos.emplace_back(make_pair(p.first, p.second));
	}
	sort(pos.begin(), pos.end(), compare);
	int length = pos.size();
	priority_queue<ll> pq;
	for (int i = 0; i < length; i++) {
		pq.push(-pos[i].first);
		while (pq.top() > d - pos[i].second)
			pq.pop();
		answer = max(answer, (int)pq.size());
	}
	cout << answer;

	return 0;
}