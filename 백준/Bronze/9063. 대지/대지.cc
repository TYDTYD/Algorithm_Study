#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v1, v2;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v1.push_back(x);
		v2.push_back(y);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int a = v1.back() - v1.front();
	int b = v2.back() - v2.front();
	cout << a * b;
	return 0;
}