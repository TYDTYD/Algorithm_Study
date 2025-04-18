#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<pair<int, int>> v1;
	vector<pair<int, int>> v2;
	pair<int, int> answer;
	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		v1.push_back({ x,0 });
		v2.push_back({ y,0 });
	}

	for (int i = 0; i < 3; i++) {
		int count1 = 0;
		int count2 = 0;
		for (int j = 0; j < 3; j++) {
			if (v1[i].first == v1[j].first)
				count1++;
			if (v2[i].first == v2[j].first)
				count2++;
		}
		if (count1 == 1)
			answer.first = v1[i].first;
		if (count2 == 1)
			answer.second = v2[i].first;
	}

	cout << answer.first << ' ' << answer.second;
	return 0;
}