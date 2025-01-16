#include <iostream>
using namespace std;

int main() {
	int a = 1;
	
	while (a) {
		int answer = 1;
		cin >> a;
		if (a == 0)
			break;
		for (int i = 0; i < a; i++) {
			int factor, remove;
			cin >> factor >> remove;
			answer *= factor;
			answer -= remove;
		}
		cout << answer << '\n';
	}

	return 0;
}