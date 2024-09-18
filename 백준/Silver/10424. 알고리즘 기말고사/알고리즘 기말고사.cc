#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, arr[100001],result[100001];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		result[arr[i]] = arr[i] - i;
	}
	for (int i=1; i<=n; i++)
		cout << result[i] << '\n';
	return 0;
}