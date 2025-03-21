#include <iostream>
#include <string>
using namespace std;

string pic[540000];

void solve(int n,int start, int end) {
	if (n == 0)
		return;
	int num = (end - start) / 3;
	for (int i = start + num; i < end - num; i++) {
		pic[i] = ' ';
	}
	solve(n - 1, start, start + num);
	solve(n - 1, end - num, end);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n) {
		int num = 1;
		for (int i = 0; i < n; i++)
			num *= 3;
		for (int i = 0; i < num; i++)
			pic[i] = '-';
		solve(n, 0, num);
		for (int i = 0; i < num; i++)
			cout << pic[i];
		cout << '\n';
	}
	return 0;
}