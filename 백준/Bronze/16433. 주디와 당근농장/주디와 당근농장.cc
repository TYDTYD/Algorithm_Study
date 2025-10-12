#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, r, c;
	cin >> n >> r >> c;
	bool flag = ((r + c) % 2) != 0;
	bool first = flag;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (flag)
				cout << '.';
			else
				cout << 'v';
			flag = !flag;
		}
		first = !first;
		flag = first;
		cout << '\n';
	}

	return 0;
}