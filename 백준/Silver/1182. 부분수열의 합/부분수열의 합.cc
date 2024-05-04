#include <iostream>
#include <vector>
using namespace std;

int N, S, a[20], answer = 0;
void back(int n, int total) {
	if (n == N) {
		if (total == S)
			answer++;
		return;
	}
	back(n + 1, total);
	back(n + 1, total+a[n]);
}


int main() {
	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> a[i];

	back(0, 0);
	if (S == 0)
		answer--;

	cout << answer;

	return 0;
}