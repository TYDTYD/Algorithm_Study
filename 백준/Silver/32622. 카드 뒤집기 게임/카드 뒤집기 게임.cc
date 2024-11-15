#include <iostream>
using namespace std;

int main() {
	int n, answer = 1, result = 1, pre_result = 0;
	cin >> n;
	bool arr[300001], idx;
	cin >> arr[0];
	idx = arr[0];
	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		if (idx!=arr[i]) {
			idx = arr[i];
			answer = max(answer, result+pre_result);
			pre_result = result;
			result = 0;
		}
		result++;
	}
	answer = max(answer, result+pre_result);
	cout << min(n, answer);
	return 0;
}