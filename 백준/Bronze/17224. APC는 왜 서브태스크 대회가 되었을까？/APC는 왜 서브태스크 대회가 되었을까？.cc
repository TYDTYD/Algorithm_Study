#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Status{
	int sub1;
	int sub2;
	bool solved;
	Status(int a, int b) : sub1(a), sub2(b), solved(false) {}
};

bool SortSubTask(const Status& a, const Status& b) {
	if (a.sub2 == b.sub2) {
		return a.sub1 < b.sub1;
	}
	return a.sub2 > b.sub2;
}

bool Sort(const Status& a, const Status& b) {
	if (a.sub1 == b.sub1) {
		return a.sub2 < b.sub2;
	}
	return a.sub1 < b.sub1;
}

int main() {
	int n, l, k;
	cin >> n >> l >> k;

	vector<Status> problems;

	for (int i = 0; i < n; i++) {
		int sub1, sub2;
		cin >> sub1 >> sub2;
		problems.push_back(Status(sub1, sub2));
	}

	sort(problems.begin(), problems.end(), SortSubTask);

	int maxScore = 0;	
	int count = 0;

	for (int i = 0; i < n; i++) {
		if(problems[i].sub2 <= l) {
			maxScore += 140;
			problems[i].solved = true;
			count++;
		}
		if(count == k)
			break;
	}

	int remain = k - count;
	count = 0;

	if (remain > 0) {
		sort(problems.begin(), problems.end(), Sort);
		for (int i = 0; i < n; i++) {
			if (!problems[i].solved) {
				count++;
				if (problems[i].sub2 <= l)
					maxScore += 140;
				else if (problems[i].sub1 <= l)
					maxScore += 100;
				else
					count--;
			}
			if (count == remain)
				break;
		}
	}	

	cout << maxScore;

	return 0;
}