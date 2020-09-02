#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

#define MAX_NUM 1000

time_t startTime, endTime; // 开始和结束时间

int goodsNum;      // 货物数量
int capacity;      // 箱子容量
vector<int> bins;  // 箱子
vector<int> goods; // 货物队列
int bin;           // 当前箱子

/**
 * 首次适应
*/
void firstFit(int goodsNum);

int main()
{
  cin >> goodsNum;
  cin >> capacity;

  bins.clear();
  goods.clear();
  bin = 0;

  cout << "货物数量：" << goodsNum << '\t' << "背包容量：" << capacity << endl;

  startTime = clock();

  firstFit(goodsNum);

  endTime = clock();

  cout << "需要背包数量为：" << bins.size() << "\t 消耗时间："
       << (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000 << " ms" << endl;

  return 0;
}

void firstFit(int goodsNum)
{
  for (int i = 0; i < goodsNum; i++) // 在线输入
  {
    int good = 0;
    bool findBin = false;
    cin >> good;
    for (int i = 0; i < bins.size(); i++)
    {
      if (bins[i] + good <= capacity) // 能够找到对应的箱子
      {
        bins[i] += good;
        findBin = true;
        break;
      }
    }
    if (!findBin) // 如果没有找到
    {
      bins.push_back(good);
    }
  }
}
