#include <iostream>
#include <vector>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	int n;
	cin >> n;
	vector<pair<int,int>> sticker(n);
	int answer = 0;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		sticker[i] = { x, y };
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int area = sticker[i].first * sticker[i].second + sticker[j].first * sticker[j].second;
			if (max(sticker[i].first, sticker[j].first) <= h && sticker[i].second + sticker[j].second <= w)
				answer = max(answer, area);
			if (max(sticker[i].first, sticker[j].second) <= h && sticker[i].second + sticker[j].first <= w)
				answer = max(answer, area);
			if (max(sticker[i].second, sticker[j].first) <= h && sticker[i].first + sticker[j].second <= w)
				answer = max(answer, area);
			if (max(sticker[i].second, sticker[j].second) <= h && sticker[i].first + sticker[j].first <= w)
				answer = max(answer, area);

			if (max(sticker[i].first, sticker[j].first) <= w && sticker[i].second + sticker[j].second <= h)
				answer = max(answer, area);
			if (max(sticker[i].first, sticker[j].second) <= w && sticker[i].second + sticker[j].first <= h)
				answer = max(answer, area);
			if (max(sticker[i].second, sticker[j].first) <= w && sticker[i].first + sticker[j].second <= h)
				answer = max(answer, area);
			if (max(sticker[i].second, sticker[j].second) <= w && sticker[i].first + sticker[j].first <= h)
				answer = max(answer, area);
		}
	}

	cout << answer;
	return 0;
}