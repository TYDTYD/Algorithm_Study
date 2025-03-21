#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> tmp(n);
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		tmp[i] = t;
	}
	for (int i = 0; i < k; i++)
		answer += tmp[i];
	int index = answer;
	for (int i = k; i < n; i++) {
		index -= tmp[i - k];
		index += tmp[i];
		answer = max(answer, index);
	}
	cout << answer;
	return 0;
}