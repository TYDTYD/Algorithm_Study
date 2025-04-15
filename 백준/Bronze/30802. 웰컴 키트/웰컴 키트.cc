#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> t_size;
	int sum = 0;
	for (int i = 0; i < 6; i++) {
		int size;
		cin >> size;
		t_size.push_back(size);
		sum += size;
	}
	int T, P;
	cin >> T >> P;
	int t_num = 0;
	for (const auto& e : t_size) {
		if (e % T != 0)
			t_num++;
		t_num += e / T;
	}
	int p_num = sum / P;
	int p_remain = sum % P;
	cout << t_num << '\n' << p_num << ' ' << p_remain;
	return 0;
}