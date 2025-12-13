#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<deque<int>> array(n);

	for(int i =0; i < n; i++) {		
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			array[i].push_back(num);
		}
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		int query;
		cin >> query;
		if (query == 1) {
			int idx;
			cin >> idx;
			array[idx - 1].push_front(array[idx - 1].back());
			array[idx - 1].pop_back();
		}
		else if (query == 2) {
			vector<deque<int>> temp = array;
			for (int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					array[i][j] = temp[n - j - 1][i];
				}
			}
		}
	}

	for(int i =0; i < n; i++) {		
		for (int j = 0; j < n; j++)
			cout << array[i][j] << ' ';		
		cout << '\n';
	}

	return 0;
}