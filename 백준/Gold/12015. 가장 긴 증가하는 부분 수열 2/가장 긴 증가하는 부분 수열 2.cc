#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int LCS(vector<int>& list) {
	vector<int> result;
	for (int i = 0; i < list.size(); i++) {
		if (result.empty() || result.back() < list[i])
			result.push_back(list[i]);
		else if (result.back() > list[i]) {
			auto it = lower_bound(result.begin(), result.end(), list[i]);
			*it = list[i];
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