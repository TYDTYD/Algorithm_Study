#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, k;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k;
		multiset<long long> tree;
		for (int j = 0; j < k; j++) {
			long long n;
			char oper;
			cin >> oper >> n;
			if (oper == 'I')
				tree.insert(n);
			else if(!tree.empty()){
				if (n == -1)
					tree.erase(tree.begin());
				else
					tree.erase(prev(tree.end()));
			}
		}
		if (tree.empty())
			cout << "EMPTY" << '\n';
		else
			cout << *prev(tree.end()) << ' ' << *tree.begin() << '\n';
	}

	return 0;
}