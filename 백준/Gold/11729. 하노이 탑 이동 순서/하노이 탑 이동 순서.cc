#include <iostream>

using namespace std;

void hanoi(int n, int from, int by, int to)
{
	if (n == 0)
		return;
	// n - 1번째 원판을 1에서 2로 옮기는 함수
	hanoi(n - 1, from, to, by);
	cout << from << " " << to << '\n';
	// n - 1번째 원판을 2에서 3으로 옮기는 함수
	hanoi(n - 1, by, from, to);
}

int main() {
	int k;
	cin >> k;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout << (2 << k-1) - 1 << '\n';
	hanoi(k, 1, 2, 3);
	return 0;
}