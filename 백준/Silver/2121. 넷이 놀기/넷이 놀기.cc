#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a, b, answer = 0;
	vector<pair<int,int>> v(n);
	cin >> a >> b;

	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		pair<int, int> p1 = make_pair(v[i].first + a, v[i].second + b);
		pair<int, int> p2 = make_pair(v[i].first , v[i].second + b);
		pair<int, int> p3 = make_pair(v[i].first + a, v[i].second);
		if (binary_search(v.begin(), v.end(), p1) && binary_search(v.begin(), v.end(), p2)
			&& binary_search(v.begin(), v.end(), p3))
			answer++;
	}

	cout << answer;

	return 0;
}