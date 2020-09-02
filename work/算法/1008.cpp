#include <iostream>

using namespace std;

int main()
{
  long input;
  bool isPlus = true;
  long res = 0;
  cin >> input;
  // cout << input << endl;
  if (input == 0)
  {
    cout << "input = 0" << 0 << endl;
    return 0;
  }
  else if (input < 0)
  {
    isPlus = false;
    input = -input;
  }

  while (input != 0)
  {
    long tmp = input % 10;
    res = res * 10 + tmp;
    input /= 10;
    // cout << res;
  }

  if (isPlus)
    cout << res << endl;
  else
    cout << -res << endl;
}