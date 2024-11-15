#include <iostream>
#include <tuple>
using namespace std;

pair<long long,long long> calc(int a[15], int idx, int n) {
	if (idx == n-1)
		return make_pair(1, a[idx]);
	return make_pair(calc(a, idx + 1, n).second, a[idx] * calc(a, idx + 1, n).second + calc(a, idx + 1, n).first);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, arr[15];
	pair<long long, long long> result;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	result = calc(arr, 0, n);
	cout << result.second - result.first << ' ' << result.second;
	return 0;
}