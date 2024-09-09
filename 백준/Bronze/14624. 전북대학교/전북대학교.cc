#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	if (N % 2 != 0) {
		for (int i = 0; i < 3+((N-3)/2); i++) {
			for (int j = 0; j < N; j++) {
				if (i == 0)
					cout << '*';
				else if ((N / 2) - (i - 1) == j || (N / 2) + (i - 1) == j)
					cout << '*';
				else if ((N / 2) + (i - 1) < j)
					break;
				else
					cout << ' ';
			}
			cout << '\n';
		}
	}
	else
		cout << "I LOVE CBNU";
	return 0;
}