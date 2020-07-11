#include <iostream>
#include <queue>

using namespace std;

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
const int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const string dir = "NSWE";
int n, m;
char dir2[5];
char map[maxn][maxn];
int res[maxn][maxn][maxn][maxn];

struct Node
{
  int Px, Py, Hx, Hy;

  // 初始化
  Node(int Px, int Py, int Hx, int Hy) : Px(Px), Py(Py), Hx(Hx), Hy(Hy) {}
};
queue<Node> q;

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

int bfs(int Px, int Py, int Hx, int Hy)
{
  init();
  q.push(Node(Px, Py, Hx, Hy));
  res[Px][Py][Hx][Hy] = 0;
  while (!q.empty()) // 开始 bfs
  {
    Node node = q.front(); // 获取第一个
    q.pop();               // 同时删除掉
    for (int i = 0; i < 4; i++)
    {
      int j = dir.find(dir2[i]);
      int newPx = node.Px + d[i][0];
      int newPy = node.Py + d[i][1];
      int newHx = node.Hx + d[j][0];
      int newHy = node.Hy + d[j][1];
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
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> map[i];
  }
  cin >> dir2;

  int Px, Py, Hx, Hy;
  Px = Py = Hx = Hy = 0;
  FindLocation(Px, Py, Hx, Hy, n, m);

  int res = bfs(Px, Py, Hx, Hy);
  if (res == 0)
    cout << "Impossible" << endl;
  else
    cout << res << endl;
}