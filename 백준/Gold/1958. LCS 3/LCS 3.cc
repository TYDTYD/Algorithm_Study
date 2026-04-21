using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int L[101][101][101] = {0, };

bool Compare(string a, string b) {
	return a.length() > b.length();
}

int LCS(int m, int n, int l, string a, string b, string c) {
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			for (int k = 1; k < l + 1; k++) {
				if ((a[i - 1] == b[j - 1]) && (b[j-1] == c[k - 1]))
					L[i][j][k] = L[i - 1][j - 1][k - 1] + 1;
				else
					L[i][j][k] = max(max(L[i - 1][j][k], L[i][j - 1][k]), L[i][j][k - 1]);
			}
		}
	}

	return L[m][n][l];
}

int main() {
	string a, b, c;
	vector <string> index;

	cin >> a >> b >> c;

	index.push_back(a);
	index.push_back(b);
	index.push_back(c);

	sort(index.begin(), index.end(), Compare);

	cout << LCS(index[0].length(), index[1].length(), index[2].length(), index[0], index[1], index[2]);

	
}