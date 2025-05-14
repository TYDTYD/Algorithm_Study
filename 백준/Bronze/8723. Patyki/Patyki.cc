#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> v;

	v.push_back(a);
	v.push_back(b);
	v.push_back(c);

	sort(v.begin(), v.end());

	if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2])
		cout << 1;
	else if (v[0] == v[1] && v[1] == v[2])
		cout << 2;
	else
		cout << 0;

	return 0;
}