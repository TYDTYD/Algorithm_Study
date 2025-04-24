#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int arr[3] = { a,b,c };
	sort(arr, arr + 3);
	int mx = arr[2];
	int sum = arr[0] + arr[1];
	if (mx >= sum)
		mx = sum - 1;
	cout << mx + sum;
	return 0;
}