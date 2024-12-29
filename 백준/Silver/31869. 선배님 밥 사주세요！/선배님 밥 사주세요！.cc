#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	unordered_map<string, pair<int,int>> senior;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		string name;
		int w, d, p;
		cin >> name >> w >> d >> p;
		senior[name] = make_pair(w * 7 + d, p);
	}

	for (int i = 0; i < n; i++) {
		string name;
		int money;
		cin >> name >> money;
		if (money >= senior[name].second)
			v.emplace_back(senior[name].first);
	}

	sort(v.begin(), v.end());

	int answer = (v.size() == 0) ? 0 : 1;
	int result = (v.size() == 0) ? 0 : 1;

	for (int i = 0; i < int(v.size()) - 1; i++) {
		if (v[i + 1] - v[i] == 0)
			continue;
		if (v[i + 1] - v[i] == 1)
			result++;
		else {
			answer = max(answer, result);
			result = 1;
		}
	}

	answer = max(answer, result);

	cout << answer;
	return 0;
}