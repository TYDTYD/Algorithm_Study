#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int find_parent(int c, vector<pair<string,int>>& v) {
	if (v[c].second == c)
		return c;
	return v[c].second = find_parent(v[c].second, v);
}

void merge(int a, int b, vector<pair<string,int>>& v, unordered_map<string, int>& net_info) {
	int a_parent = find_parent(a, v);
	int b_parent = find_parent(b, v);

	if (a_parent != b_parent) {
		// a 인덱스의 해당하는 친구의 부모를 b의 부모로 설정
		v[a_parent].second = b_parent;
		// 부모로 설정한 친구의 네트워크 갱신
		net_info[v[b_parent].first] += net_info[v[a_parent].first];
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int F;
		cin >> F;
		unordered_set<string> f_name;
		unordered_map<string, int> f_index, f_count;
		vector<pair<string,int>> network;
		int idx = 0;
		for (int i = 0; i < F; i++) {
			string a, b;
			cin >> a >> b;
			if (f_name.find(a) == f_name.end()) {
				f_name.insert(a);
				f_index[a] = idx;
				f_count[a] = 1;
				network.emplace_back(make_pair(a, idx++));
			}
			if (f_name.find(b) == f_name.end()) {
				f_name.insert(b);
				f_index[b] = idx;
				f_count[b] = 1;
				network.emplace_back(make_pair(b, idx++));
			}
			merge(f_index[a], f_index[b], network, f_count);
			// a의 부모를 찾음
			int parent = find_parent(f_index[a], network);
			// 대표 번호의 네트워크 개수를 출력 
			cout << f_count[network[parent].first] << '\n';
		}
	}

	return 0;
}