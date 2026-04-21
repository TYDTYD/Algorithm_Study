#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a, b, v;
    int answer;
    cin >> a >> b >> v;
    answer = ceil((v - a) / (a - b)) + 1;
    cout << answer;
}