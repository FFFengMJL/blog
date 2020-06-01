#include <iostream>

using namespace std;

int triTiling(int n)
{
  if (n == 0 || n == 1)
    return 0;
  int f[n / 2 + 1], g[n / 2 + 1];
  f[0] = 1;
  g[0] = 0;
  for (int i = 1; i < n / 2 + 1; i++)
  {
    f[i] = f[i - 1] * 3 + g[i - 1];
    g[i] = f[i - 1] * 2 + g[i - 1];
  }
  return f[n / 2];
}

const int MAX_N = 16;
int f[MAX_N];
int g[MAX_N];
void tritiling()
{
  f[0] = 1;
  g[0] = 0;
  for (int i = 1; i < MAX_N; i++)
  {
    f[i] = f[i - 1] * 3 + g[i - 1];
    g[i] = f[i - 1] * 2 + g[i - 1];
  }
}

int main()
{
  while (1)
  {
    int n;
    cin >> n;
    if (n == -1)
      break;
    cout << triTiling(n) << endl;
  }
}