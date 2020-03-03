#include <iostream>
using namespace std;

int cale(int data)
{
    int sum = 0;
    int bit;
    while (data != 0) {
        bit = data % 10; // 取余
        data /= 10; // 自递除
        sum += bit * bit * bit;
    }
    return sum;
}

int main()
{
    int data;
    while (1) {
        cin >> data;
        if (data == 0) break;
        if (data < 0) cout << "Not a true data, please input again" << endl;
        else cout << cale(data) << endl;
    }
    return 0;
}