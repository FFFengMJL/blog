#include <iostream>
#include <vector>

using namespace std;

#define maxGold 30000
#define maxKid 100

void count(int v, int sum[], vector<int> link[])
{
}

void count_sum(int u, int fa, int sum[], vector<int> link[])
{
  sum[u] = 1;
  for (int i = 0; i < link[u].size(); i++)
  {
    int nextNode = link[u][i];
    if (nextNode == fa)
      continue;
    count(nextNode, sum, link);
  }
}

int main()
{
  vector<int> link[maxGold];
  int n, k;
  cin >> n >> k;
  int sum[maxGold];
  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    link[x - 1].push_back(y - 1);
    link[y - 1].push_back(x - 1);
  }
}