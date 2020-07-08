#include <iostream>
#include <vector>

using namespace std;

// 1 0
// 1 1
// 1 1
// 3 1
// 1 3
// 2 2
// 1 2
// 2 1
// 0 88

#define maxNode 100          // 节点最大可能数量
int maxDepth, maxWidth;      // 储存最大深度和最大宽度
int in[maxNode];             // 代表入度
bool mark[maxNode];          // 代表是否走过
int width[maxNode];          // 代表深度
vector<int> forest[maxNode]; // 储存图

bool dfs(int node, int depth)
{
  mark[node] = true; // 已经访问过
  width[depth]++;
  maxDepth = maxDepth > depth ? maxDepth : depth; // 当前最大深度
  for (int i = 0; i < forest[node].size(); i++)
  {
    int nextNode = forest[node][i]; // 得到下一个子节点
    if (mark[nextNode])             // 多条边指向同一个节点
      return false;
    else if (dfs(nextNode, depth + 1) == false)
      return false;
  }
  return true;
}

int main()
{
  while (1)
  {
    int n, m;
    cin >> n >> m;

    if (n == 0)
      return 0;

    for (int i = 0; i < n; i++) // 储存清空，设定初始值
    {
      forest[i].clear();
      mark[i] = false;
      width[i] = 0;
      in[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
      int a, b;
      cin >> a >> b;
      forest[a - 1].push_back(b - 1); // 分别 -1 对应
      in[b - 1]++;
    }

    maxDepth = maxWidth = 0;
    bool flag = true; // 用于判断循环是否继续

    // 在有根的情况下进行 dfs
    for (int i = 0; i < n; i++)
    {
      // 根节点， dfs 时放在第0层
      // 如果 dfs 失败，说明不能构成图
      // 利用短路简化代码
      if (in[i] == 0 && !dfs(i, 0))
      {
        flag = false;
        break;
      }
    }

    // 存在环的情况
    for (int i = 0; i < n && flag; i++)
    {
      if (mark[i] == false) // 出现没有连接的情况
      {
        flag = false;
        break;
      }
      maxWidth = max(maxWidth, width[i]);
    }

    if (flag)
      cout << maxDepth << ' ' << maxWidth << endl;
    else
      cout << "INVALID" << endl;
  }

  return 0;
}