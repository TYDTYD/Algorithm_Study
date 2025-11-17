#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> students;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		students.push_back(x);
	}

	sort(students.begin(), students.end());

	int team_count = 0;
	int student = 0;
	int index = 0;

	for (int i = 0; i < n; i++) {
		student++;		
		if(students[index] <= student) {
			team_count++;
			student = 0;					
			index = i + 1;
		}		
	}

	if(student != 0)
		team_count++;

	cout << team_count;
	return 0;
}