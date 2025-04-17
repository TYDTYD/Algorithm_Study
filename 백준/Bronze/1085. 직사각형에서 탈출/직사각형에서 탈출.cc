#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int x_mn = min(w - x, x);
	int y_mn = min(h - y, y);

	cout << min(x_mn, y_mn);

	return 0;
}