#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n, 0);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << *min_element(a.begin(), a.end()) << " " << *max_element(a.begin(), a.end());

}