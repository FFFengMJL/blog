#include <iostream>
using namespace std;

int main()
{
    float a = 1.0 / 0.0;
    float b = a;
    cout << a << '\t' << b << endl;
    printf("%d\n", a == b);
    return 0;
}