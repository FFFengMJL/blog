#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
  string line;
  string finalUrl = "data: image/jpeg; base64, ";
  vector<string> lines;
  int flag;

  // scanf("%s", line);
  cin >> line;
  cin >> line;
  cin >> line;
  lines.push_back(finalUrl);

  while (1)
  {
    cin >> line;
    // cout << line;
    if (line == "end" || line == "====")
      break;
    lines.push_back(line);
  }

  for (int i = 0; i < lines.size(); i++)
    cout << lines[i];
  return 0;
}