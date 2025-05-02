#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
	int n;
	cin >> n;
	int answer = 0;
	vector<string> v;
	unordered_map<string, int> mapping;
	mapping["botswana"] = 0;
	mapping["ethiopia"] = 50;
	mapping["kenya"] = 50;
	mapping["namibia"] = 140;
	mapping["south-africa"] = 0;
	mapping["zambia"] = 50;
	mapping["tanzania"] = 50;
	mapping["zimbabwe"] = 30;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		answer += mapping[s];
		if (s == "south-africa") {
			mapping["namibia"] = 40;
		}
		if (s == "zambia") {
			mapping["zimbabwe"] = 0;
		}
		else {
			mapping["zimbabwe"] = 30;
		}
		if (s == "zimbabwe") {
			mapping["zambia"] = 20;
		}
		else {
			mapping["zambia"] = 50;
		}
	}
	cout << answer;
	return 0;
}