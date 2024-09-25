#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b;
	int answer = 0;
	vector<int> v;
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.emplace_back(t);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		int time = 0, num = 0;
		for (int j = 1; j <= i; j++) {
			if (time + a <= v[j - 1]) {
				time += a;
				num++;
			}
		}
		int store = num;
		int timeIdx = time;
		int idx = i;
		for (int j = 0; j < a; j++) {
			idx = i;
			time = timeIdx;
			time += b * j;
			num = store;
			while (idx < n) {
				if (time+(a-j)>v[idx])
					break;
				time += a - j;
				idx++;
				num++;
			}
			answer = max(answer, num);
		}
		
	}
	
	cout << answer;
	return 0;
}