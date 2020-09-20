#include <iostream>
#include <vector>

using namespace std;

vector<char> l, r;

bool test(string s)
{
  // cout << s << endl;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{')
    {
      l.push_back(s[i]);
    }
    else if ((s[i] == ')' && l[l.size() - 1] == '(') ||
             (s[i] == ']' && l[l.size() - 1] == '[') ||
             (s[i] == '}' && l[l.size() - 1] == '{'))
    {
      l.pop_back();
    }
    else
    {
      r.push_back(s[i]);
      return false;
    }
    // cout << l[l.size() - 1] << '\t' << s[i] << endl;
  }
  return l.size() == 0;
}

int main()
{
  string s;
  int len = 0;
  cin >> len;
  // cin >> s;
  while (cin >> s)
  {
    l.clear();
    r.clear();
    cout << (test(s) ? "YES" : "NO") << endl;
    cin >> len;
    // cin >> s;
  }
}