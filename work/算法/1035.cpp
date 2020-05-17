#include <iostream>
#include <set>

using namespace std;

int matchDNA(int n)
{
  static char strTemp[127]; // 用于获取目标匹配的单链
  int res = 0;              // 结果
  multiset<string> strSet;  // 储存未被匹配的单链
  string str;               // 输入的单链
  string rts;               // 匹配的单链

  strTemp['A'] = 'T';
  strTemp['T'] = 'A';
  strTemp['C'] = 'G';
  strTemp['G'] = 'C';

  for (int i = 0; i < n; i++)
  {
    str = "";
    rts = "";
    cin >> str;
    for (int j = 0; j < str.size(); j++)
    {
      rts += strTemp[str[j]]; // 获取到目标匹配的单链
    }
    if (strSet.count(rts)) // 如果存在目标单链，则在集合中删去并且结果+1
    {
      res++;
      strSet.erase(strSet.find(rts));
    }
    else
    {
      strSet.insert(str); // 否则插入
    }
  }

  return res;
}

int main()
{
  int k = 0;
  cin >> k;

  for (int i = 0; i < k; i++)
  {
    // cout << i;
    int n = 0;
    cin >> n;
    cout << matchDNA(n) << endl;
  }

  return 0;
}