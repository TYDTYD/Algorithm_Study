#include <iostream>

using namespace std;

int main() {
	int n = -1, num = 0;
	int arr[100001];
	while (true) {
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cout << "Case " << ++num << ": Sorting... done!" << '\n';
	}
	return 0;
}