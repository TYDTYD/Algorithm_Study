#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[1001];
vector<int> two;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	for (const auto& array1 : a) {
		for (const auto& array2 : a) {
			two.push_back(array1 + array2);
		}
	}

	sort(two.begin(), two.end());

	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (binary_search(two.begin(), two.end(), a[i] - a[j])) {
				cout << a[i];
				return 0;
			}
		}
	}

	return 0;
}