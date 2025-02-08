#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, vector<int>& res, int left, int right, int end) {
	int num = left, start = left, mid = right - 1;
	bool flag = false;
	while (left <= mid && right <= end) {
		if (arr[left] > arr[right])
			res[num++] = arr[right++];
		else
			res[num++] = arr[left++];
	}
	while (num <= end) {
		if (left > mid)
			res[num++] = arr[right++];
		else
			res[num++] = arr[left++];
	}
	for (int i = start; i <= end; i++)
		arr[i] = res[i];
	return;
}

void merge_sort(vector<int>& arr, int start, int end, vector<int>& new_arr) {
	if (start != end) {
		int mid = (start + end) / 2;
		merge_sort(arr, start, mid, new_arr);
		merge_sort(arr, mid + 1, end, new_arr);
		merge(arr, new_arr, start, mid + 1, end);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int element;
		cin >> element;
		arr.emplace_back(element);
	}

	vector<int> res(n, 0);
	merge_sort(arr, 0, n - 1, res);

	for (const auto& e : arr)
		cout << e << '\n';

	return 0;
}