#include <iostream>
using namespace std;

int gcd(int a,int b){
    if(a % b == 0) return b;
    return gcd(b,a % b);
}

int main() {
    int a, d, n;
    cin >> a >> d >> n;
    cout << gcd(a + n * d, a) << endl;
}