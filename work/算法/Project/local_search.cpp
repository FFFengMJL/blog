#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int goodsNum;
int capacity;

#define MAX_LOOP_TIME 300
#define RAND_TIME 100

vector<int> goods;
vector<int> bins;
vector<int> newGoods; // 用于储存新生成的序列

int bestResult;             // 最好的结果
int noBetterResultTime = 0; // 连续没有出现更优解的次数

/**
 * 获取货物列表
*/
void getGoods();

/**
 * LS 算法
*/
int localSearch();
/**
 * 获取新的货物顺序
*/
void getOneNewGoodsList();

/**
 * 首次适应算法（不能排序）
*/
int firstFit();

/**
 * 最佳适应算法（不能排序）
*/
int bestFit();

/**
 * 用新的序列覆盖原来的序列
*/
void copyGoods();

int main()
{
  time_t startTime, endTime; // 开始与结束时间

  cin >> goodsNum >> capacity;

  goods.clear();
  bins.clear();
  newGoods.clear();

  startTime = clock();
  srand((unsigned)(time(NULL))); // 初始化随机种子，避免生成同样的随机结果

  getGoods();
  localSearch();

  endTime = clock();

  cout << "需要背包数量为：" << bestResult << "\t 消耗时间："
       << (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000 << " ms" << endl;

  return 0;
}

void getGoods()
{
  int good = 0;
  for (int i = 0; i < goodsNum; i++)
  {
    cin >> good;
    goods.push_back(good);
    newGoods.push_back(good);
  }

  sort(goods.begin(), goods.end(), [](int a, int b) { return a > b; });
  sort(newGoods.begin(), newGoods.end(), [](int a, int b) { return a > b; });
}

int localSearch()
{
  int a = firstFit();
  int b = bestFit();
  bestResult = a > b ? b : a;
  while (noBetterResultTime < MAX_LOOP_TIME)
  {
    getOneNewGoodsList(); // 随机生成新的序列
    int ffBins = firstFit();
    int bfBins = bestFit();

    if (bestResult > ffBins || bestResult > bfBins) // 如果有更优解
    {
      bestResult = ffBins < bfBins ? ffBins : bfBins;
      copyGoods();
      noBetterResultTime = 0;
    }
    else
    {
      noBetterResultTime++;
    }
  }
}

void getOneNewGoodsList()
{
  newGoods.clear();
  for (auto i = goods.begin(); i != goods.end(); i++)
  {
    newGoods.push_back(*i);
  }

  // 生成随机序列
  for (int i = 0; i < RAND_TIME; i++)
  {
    int tmp;

    // 生成交换的位置
    int a = rand() % goodsNum;
    int b = rand() % goodsNum;

    tmp = newGoods[a];
    newGoods[a] = newGoods[b];
    newGoods[b] = tmp;
  }
}

void copyGoods()
{
  goods.clear();
  for (int i = 0; i < newGoods.size(); i++)
  {
    goods.push_back(newGoods[i]);
  }
}

int firstFit()
{
  bins.clear();
  for (int i = 0; i < newGoods.size(); i++)
  {
    bool findBin = false;
    for (int j = 0; j < bins.size(); j++)
    {
      if (bins[j] + newGoods[i] <= capacity) // 找到了能放下的就放进去
      {
        bins[j] += newGoods[i];
        findBin = true;
        break;
      }
    }
    if (!findBin) // 否则开一个新的箱子
    {
      bins.push_back(newGoods[i]);
    }
  }

  return bins.size();
}

int bestFit()
{
  bins.clear();
  for (int i = 0; i < newGoods.size(); i++)
  {
    int findBestBin[] = {-1, 0};
    for (int j = 0; j < bins.size(); j++)
    {
      // 如果找到了能放下的，并且剩余容量更小
      if (bins[j] + newGoods[i] <= capacity && findBestBin[1] < bins[j])
      {
        findBestBin[0] = j;
        findBestBin[1] = bins[j];
      }
    }
    if (findBestBin[0] == -1)
    {
      bins.push_back(newGoods[i]);
    }
    else
    {
      bins[findBestBin[0]] += newGoods[i];
    }
  }

  return bins.size();
}