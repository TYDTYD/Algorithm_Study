#include <iostream>
#include <string>

using namespace std;

class Automata{
public:
	string expr;
	int start = 0;

	Automata(string _expr) {
		expr = _expr;
	}

	bool state0(int index) {
		if (index == expr.length())
			return false;
		else if (expr[index] == '0')
			return state4(index + 1);
		else
			return state1(index + 1);
	}

	bool state1(int index) {
		if (index == expr.length())
			return false;
		else if (expr[index] == '0')
			return state2(index + 1);
		else
			return false;
	}

	bool state2(int index) {
		if (index == expr.length())
			return false;
		else if (expr[index] == '0')
			return state3(index + 1);
		else
			return false;
	}

	bool state3(int index) {
		if (index == expr.length())
			return false;
		else if (expr[index] == '0')
			return state3(index + 1);
		else
			return state5(index + 1);
	}

	bool state4(int index) {
		if (index == expr.length())
			return false;
		else if (expr[index] == '1')
			return state6(index + 1);
		else
			return false;
	}

	bool state5(int index) {
		if (index == expr.length())
			return true;
		else if (expr[index] == '1')
			return state7(index + 1);
		else
			return state0(index);
	}

	bool state6(int index) {
		if (index == expr.length())
			return true;
		else if (expr[index] == '0')
			return state4(index + 1);
		else
			return state1(index + 1);
	}

	bool state7(int index) {
		if (index == expr.length())
			return true;
		else if (expr[index] == '0')
			return (state2(index + 1) || state4(index + 1));
		else
			return state7(index + 1);
	}
	~Automata() {};
};

int main() {
	int T;
	string exp;
	string output;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> exp;
		Automata automata(exp);

		if (automata.state0(automata.start))
			output += "YES\n";
		else
			output += "NO\n";
	}

	cout << output << endl;
	
	return 0;
}