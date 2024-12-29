#include <iostream>
using namespace std;

int main() {
	int N;
	char str[11];
	cin >> N >> str;

	int time = 0, select = 0;
	bool drift = false;
	for (int i = 0; i < N; i++) {
		if (time >= 2)
			break;
		if (time == 1 && str[i] == 'P') {
			drift = true;
		}
		if (str[i] == 'W')
			time++;
		else
			select++;
	}

	if (time < 2)
		cout << 0;
	else {
		if (drift)
			cout << 6;
		else if (select % 2 == 0)
			cout << 5;
		else
			cout << 1;
	}

	return 0;
}