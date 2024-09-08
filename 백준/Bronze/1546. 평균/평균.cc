#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, score[1001], m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> score[i];
    m = *max_element(score, score + n);
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += score[i] / (double)m * 100;
    double average = sum / n;
    cout << average;
}