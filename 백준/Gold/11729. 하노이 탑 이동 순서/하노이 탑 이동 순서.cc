#include <iostream>

using namespace std;

void move(int from, int to)
{
	cout << from << " " << to << '\n';
}

void hanoi(int n, int from, int by, int to)
{
	if (n == 0)
		return;
	// n - 1번째 원판을 1에서 2로 옮기는 함수
	hanoi(n - 1, from, to, by);
	move(from, to); // 1에서 3으로 옮기는 함수
	// n - 1번째 원판을 2에서 3으로 옮기는 함수
	hanoi(n - 1, by, from, to);
}

int main() {
	int k;
	cin >> k;

	cout << (2 << k-1) - 1 << '\n';

	hanoi(k, 1, 2, 3);


	return 0;
}