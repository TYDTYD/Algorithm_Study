#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int num = 1;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		bool result = false;
		if (a > b && a > c)
			result = a * a == b * b + c * c;		
		else if (b > a && b > c)
			result = b * b == a * a + c * c;		
		else if (c > a && c > b)
			result = c * c == a * a + b * b;		
		else
			result = false;		
		cout << "Case #" << num++ << ": ";
		if (result)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}