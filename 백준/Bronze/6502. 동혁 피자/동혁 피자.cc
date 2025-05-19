#include <iostream>
using namespace std;

int main() {
	long double r, w, l;
	int count = 1;
	while (cin >> r) {
		if (r == 0)
			return 0;
		cin >> w;
		cin >> l;
		w *= 0.5;
		l *= 0.5;
		cout << "Pizza " << count++;
		if (r * r >= w * w + l * l) {
			cout << " fits on the table." << '\n';
		}
		else {
			cout << " does not fit on the table." << '\n';
		}
	}
	
	return 0;
}