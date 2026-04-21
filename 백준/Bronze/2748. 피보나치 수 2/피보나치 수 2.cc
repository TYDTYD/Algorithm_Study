#include <iostream>
using namespace std;

long long f[1000];
long long fib(int n) {
    for (int j = 3; j < n + 2; j++) {
        f[j] = f[j - 1] + f[j - 2];
    }
    return f[n];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n + 2; i++) {
        f[i] = 0;
    }
    f[1] = 1;
    f[2] = 1;
    cout << fib(n);
}