#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	deque<int> gift;
	vector<int> gift_box;
	map<int, int> left_box;
	int my_gift_size = 0;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		gift.emplace_back(s);
	}

	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		left_box[s]++;
	}

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		gift_box.emplace_back(c);
		left_box[c]--;
	}

	for (map<int, int>::iterator it = left_box.begin(); it != left_box.end(); it++) {
		if ((*it).second != 0)
			my_gift_size = (*it).first;
	}

	sort(gift_box.begin(), gift_box.end());
	sort(gift.begin(), gift.end());
	for (const auto& box : gift_box) {
		if (box <= my_gift_size)
			gift.pop_front();
		else {
			auto it = upper_bound(gift.begin(), gift.end(), my_gift_size);
			if (it == gift.end())
				gift.pop_front();
			else if (*it > box)
				gift.pop_front();
			else
				gift.erase(it);
		}
	}

	while (gift.back() > my_gift_size) {
		gift.pop_back();
	}

	cout << gift.back();

	return 0;
}