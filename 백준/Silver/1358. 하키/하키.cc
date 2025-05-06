#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int w, h, x, y, p;
	cin >> w >> h >> x >> y >> p;
	int r = h / 2;
	int answer = 0;
	for (int i = 0; i < p; i++) {
		int ax, ay;
		cin >> ax >> ay;
		if (x <= ax && y <= ay && x + w >= ax && y + h >= ay)
			answer++;
		else if ((x - ax) * (x - ax) + (y + r - ay) * (y + r - ay) <= r * r)
			answer++;
		else if ((x + w - ax) * (x + w - ax) + (y + r - ay) * (y + r - ay) <= r * r)
			answer++;
	}
	cout << answer;
	return 0;
}