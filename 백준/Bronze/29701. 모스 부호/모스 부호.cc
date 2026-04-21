#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	unordered_map<string, char> keyValue;

	keyValue[".-"] = 'A';
	keyValue["-..."] = 'B';
	keyValue["-.-."] = 'C';
	keyValue["-.."] = 'D';
	keyValue["."] = 'E';
	keyValue["..-."] = 'F';
	keyValue["--."] = 'G';
	keyValue["...."] = 'H';
	keyValue[".."] = 'I';
	keyValue[".---"] = 'J';
	keyValue["-.-"] = 'K';
	keyValue[".-.."] = 'L';
	keyValue["--"] = 'M';
	keyValue["-."] = 'N';
	keyValue["---"] = 'O';
	keyValue[".--."] = 'P';
	keyValue["--.-"] = 'Q';
	keyValue[".-."] = 'R';
	keyValue["..."] = 'S';
	keyValue["-"] = 'T';
	keyValue["..-"] = 'U';
	keyValue["...-"] = 'V';
	keyValue[".--"] = 'W';
	keyValue["-..-"] = 'X';
	keyValue["-.--"] = 'Y';
	keyValue["--.."] = 'Z';
	keyValue[".----"] = '1';
	keyValue["..---"] = '2';
	keyValue["...--"] = '3';
	keyValue["....-"] = '4';
	keyValue["....."] = '5';
	keyValue["-...."] = '6';
	keyValue["--..."] = '7';
	keyValue["---.."] = '8';
	keyValue["----."] = '9';
	keyValue["-----"] = '0';
	keyValue["--..--"] = ',';
	keyValue[".-.-.-"] = '.';
	keyValue["..--.."] = '?';
	keyValue["---..."] = ':';
	keyValue["-....-"] = '-';
	keyValue[".--.-."] = '@';

	string answer = "";
	for (int i = 0; i < n; i++) {
		string key;
		cin >> key;
		answer += keyValue[key];
	}
	cout << answer;
}