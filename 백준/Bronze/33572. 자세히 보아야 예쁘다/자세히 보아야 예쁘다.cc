#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	long long time = 0;
	for (int i = 0; i < n; i++) {
		long long t;
		cin >> t;
		time += t - 1;
	}
	if (m>time)
		cout << "OUT";
	else
		cout << "DIMI";
	return 0;
}