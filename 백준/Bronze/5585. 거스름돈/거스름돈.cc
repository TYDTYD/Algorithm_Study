#include <iostream>
using namespace std;

int main()
{
    int money;
    int index = 0;
    int result = 0;
    cin >> money;
    int fund = 1000 - money;
    int coin[6] = { 500,100,50,10,5,1 };
    while (fund > 0) {
        if (fund >= coin[index]) {
            result += (fund / coin[index]);
            fund = fund - (fund / coin[index]) * coin[index];
            index++;
        }
        else {
            index++;
        }
    }
    cout << result;
}