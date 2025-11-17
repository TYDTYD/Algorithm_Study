#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	priority_queue<double, vector<double>, greater<double>> pq;
	for (int i = 0; i < n; i++) {
		double score;
		cin >> score;
		pq.push(score);
	}

	for(int i =0; i<7; i++) {
		if (!pq.empty()) {
			cout << fixed;
			cout.precision(3);
			cout << pq.top() << '\n';
			pq.pop();
		}
	}

	return 0;
}