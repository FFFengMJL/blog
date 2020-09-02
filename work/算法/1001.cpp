#include <iostream>

using namespace std;

int main()
{
  int time;
  cin >> time;
  while (time--)
  {
    int a, b, low, high;
    cin >> a >> b >> low >> high;
    bool founded = false;
    for (int i = high; i >= low; i--)
    {
      if (a % i == 0 && b % i == 0)
      {
        cout << i << endl;
        founded = true;
        break;
      }
    }
    if (!founded)
      cout << "No answer" << endl;
  }
}