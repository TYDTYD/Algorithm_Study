#include <iostream>
#include <string>
using namespace std;

string s;
int answer = -310000000, n;
void solve(int count, int result) {
	if (count > n){
		answer = max(answer, result);
		return;
	}
	if (count + 2 < n) {
		int tmp1, tmp2, res;
		tmp1 = (s[count] - '0');
		tmp2 = (s[count + 2] - '0');
		if (s[count + 1] == '*')
			res = tmp1 * tmp2;
		else if (s[count + 1] == '-')
			res = tmp1 - tmp2;
		else if (s[count + 1] == '+')
			res = tmp1 + tmp2;
		if (count == 0)
			solve(4, res);
		else {
			if (s[count - 1] == '+')
				solve(count + 4, result + res);
			else if (s[count - 1] == '-')
				solve(count + 4, result - res);
			else if (s[count - 1] == '*')
				solve(count + 4, result * res);
		}
	}

	int num = s[count] - '0';
	if (count == 0)
		solve(2, num);
	else {
		if (s[count - 1] == '*')
			solve(count + 2, result * num);
		else if (s[count - 1] == '-')
			solve(count + 2, result - num);
		else if (s[count - 1] == '+')
			solve(count + 2, result + num);
	}
	
	return;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> s;
	solve(0, 0);
	cout << answer;
	return 0;
}