#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

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

const int maxn = 21;
vector<string> map;                // 地图
int n, m;                          // 地图的行，列
const string MOVE_ACTION = "NSWE"; // 运动的操作
string H_way = "";                 // 表示 H 的路线
int res[maxn][maxn][maxn][maxn];

struct Node
{
  int Px, Py, Hx, Hy;

  // 初始化
  Node(int Px, int Py, int Hx, int Hy) : Px(Px), Py(Py), Hx(Hx), Hy(Hy) {}
};
queue<Node> q;

int goX(int x, char positon)
{
  int res = x;
  if (positon == UP)
  {
    res--;
    return res < 0 ? x : res; // 越界返回 x ，否则返回 res
  }
  if (positon == DOWN)
  {
    res++;
    return res >= n ? x : res; // 越界返回 x ，否则返回 res
  }
  return x; // 移动指令不匹配
}

int goY(int y, char position)
{
  int res = y;
  if (position == LEFT)
  {
    res--;
    return res < 0 ? y : res; // 越界返回 y ，否则返回 res
  }
  if (position == RIGHT)
  {
    res++;
    return res >= m ? y : res; // 越界返回 y ，否则返回 res
  }
  return y;
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
        Px = i;
        Py = j;
        map[i][j] = '.'; // 清除位置
      }
      else if (map[i][j] == Helen)
      {
        Hx = i;
        Hy = j;
        map[i][j] = '.'; // 清除位置
      }
      if (Hx && Hy && Px && Py)
        return;
    }
  }
}

void init()
{
  for (int i = 0; i < maxn; i++)
  {
    for (int j = 0; j < maxn; j++)
    {
      for (int k = 0; k < maxn; k++)
      {
        for (int l = 0; l < maxn; l++)
        {
          res[i][j][k][l] = -1;
          // cout << res[i][j][k][l] << ' ';
        }
      }
    }
  }
}

int bfs(int Px, int Py, int Hx, int Hy)
{
  init();
  q.push(Node(Px, Py, Hx, Hy));
  res[Px][Py][Hx][Hy] = 0;
  while (!q.empty()) // 开始 bfs
  {
    Node node = q.front(); // 获取第一个
    q.pop();               // 同时删除掉
    for (int i = 0; i < MOVE_ACTION.length(); i++)
    {
      int newPx = goX(node.Px, MOVE_ACTION[i]);
      int newPy = goY(node.Py, MOVE_ACTION[i]);
      int newHx = goX(node.Hx, H_way[i]);
      int newHy = goY(node.Hy, H_way[i]);
      // printf("%d %d %d %d\n", newPx, newPy, newHx, newHy);

      if (map[newPx][newPy] == ROAD && map[newHx][newHy] != MELT) // 两人都能走
      {
        if (map[newHx][newHy] == WALL) // 如果 H 下一块是岩石, 则需要恢复到刚才的位置
        {
          newHx = node.Hx;
          newHy = node.Hy;
        }
        // printf("real : %d %d %d %d\n", newPx, newPy, newHx, newHy);
        if (make_pair(node.Px, node.Py) == make_pair(newHx, newHy) &&
                make_pair(node.Hx, node.Hy) == make_pair(newPx, newPy) ||
            make_pair(newPx, newPy) == make_pair(newHx, newHy)) // 如果下一步能够重合
        {
          // printf("%d %d %d %d %d\n", newPx, newPy, newHx, newHy, res[node.Px][node.Py][node.Hx][node.Hy] + 1);

          return res[node.Px][node.Py][node.Hx][node.Hy] + 1;
        }
        if (res[newPx][newPy][newHx][newHy] < 0) // 如果该状态没出现过
        {
          res[newPx][newPy][newHx][newHy] = res[node.Px][node.Py][node.Hx][node.Hy] + 1;
          q.push(Node(newPx, newPy, newHx, newHy));
        }
        // printf("saved: %d %d %d %d %d\n", newPx, newPy, newHx, newHy, res[newPx][newPy][newHx][newHy]);
      }
    }
  }

  return -1;
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

  int res = bfs(Px, Py, Hx, Hy);
  if (res == 0)
    cout << "Impossible" << endl;
  else
    cout << res << endl;
}