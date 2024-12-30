#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k, answer = 0;
	cin >> n >> m >> k;
	vector<int> v(2 * n), tmp(2 * n, 0);
	vector<vector<int>> quest(m), p;
	for (int i = 0; i < 2 * n; i++) {
		if (i >= n)
			tmp[i] = 1;
		v[i] = i + 1;
	}

	do {
		vector<int> key;
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i])
				key.emplace_back(v[i]);
		}
		p.emplace_back(key);
	} while (next_permutation(tmp.begin(), tmp.end()));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			int skill;
			cin >> skill;
			quest[i].emplace_back(skill);
		}
	}

	sort(p.begin(), p.end());
	sort(quest.begin(), quest.end());

	// 키 배치에 필요한 조합
	for (int i = 0; i < p.size(); i++) {
		int result = 0;
		// 조합마다 quest를 for문으로 돌리기
		for (int j = 0; j < quest.size(); j++) {
			int num = 0;
			// quest에 필요한 키 for문으로 돌리기
			for (const auto& q : quest[j]) {
				bool pass = false;
				// 필요한 키와 조합의 키를 비교하면서
				for (const auto& key : p[i]) {
					// 같다면 바로 다음 필요한 키로 넘어가기
					if (q == key) {
						pass = true;
						break;
					}
				}
				// pass가 false라면 필요한 키가 없는 것이므로 바로 다음 quest로 넘어가기
				if (!pass)
					continue;
				// pass가 true라면 필요한 키가 있다는 것
				num++;
			}
			// num이 k라면 필요한 키가 k개, 즉 모든 키가 있다는 뜻
			if (num == k)
				result++;
		}
		answer = max(answer, result);
	}

	cout << answer;

	return 0;
}