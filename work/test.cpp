#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main()
{
  string test = "test\0";
  cout << test.size() << '\t' << test.length() << endl;
}