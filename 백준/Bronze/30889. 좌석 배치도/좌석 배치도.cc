#include<iostream>
#include<string>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	string seat[201], movie[10];
	cin >> n;

	for (int i = 0; i < 10; i++)
		movie[i] = "....................";

	for (int i = 0; i < n; i++) {
		cin >> seat[i];
		if (seat[i].length() == 2)
			movie[seat[i][0] - 'A'][seat[i][1] - '1'] = 'o';
		else {
			string num = "";
			num += seat[i][1];
			num += seat[i][2];
			movie[seat[i][0] - 'A'][stoi(num)-1] = 'o';
		}
	}

	for (int i = 0; i < 10; i++)
		cout << movie[i] << '\n';

	return 0;
}