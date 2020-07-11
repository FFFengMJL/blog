#include <iostream>

using namespace std;

int fourDig(int num, int tar)
{
  int res = 0;
  while (num != 0)
  {
    res += num % tar;
    num /= tar;
  }
  return res;
}

int main()
{
  for (int i = 1000; i < 10000; i++)
  {
    int ten = fourDig(i, 10);
    int twe = fourDig(i, 12);
    int hex = fourDig(i, 16);
    if (ten == twe && twe == hex && ten == hex)
      cout << i << endl;
  }
  return 0;
}
