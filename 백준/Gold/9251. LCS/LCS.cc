using namespace std;
#include <iostream>
#include <vector>
#include <string>

string a;
string b;
vector <vector<int>> L(1001);

int LCS(int m, int n,string a, string b) {
	for (int i = 0; i < m + 1; i++)
		for (int j = 0; j < n + 1; j++)
			L[i].push_back(0);

	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (a[i - 1] == b[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	return L[m][n];
}

int main() {
	cin >> a >> b;

	if (a.length() < b.length())
		cout << LCS(a.length(), b.length(), a, b);
	else
		cout << LCS(b.length(), a.length(), b, a);
}