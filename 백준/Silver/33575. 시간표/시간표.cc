#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long answer = 0;
	int n, m, a, b;
	vector<int> schedule;
	unordered_set<int> like;
	unordered_set<int> hate;
	cin >> n >> m >> a >> b;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		schedule.push_back(t);
	}
	for (int i = 0; i < a; i++) {
		int s;
		cin >> s;
		like.insert(s);
	}
	for (int i = 0; i < b; i++) {
		int s;
		cin >> s;
		hate.insert(s);
	}
	int likeSeq = 0;
	int hateSeq = 0;
	for (const auto& s : schedule) {
		if (like.find(s) != like.end()) {
			if (hateSeq >= 3)
				answer -= hateSeq;
			hateSeq = 0;
			likeSeq++;
		}
		else if (hate.find(s) != hate.end()) {
			if (likeSeq >= 3)
				answer += likeSeq;
			likeSeq = 0;
			hateSeq++;
		}
		else {
			if (likeSeq >= 3)
				answer += likeSeq;
			if (hateSeq >= 3)
				answer -= hateSeq;
			likeSeq = 0;
			hateSeq = 0;
		}
	}
	if (likeSeq >= 3)
		answer += likeSeq;
	if (hateSeq >= 3)
		answer -= hateSeq;
	cout << answer;
	return 0;
}