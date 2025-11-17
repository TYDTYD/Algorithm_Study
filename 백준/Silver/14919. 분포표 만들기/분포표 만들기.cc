#include <iostream>
using namespace std;

int segment[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin >> m;

	long double value;	

	while (cin >> value) {		
		value += 1e-9;
		value *= 1e9;		
		long long a = static_cast<long long>(value);
		segment[a * m / 1000000000]++;
	}

	for (int i = 0; i < m; i++)
		cout << segment[i] << ' ';

	return 0;
}