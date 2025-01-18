#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int t;
	while (cin >> t) {
		if (t == 0)
			break;
		vector<pair<string, double>> list;
		for (int i = 0; i < t; i++) {
			string name;
			double tall;
			cin >> name >> tall;
			list.emplace_back(make_pair(name, tall));
		}

		sort(list.begin(), list.end(), [](pair<string, double>& a, pair<string, double>& b) -> bool {
			return a.second > b.second;
			});
		double answer = list.front().second;
		cout << list.front().first << ' ';
		if (t == 1)
			continue;
		int index = 1;
		while (answer == list[index].second) {
			cout << list[index++].first << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}