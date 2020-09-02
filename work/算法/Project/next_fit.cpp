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
 * 下项适应
*/
void nextFit(int goodsNum);

int main()
{

  cin >> goodsNum;
  cin >> capacity;

  bins.clear();
  goods.clear();
  bin = 0;

  cout << "货物数量：" << goodsNum << '\t' << "背包容量：" << capacity << endl;

  startTime = clock();

  nextFit(goodsNum);

  endTime = clock();

  cout << "需要背包数量为：" << bins.size() << "\t 消耗时间："
       << (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000 << " ms" << endl;

  return 0;
}

void nextFit(int goodsNum)
{
  for (int i = 0; i < goodsNum; i++)
  {
    int good = 0;
    cin >> good;
    if (good + bin <= capacity) // 如果能装下
    {
      bin += good;
    }
    else
    {
      bins.push_back(bin);
      bin = good;
    }
    goods.push_back(good);
    // cout << i << '\t' << good << endl;
  }
  bins.push_back(bin);
}
