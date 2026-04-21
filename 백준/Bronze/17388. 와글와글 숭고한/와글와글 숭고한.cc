#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<pair<int,string>> score(3);
	int sum = 0;
	score[0].second = "Soongsil";
	score[1].second = "Korea";
	score[2].second = "Hanyang";
	for (int i = 0; i < 3; i++) {
		cin >> score[i].first;
		sum += score[i].first;
	}

	if (sum >= 100) {
		cout << "OK";
	}
	else{
		sort(score.begin(), score.end(), [](pair<int, string>& x, pair<int, string>& y) {
			return x.first < y.first;
			}
		);
		cout << score.front().second;
	}
	return 0;
}