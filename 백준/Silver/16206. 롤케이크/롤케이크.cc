#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
	int n, m, answer = 0;
	priority_queue<int> pq;	
	vector<int> multi;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int cake;
		cin >> cake;
		if (cake == 10)
			answer++;
		else if (cake % 10 == 0)
			multi.emplace_back(cake);
		else if (cake > 10)
			pq.push(cake);
	}

	sort(multi.begin(), multi.end());

	for (int i = 0; i < multi.size(); i++) {
		while (m > 0 && multi[i] != 10) {
			m--;
			multi[i] -= 10;
			answer++;
		}
		if(multi[i]==10)
			answer++;
		if (m == 0)
			break;
	}

	if (m == 0) {
		cout << answer;
		return 0;
	}


	while (m > 0 && !pq.empty()) {
		if (pq.top() >= 10) {
			int tmp = pq.top() - 10;
			pq.pop();
			if (tmp > 10)
				pq.push(tmp);
			answer++;
			m--;
		}
		else {
			break;
		}
	}

	cout << answer;

	return 0;
}