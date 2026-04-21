#include <iostream>
using namespace std;

int main()
{
    long long n;
    long long index = 1;
    cin >> n;
    while (n>=0) {
        n-=index;
        if (n <= index) {
            break;
        }
        index++;
    }
    cout << index;
    return 0;
}