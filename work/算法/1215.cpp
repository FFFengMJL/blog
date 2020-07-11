#include <iostream>
#include <vector>

using namespace std;

// 定义上下左右
#define UP 'N'
#define DOWN 'S'
#define LEFT 'W'
#define RIGHT 'E'

// 定义 墙|熔浆|通路
#define WALL '#'
#define MELT '!'
#define ROAD '.'

// 定义两个人
#define Paris 'P'
#define Helen 'H'

vector<string> map;                // 地图
int n, m;                          // 地图的行，列
const string MOVE_ACTION = "NSWE"; // 运动的操作
string H_way = "";                 // 表示 H 的路线
bool flag = false;
string storage = "";

int goX(int x, char positon)
{
  int res = x;
  if (positon == LEFT)
  {
    res--;
    return res < 0 ? x : res; // 越界返回 x ，否则返回 res
  }
  if (positon == RIGHT)
  {
    res++;
    return res >= m ? x : res; // 越界返回 x ，否则返回 res
  }
  return x; // 移动指令不匹配
}

int goY(int y, char position)
{
  int res = y;
  if (position == UP)
  {
    res--;
    return res < 0 ? y : res; // 越界返回 y ，否则返回 res
  }
  if (position == DOWN)
  {
    res++;
    return res >= n ? y : res; // 越界返回 y ，否则返回 res
  }
  return y;
}

// 思路，递归函数，每一层都有 P 先走一步，H 再走一步
string FindWay(int Px, int Py, int Hx, int Hy, string hasGone)
{
  if (255 < hasGone.length()) // 极限
    return "";
  else
  {
    // int storage = -1; // 用于储存最小
    for (int i = 0; i < MOVE_ACTION.length(); i++)
    {
      int newPx = goX(Px, MOVE_ACTION[i]);
      int newPy = goY(Py, MOVE_ACTION[i]);
      if (map[newPy][newPx] == ROAD) // 如果 P 走得通
      {
        // H 行动
        int newHx = goX(Hx, H_way[i]);
        int newHy = goY(Hy, H_way[i]);

        if (map[newHy][newHx] != ROAD) // 如果 H 走不通，可能是岩石|熔浆
        {
          if (map[newHy][newHx] == MELT) // 如果是熔浆，则木大
            return "";
          // 岩石，则应该不动
          else if (map[newHy][newHx] == WALL)
          {
            newHx = Hx;
            newHy = Hy;
          }
        }
        if (newPx == newHx && newPy == newHy) // 此时重合
        {
          // cout << endl;
          // storage = hasGone.length() + 1;
          // cout << storage << " ";
          return hasGone + MOVE_ACTION[i]; // 返回结果
        }
        else
        {
          string tmp = FindWay(newPx, newPy, newHx, newHy, hasGone + MOVE_ACTION[i]);
          if (tmp != "") // 如果存在路径
          {
            // cout << "tmp: " << tmp << " ";
            // 当 storage 为空，存 tmp ，否则存最小的那个
            if (storage == "")
            {
              storage = tmp;
            }
            else
            {
              // storage = tmp;
              storage = storage.length() < tmp.length() ? storage : tmp;
            }
            // cout << storage << endl;
          }
        }
      }
    }
    // cout << storage << endl;
    return storage;
  }
}

// 寻找两个人的位置
void FindLocation(int &Px, int &Py, int &Hx, int &Hy, int n, int m)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // cout << map[i][j] << endl;
      if (map[i][j] == Paris)
      {
        Px = j;
        Py = i;
        map[i][j] = '.'; // 清除位置
      }
      else if (map[i][j] == Helen)
      {
        Hx = j;
        Hy = i;
        map[i][j] = '.'; // 清除位置
      }
      if (Hx && Hy && Px && Py)
        return;
    }
  }
}

int main()
{
  n = m = 0;
  cin >> n >> m;
  map.clear();
  for (int i = 0; i < n; i++)
  {
    string line = "";
    cin >> line;
    map.push_back(line);
  }

  cin >> H_way;

  int Hx, Hy, Px, Py;
  Px = Py = Hx = Hy = 0;
  FindLocation(Px, Py, Hx, Hy, n, m);
  // cout << MOVE_ACTION << endl;

  string res = FindWay(Px, Py, Hx, Hy, "");

  if (res == "")
    cout << "Impossible" << endl;
  else
    cout << res.length() << endl;
  // cout << res << ' ' << res.length() << endl;

  return 0;
}

/*
5 5
#####
#H..#
#.!.#
#.#P#
#####
WNSE

5
*/