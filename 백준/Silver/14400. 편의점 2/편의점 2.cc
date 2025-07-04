#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> posX, posY;
	long long answer = 0;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		posX.push_back(x);
		posY.push_back(y);
	}

	sort(posX.begin(), posX.end());
	sort(posY.begin(), posY.end());

	pair<long long, long long> pos = { posX[n / 2],posY[n / 2] };

	for (int i = 0; i < n; i++) {
		answer += abs(pos.first - posX[i]) + abs(pos.second - posY[i]);
	}

	cout << answer;

	return 0;
}