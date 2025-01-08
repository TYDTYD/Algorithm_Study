#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, p;
	unordered_map<int,int> result;
	cin >> n >> p;
	int r = n, i = 0;

	while (result.find((r * n) % p)==result.end()) {
		result[(r * n) % p] = i;
		r = (r * n) % p;
		i++;
	}

	cout << i - result[(r * n) % p];

	return 0;
}