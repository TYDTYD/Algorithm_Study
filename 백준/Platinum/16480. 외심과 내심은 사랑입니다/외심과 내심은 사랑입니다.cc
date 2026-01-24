#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long R, r;
	cin >> R >> r;	
	long long answer = R * (R - 2 * r);
	cout << answer;
	return 0;
}