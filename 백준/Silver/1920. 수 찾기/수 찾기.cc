#include <iostream>
#include <algorithm>

using namespace std;

int A[100001];

bool search(int start, int end, int seek) {
	int mid = (start + end) / 2;
	if (start > end)
		return false;
	else if (seek == A[mid])
		return true;
	else if (seek < A[mid])
		return search(start, mid - 1, seek);
	else if (seek > A[mid])
		return search(mid + 1, end, seek);
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A+N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int b;
		cin >> b;
		cout << search(0, N-1, b) << "\n";
	}

	return 0;
}