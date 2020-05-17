#include <iostream>
#include <algorithm>

using namespace std;

string minString(string strList[], int length)
{
  string res = "", tmp = "";
  for (int i = 0; i < length; i++) // 初始值
  {
    res += strList[i];
  }
  while (next_permutation(strList, strList + length)) // 全排列函数，方便组合
  {
    bool flag = true;
    tmp = "";
    for (int i = 0; i < length; i++)
    {
      if (strList[i] + tmp < tmp + strList[i] || tmp + strList[i] > res) // 这种情况下，再继续拼接字符串没有意义了
      {
        flag = false; // 表示是否终止
        break;
      }
      else
      {
        tmp += strList[i];
      }
    }
    if (flag)
    {
      res = res < tmp ? res : tmp;
    }
  }

  return res;
}

int main()
{

  int t = 0;
  cin >> t;
  while (t--)
  {
    int n = 0;
    cin >> n;
    string strList[n] = {};
    for (int i = 0; i < n; i++)
    {
      cin >> strList[i];
    }
    sort(strList, strList + n);
    cout << minString(strList, n) << endl;
  }
}