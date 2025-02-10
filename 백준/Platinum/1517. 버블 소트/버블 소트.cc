#include <iostream>
#include <vector>
using namespace std;

long long answer = 0;

void merge(vector<long long>& arr, vector<long long>& res, int left, int right, int end) {
	int num = left, start = left, mid = right - 1;
	int index = 0;
	while (left <= mid && right <= end) {
		if (arr[left] > arr[right]) {
			res[num++] = arr[right];
			index = max(index, right - mid);
			right++;
		}
		else {
			res[num++] = arr[left++];
			answer += index;
			index = (right - 1) - mid;
		}
	}
	while (num <= end) {
		if (left > mid)
			res[num++] = arr[right++];
		else {
			res[num++] = arr[left++];
			answer += index;
		}
	}
	for (int i = start; i <= end; i++)
		arr[i] = res[i];
	return;
}

void merge_sort(vector<long long>& arr, int start, int end, vector<long long>& new_arr) {
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
	vector<long long> arr;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int element;
		cin >> element;
		arr.emplace_back(element);
	}

	vector<long long> res(n, 0);
	merge_sort(arr, 0, n - 1, res);

	cout << answer;

	return 0;
}