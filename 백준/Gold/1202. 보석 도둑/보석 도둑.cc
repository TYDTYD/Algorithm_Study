#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	long long answer = 0;
	cin >> n >> k;
	pair<int, int> juwelry[300003];
	multiset<int> bag;
	for (int i = 0; i < n; i++) {
		cin >> juwelry[i].second >> juwelry[i].first;
	}
	for (int i = 0; i < k; i++) {
		int weight;
		cin >> weight;
		bag.insert(weight);
	}
	sort(juwelry, juwelry + n);
	// 보석 가치가 가장 높은 것부터 가방이 가장 작은 것부터 비교해서 넣는다
	for (int i = n - 1; i >= 0; i--) {
		int v = juwelry[i].first;
		int m = juwelry[i].second;
		multiset<int>::iterator it=bag.lower_bound(m);
		if (it == bag.end())
			continue;
		answer += v;
		bag.erase(it);
	}

	cout << answer;

	return 0;
}