#include <iostream>

using namespace std;

int f[1001][5] = {0};

void pre()
{
  f[0][0] = 1;
  for (int i = 1; i < 1000; i++)
  {
    f[i][0] = f[i - 1][0] + f[i - 1][1] + f[i - 1][2] + f[i - 1][3];
    if (i > 1)
    {
      f[i][0] += f[i - 2][0];
    }
    f[i][1] = f[i - 1][0] + f[i - 1][2];
    f[i][2] = f[i - 1][0] + f[i - 1][1];
    f[i][3] = f[i - 1][0] + f[i - 1][4];
    f[i][4] = f[i - 1][3];
  }
}

int main()
{
  int time;
  cin >> time;
  pre();
  for (int i = 1; i <= time; i++)
  {
    int length;
    cin >> length;
    cout << i << ' ' << f[length][0] << endl;
  }
}