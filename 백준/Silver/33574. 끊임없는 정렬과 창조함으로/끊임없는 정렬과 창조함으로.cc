#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

bool compare(long long x, long long y) {
	return x > y;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int Q;
	cin >> Q;
	list<long long> l;
	while (Q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int x;
			cin >> x;
			if (x == 1)
				l.sort();
			else
				l.sort(compare);
		}
		else {
			int x, t;
			cin >> x >> t;
			list<long long>::iterator it = l.begin();
			if (x == l.size())
				it = l.end();
			else
				advance(it, x);
			l.insert(it, t);
		}	
	}
	cout << l.size() << '\n';
	for (const auto& e : l)
		cout << e << ' ';
	return 0;
}