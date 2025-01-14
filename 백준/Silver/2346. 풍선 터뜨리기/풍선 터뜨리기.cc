#include <iostream>
#include <deque>
using namespace std;

int main() {
	int n;
	cin >> n;
	deque<pair<int,int>> q;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		q.push_back(make_pair(num, i + 1));
	}

	int seq = 0;

	while (!q.empty()) {
		if (seq==0) {
			if (q.front().first > 0)
				seq = q.front().first - 1;
			else
				seq = q.front().first;
			cout << q.front().second << ' ';
			q.pop_front();
		}
		else if (seq>0){
			seq--;
			q.push_back(q.front());
			q.pop_front();
		}
		else {
			seq++;
			q.push_front(q.back());
			q.pop_back();
		}
	}

	return 0;
}