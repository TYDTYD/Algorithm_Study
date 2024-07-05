#include<iostream>
#include <string>
using namespace std;

char graph[51][51];
int n;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

bool recur(int k) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int result = gcd(i + k, j + k);
			if (result == 1 && graph[i - 1][j - 1] != '1')
				return false;
			else if (result != 1 && graph[i - 1][j - 1] == '1')
				return false;
		}
	}
	return true;
}

bool isValid() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];
	}
	for (int i = 0; i <= 1000; i++) {
		if (recur(i))
			return true;
	}

	return false;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		if(isValid())
			cout << '#' << i + 1 << " YES" << '\n';
		else
			cout << '#' << i + 1 << " NO" << '\n';
	}
	return 0;
}