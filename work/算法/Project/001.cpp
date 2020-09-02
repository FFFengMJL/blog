#include <iostream>
#include <cstdio>
#include <time.h>
#include <signal.h>
#include <vector>

using namespace std;

#define MAX_NUM 1000

time_t startTime, endTime; // 开始和结束时间

int goodNums;      // 货物数量
int capacity;      // 箱子容量
vector<int> bins;  // 箱子
vector<int> goods; // 货物队列

/**
 * 下项适应
*/
void nextFit();

/**
 * 显示运行的时间
*/
void displayRunTime(int i);

int main()
{

  signal(SIGINT, displayRunTime);
  cin >> goodNums;
  cin >> capacity;

  bins.clear();

  cout << goodNums << '\t' << capacity << endl;
  for (int i = 0; i < goodNums; i++)
  {
    int good = 0;
    cin >> good;
    goods.push_back(good);
    cout << i << '\t' << good << endl;
  }

  startTime = clock();

  nextFit();

  endTime = clock();

  cout << "需要背包数量为：" << bins.size() << "\t 消耗时间："
       << (double)(endTime - startTime) / CLOCKS_PER_SEC << endl;

  for (int i = 0; i <)
  {
    cout <<
  }

  return 0;
}

void nextFit()
{
  bins.push_back(0); // 新开一个背包
  while (!goods.empty())
  {
    for (int i = 0; i < bins.size(); i++)
    {
      // 如果能装下，就放进去，然后移除这个货物
      if (bins[i] + goods[goods.size() - 1] <= capacity)
      {
        bins[i] += goods[goods.size() - 1];
        goods.pop_back();
        break;
      }
    }
    // 否则就新开一个背包
    bins.push_back(goods[goods.size() - 1]);
    goods.pop_back();
  }
}

void displayRunTime(int i)
{
  time_t nowTime = clock();
  cout << "已经消耗时间："
       << (double)(nowTime - startTime) / CLOCKS_PER_SEC << endl;
}