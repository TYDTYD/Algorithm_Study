#include <iostream>
#define MOD 10007
typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	ll c[53][53] = {};
	c[0][0] = 1;
	c[1][0] = 1;
	c[1][1] = 1;
	for (int i = 2; i <= 52; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				c[i][j] = 1;
				continue;
			}
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}
	int index = 1;
	ll answer = 0;
	while (n >= 4 * index && index <= 13) {
		if (index % 2 == 1)
			answer = (answer + c[52 - 4 * index][n - 4 * index] * c[13][index]) % MOD;
		else
			answer = (answer - c[52 - 4 * index][n - 4 * index] * c[13][index] % MOD + MOD) % MOD;
		index++;
	}
	cout << answer;
	return 0;
}