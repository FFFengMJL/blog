#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int main()
{
    stack <int> a;
    int num = 0, n = 0, data, sum = 0;
    ifstream file;
    file.open("test.txt", ios::in);
    file >> num;
    if (n >= 10) {
        cout << "data error" << endl;
        return 1;
    }
    for (int i = 0; i < num; i++) {
        sum = 0;
        for (int t = 0; t < num; t++) {
            file >> data;
            cout << data << '\t';
            sum += data * data * data;
        }
        cout << "\t\t" << sum << endl;
    }
    file.close();
    return 0;
}