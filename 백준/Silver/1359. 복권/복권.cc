#include <iostream>
using namespace std;

long double calc(int n, int m) {
	long double total = 1;
	long double div = 1;
	for (int i = 0; i < m; i++)
		total *= (n - i);	
	for (int i = 1; i <= m; i++)
		div *= i;;
	return total / div;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;

	long double total = calc(n, m) * calc(n, m);
	long double count = 0;
	for (int i = 0; i < k; i++)
		count += calc(m, i) * calc(n - m, m - i);
	count *= calc(n, m);

	cout.fixed;
	cout.precision(12);

	long double answer = 1 - count / total;

	cout << answer;
	return 0;
}