#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool res[33000];

void insert(string s, int i, int num)
{
  // cout << i << endl;
  if (i == s.length())
  {
    // cout << num << endl;
    res[num] = true;
    return;
  }
  if (s[i] == '0')
  {
    insert(s, i + 1, num * 2 + 0);
  }
  else if (s[i] == '1')
    insert(s, i + 1, num * 2 + 1);
  else if (s[i] == '?')
  {
    insert(s, i + 1, num * 2 + 0);
    insert(s, i + 1, num * 2 + 1);
  }
}

int main()
{
  int m, n;
  cin >> m >> n;
  while (m != 0 || n != 0)
  {
    for (int i = 0; i < 33000; i++)
    {
      res[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
      string s;
      cin >> s;
      // cout << s << endl;
      insert(s, 0, 0);
    }
    int num = 0;
    for (int i = 0; i < 33000; i++)
    {
      if (res[i])
      {
        num++;
        // cout << i << endl;
      }
    }
    // if (n == 0)
    //   cout << 0 << endl;

    cout << num << endl;
    cin >> m >> n;
  }
}