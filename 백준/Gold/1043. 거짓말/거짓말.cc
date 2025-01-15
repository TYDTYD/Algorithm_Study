#include <iostream>
#include <vector>
using namespace std;

int findParent(int u, vector<int>& parent) {
	if (u == parent[u])
		return u;
	return parent[u] = findParent(parent[u], parent);
}

void merge(int u, int v, vector<int>& parent, bool truth[]) {
	u = findParent(u, parent);
	v = findParent(v, parent);
	if (u == v)
		return;
	if (truth[v])
		parent[u] = v;
	else
		parent[v] = u;
}

int main() {
	int n, m, num, answer = 0;
	cin >> n >> m;
	vector<int> graph;
	for (int i = 0; i <= n; i++)
		graph.emplace_back(i);
	bool truth[51] = {};

	cin >> num;
	for (int i = 0; i < num; i++) {
		int p;
		cin >> p;
		truth[p] = true;
	}

	vector<vector<int>> result;

	for (int i = 0; i < m; i++) {
		int party, in = 0;
		cin >> party;
		vector<int> people, party_people;
		for (int j = 0; j < party; j++) {
			int person;
			cin >> person;
			party_people.emplace_back(person);
			
			if (truth[person])
				in = person;
			else
				people.emplace_back(person);
		}
		result.emplace_back(party_people);
		if (in) {
			for (int j = 0; j < people.size(); j++) {
				merge(people[j], in, graph,truth);
				truth[people[j]] = true;
			}
		}
		for (int j = 1; j < people.size(); j++)
			merge(people[j], people[0], graph,truth);
	}

	for (int i = 0; i < m; i++) {
		bool speak = true;
		for (int j = 0; j < result[i].size(); j++) {
			if (truth[findParent(result[i][j],graph)]) {
				speak = false;
				break;
			}
		}
		if (speak)
			answer++;
	}

	cout << answer;

	return 0;
}