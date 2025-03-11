#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int h, m;
	cin >> h >> m;
	if (h == 0 && m < 45)
		h += 24;
	int time = 0;
	time += h * 60;
	time += m;
	time -= 45;
	int hour = time / 60;
	int minute = time % 60;
	cout << hour << ' ' << minute;

	return 0;
}