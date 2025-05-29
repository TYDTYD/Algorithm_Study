#include <iostream>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;

	h *= 100;
	w *= 100;

	cout << min(h / 2, w / 2);

	return 0;
}