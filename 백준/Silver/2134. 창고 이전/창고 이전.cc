#include <iostream>
#include <queue>

using namespace std;

int main() {
	long long n, m, k, time = 0, old_floor = 1, new_floor = 1, box = 0;
	queue<int> old_Storage, new_Storage;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		old_Storage.push(num);
	}
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		new_Storage.push(num);
	}


	while (!new_Storage.empty() && !old_Storage.empty()) {
		if (new_Storage.front() == 0) {
			new_Storage.pop();
			new_floor++;
			continue;
		}
		if (old_Storage.front() == 0) {
			old_Storage.pop();
			old_floor++;
			continue;
		}
		if (old_Storage.front() > new_Storage.front()) {
			box += new_Storage.front();
			time += (old_floor + new_floor) * new_Storage.front();
			old_Storage.front() -= new_Storage.front();
			new_Storage.pop();
			
			new_floor++;
		}
		else if (old_Storage.front() < new_Storage.front()) {
			box += old_Storage.front();
			time += (old_floor + new_floor) * old_Storage.front();
			new_Storage.front() -= old_Storage.front();
			old_Storage.pop();
			old_floor++;
		}
		else {
			box += old_Storage.front();
			time += (old_floor + new_floor) * new_Storage.front();
			old_Storage.pop();
			new_Storage.pop();
			old_floor++;
			new_floor++;
		}
	}

	cout << box << ' ' << time;

	return 0;
}