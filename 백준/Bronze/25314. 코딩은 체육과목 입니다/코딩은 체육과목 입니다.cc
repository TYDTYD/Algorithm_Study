#include <iostream>
using namespace std;

int main()
{
    int n,index,answer;
    cin >> n;
    index = n / 4;

    for (int i = 0; i < index; i++) {
        cout << "long ";
    }
    cout << "int";
}