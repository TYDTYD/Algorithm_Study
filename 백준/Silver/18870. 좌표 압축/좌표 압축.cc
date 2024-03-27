#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, origin[1000001];
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		origin[i] = x;
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; i++) {
		int target = origin[i];
		int start = 0, end = v.size() - 1, answer = 0, mid;
		while (start < end) {
			mid = (start + end) / 2;
			if (target > v[mid]) {
				start = mid + 1;
				answer = start;
			}
			else if (target == v[mid]) {
				answer = mid;
				break;
			}
			else {
				end = mid - 1;
				answer = end;
			}
		}
		cout << answer << " ";
	}
	

	return 0;
}