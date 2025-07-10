#include <iostream>
using namespace std;

int main() {
	double pab, pbc, pcd;
	cin >> pab >> pbc >> pcd;

	cout.fixed;
	cout.precision(10);
	cout << pab * pcd / pbc;

	return 0;
}