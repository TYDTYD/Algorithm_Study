#include <iostream>
#include <string>
using namespace std;

bool Solve(string name, string old) {
	int nameLen = name.length();
	int len = old.length();

	if (nameLen > len) 
		return false;

	for (int i = 0; i < len; i++) {
		bool found = false;
		if (old[i] == name[0]) {
			int offset = 1;
			int count = 0;
			while (nameLen > count) {
				count = 0;
				for (int j = 0; j < nameLen; j++) {
					if (i + offset >= len)
						break;
					if (old[i + j * offset] != name[j])
						break;
					count++;
				}
				if (i + offset * (nameLen - 1) >= len)
					break;
				offset++;
			}
			if (count == nameLen)
				return true;
		}
	}
	return false;
}


int main() {
	int n;
	cin >> n;
	
	string name;
	cin >> name;

	int answer = 0;

	for(int i = 0; i < n; i++) {
		string old;
		cin >> old;
		if(Solve(name, old))
			answer++;
	}
	
	cout << answer;
	return 0;
}