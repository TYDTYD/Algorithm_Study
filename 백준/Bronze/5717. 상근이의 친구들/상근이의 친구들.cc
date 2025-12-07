#include <iostream>
using namespace std;

int main() {
	int m, f;
	while (cin >> m >> f, m || f) {
		cout << m + f << '\n';
	}
}