#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	int time = a * 60 + b;
	int c;
	cin >> c;
	time += c;
	int hour = time / 60;
	int minute = time % 60;
	cout << hour % 24 << ' ' << minute;
	return 0;
}