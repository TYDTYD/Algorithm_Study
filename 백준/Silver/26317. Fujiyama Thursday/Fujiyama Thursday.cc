#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int c, answer = 0;
		vector<int> t,d;
		cin >> c;
		for (int j = 0; j < c; j++) {
			int dist;
			cin >> dist;
			d.emplace_back(dist);
		}
		for (int j = 0; j < 4 * c; j++) {
			int time;
			cin >> time;
			t.emplace_back(time);
		}
		sort(d.begin(), d.end(), greater<int>());
		sort(t.begin(), t.end());
		for (int j = 3, k = 0; k < c; j += 4, k++) {
			answer = max(t[j] + d[k], answer);
		}
		cout << "Trip #" << i << ": " << answer << '\n';
	}
	return 0;
}