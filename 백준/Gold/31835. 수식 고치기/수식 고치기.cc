#include <iostream>
#include <string>
using namespace std;

bool combine(bool x, bool y, char c) {
	if (c == '&')
		return x && y;
	return x || y;
}

bool trans(char a) {
	if (a == 'T')
		return true;
	return false;
}

int main() {
	int n;
	cin >> n;
	char c[2001], res;
	bool idx, result;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	cin >> res;
	result = trans(res);
	

	if (n == 1) {
		if (result == trans(c[n]))
			cout << 0;
		else
			cout << 1;
		return 0;
	}

	if (n > 3)
		idx = combine(trans(c[1]), trans(c[3]), c[2]);
	else
		idx = trans(c[1]);
	
	for (int i = 5; i <= n - 2; i++) {
		idx = combine(idx, trans(c[i]), c[i - 1]);
	}

	if (idx) {
		if (c[n - 1] == '&') {
			if (trans(c[n])) {
				if (result)
					cout << 0;
				else
					cout << 1;
			}
			else {
				if (result)
					cout << 1;
				else
					cout << 0;
			}
		}
		else {
			if (trans(c[n])) {
				if (result)
					cout << 0;
				else
					cout << 2;
			}
			else {
				if (result)
					cout << 0;
				else
					cout << 1;
			}
		}
	}
	else {
		if (c[n - 1] == '&') {
			if (trans(c[n])) {
				if (result)
					cout << 1;
				else
					cout << 0;
			}
			else {
				if (result)
					cout << 2;
				else
					cout << 0;
			}
		}
		else {
			if (trans(c[n])) {
				if (result)
					cout << 0;
				else
					cout << 1;
			}
			else {
				if (result)
					cout << 1;
				else
					cout << 0;
			}
		}
	}

	return 0;
}