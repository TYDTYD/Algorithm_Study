#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, w, h;
	cin >> n >> w >> h;
	int diagonal = w * w + h * h;
	while (n--) {
		int length;
		cin >> length;

		if (diagonal >= length * length) {
			cout << "DA" << '\n';
		}
		else {
			cout << "NE" << '\n';
		}
	}

	return 0;
}