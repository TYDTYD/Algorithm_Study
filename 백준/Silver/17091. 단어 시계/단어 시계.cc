#include <iostream>
#include <string>
using namespace std;
int main() {
	int h, m;
	cin >> h;
	cin >> m;

	string hour;
	string minute;
	string mid;

	if (m > 30) {
		mid = " to ";
		m -= 60;
		m *= -1;
		h += 1;
		h %= 12;
	}
	else {
		mid = " past ";
	}

	switch (h)
	{
	case 0:
		hour = "twelve";
		break;
	case 1:
		hour = "one";
		break;
	case 2:
		hour = "two";
		break;
	case 3:
		hour = "three";
		break;
	case 4:
		hour = "four";
		break;
	case 5:
		hour = "five";
		break;
	case 6:
		hour = "six";
		break;
	case 7:
		hour = "seven";
		break;
	case 8:
		hour = "eight";
		break;
	case 9:
		hour = "nine";
		break;
	case 10:
		hour = "ten";
		break;
	case 11:
		hour = "eleven";
		break;
	case 12:
		hour = "twelve";
		break;
	}

	switch (m)
	{
	case 1:
		minute = "one minute";
		break;
	case 2:
		minute = "two minutes";
		break;
	case 3:
		minute = "three minutes";
		break;
	case 4:
		minute = "four minutes";
		break;
	case 5:
		minute = "five minutes";
		break;
	case 6:
		minute = "six minutes";
		break;
	case 7:
		minute = "seven minutes";
		break;
	case 8:
		minute = "eight minutes";
		break;
	case 9:
		minute = "nine minutes";
		break;
	case 10:
		minute = "ten minutes";
		break;
	case 11:
		minute = "eleven minutes";
		break;
	case 12:
		minute = "twelve minutes";
		break;
	case 13:
		minute = "thirteen minutes";
		break;
	case 14:
		minute = "fourteen minutes";
		break;
	case 15:
		minute = "quarter";
		break;
	case 16:
		minute = "sixteen minutes";
		break;
	case 17:
		minute = "seventeen minutes";
		break;
	case 18:
		minute = "eighteen minutes";
		break;
	case 19:
		minute = "nineteen minutes";
		break;
	case 20:
		minute = "twenty minutes";
		break;
	case 21:
		minute = "twenty one minutes";
		break;
	case 22:
		minute = "twenty two minutes";
		break;
	case 23:
		minute = "twenty three minutes";
		break;
	case 24:
		minute = "twenty four minutes";
		break;
	case 25:
		minute = "twenty five minutes";
		break;
	case 26:
		minute = "twenty six minutes";
		break;
	case 27:
		minute = "twenty seven minutes";
		break;
	case 28:
		minute = "twenty eight minutes";
		break;
	case 29:
		minute = "twenty nine minutes";
		break;
	case 30:
		minute = "half";
		break;
	}

	if (m == 0) {
		cout << hour + " o' clock";
	}
	else {
		cout << minute + mid + hour;
	}

	return 0;
}