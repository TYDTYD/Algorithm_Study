#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, c = 1, total = 1;
	cin >> x;

	bool w = false;

	while (x > 0) {
		x -= c++;
		w = !w;
		total++;
	}

	int diff = total + x - 1;
	if (w)
		cout << total - diff << '/' << diff;
	else
		cout << diff << '/' << total - diff;

	return 0;
}