#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	long long answer = 0;
	bool first = true;
	bool pass = true;
	for (int i = 0; i < n; i++) {
		long long c;
		cin >> c;
		if (i == 0 && c == 0)
			first = false;
		// 쪽방이 있는 경우
		if (c) {
			pass = true;
		}
		// 쪽방이 없는 경우
		else {
			if (i == n - 1) {
				if (first && pass)
					answer++;
				continue;
			}
			// 전 순서의 방을 개미집으로 잡지 않은 경우
			if (pass) {
				answer++;
				pass = false;
			}
			// 전 순서의 방을 개미집으로 잡은 경우
			else {
				pass = true;
			}
		}
		answer += c;
	}

	cout << answer;

	return 0;
}