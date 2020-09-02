#include <iostream>

using namespace std;

int main()
{
  int time;
  cin >> time;
  while (time--)
  {
    int num, no;
    cin >> num >> no;
    char ball;
    int r = 0, y = 0, b = 0;
    for (int i = 0; i < num; i++)
    {
      cin >> ball;
      switch (ball)
      {
      case 'r':
        r++;
        break;
      case 'y':
        y++;
        break;
      case 'b':
        b++;
        break;
      default:
        break;
      }
    }

    if (no <= r)
      cout << 'r' << endl;
    else if (no <= (r + y))
      cout << 'y' << endl;
    else
      cout << 'b' << endl;
  }
}