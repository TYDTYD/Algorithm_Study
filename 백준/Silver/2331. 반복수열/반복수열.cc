#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int a, p;
	cin >> a >> p;
	unordered_map<int, int> m;
	int count = 0;
	while (true) {
		if (m.find(a) != m.end())
			break;
		m[a] = count++;
		int next = 0;
		while (a != 0) {
			int num = a % 10;
			a /= 10;
			int power = 1;
			for (int x = 0; x < p; x++)
				power *= num;
			next += power;
		}
		a = next;
	}
	cout << m[a];

	return 0;
}