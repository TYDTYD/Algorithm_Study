#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	sort(v.begin(), v.end());
	int mx = v.back();
	int mn = v.front();
	if (mx >= v[0] + v[1])
		mx = v[0] + v[1] - 1;
	cout << mx + v[0] + v[1];
	return 0;
}