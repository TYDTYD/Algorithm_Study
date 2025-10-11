#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b;
	a = b = -1;
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) 
			break;
		cout << min(a,b) - abs(a - b) << '\n';
	}
	return 0;
}