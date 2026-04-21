#include <iostream>
using namespace std;


long long multiple(long long a, long long b, long long c) {
	if (b == 1) 
		return a % c;
	long long val = multiple(a, b / 2, c);
	val = val * val % c;
	if (b % 2 == 0)
		return val;
	return val * a % c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b, c;
	cin >> a >> b >> c;
	cout << multiple(a, b, c);

	return 0;
}