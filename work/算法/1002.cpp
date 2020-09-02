#include <iostream>

using namespace std;

bool func(int a, int b, bool player)
{
  // cout << a << b << endl;
  int big = a > b ? a : b;
  int small = a > b ? b : a;
  if (big % small == 0)
    return player;
  int tmp = big / small;
  if (tmp == 1)
  {
    player = !player;
    return func(big % small, small, player);
  }
  else
    return player;
}

int main()
{
  int a, b;
  cin >> a >> b;
  while (a != 0 && b != 0)
  {

    if (!func(a, b, false))
    {
      cout << "Singa wins\n";
    }
    else
    {
      cout << "Suny wins\n";
    }
    cin >> a >> b;
  }
}