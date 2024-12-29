#include <iostream>
#include <string>
using namespace std;

int main() {
	string sentence, alpha[8] = { "c=","c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	cin >> sentence;
	int answer = 0;

	for(int i=0; i<sentence.length(); i++){
		bool pass = false;
		for (const auto& a : alpha) {
			if (sentence.length() - i >= a.size()) {
				string cmp = "";
				for (int j = 0; j < a.length(); j++)
					cmp += sentence[i + j];
				if (cmp == a) {
					answer++;
					i += a.size() - 1;
					pass = true;
					break;
				}
			}
		}
		if (pass)
			continue;
		answer++;
	}

	cout << answer;
	return 0;
}