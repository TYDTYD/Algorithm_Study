#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int LCS(vector<int>& arr) {
	vector<int> result;
	for (const int& n:arr) {
		if (result.empty() || result.back() < n)
			result.push_back(n);
		else if (result.back() > n) {
			auto it = lower_bound(result.begin(), result.end(), n);
			*it = n;
		}
	}
	return result.size();
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	cout << LCS(arr);
	return 0;
}