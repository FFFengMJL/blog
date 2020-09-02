#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct city
{
  int no;
  bool arrived;
  vector<int> to;
};

vector<struct city> cities;

int main()
{
  int time;
  cin >> time;
  while (time--)
  {
    cities.clear();
    int cityNum = 0;
    cin >> cityNum;
    struct city tmp;
    tmp.arrived = false;
    tmp.to.clear();
    tmp.no = 0;
    for (int i = 1; i <= cityNum; i++)
    {
      tmp.no = i;
      cities.push_back(tmp);
    }

    // 输入
    int from, to;
    for (int i = 0; i < cityNum - 1; i++)
    {
      cin >> from >> to;
      cities[from].to.push_back(to);
      cities[to].to.push_back(from);
    }

    queue<int> searchList;

    for (int i = 0; i < cityNum; i++)
    {
      if (cities[i].to.size() == 1)
      {
        searchList.push(i);
      }
    }
  }

  return 0;
}
