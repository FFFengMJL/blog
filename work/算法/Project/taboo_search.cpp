#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAX_ITERATION_TIME 1000 // 最大迭代次数
#define RAND_TIME 100           // 随机次数

vector<int> goods;
vector<int> newGoods;
vector<int> bins;

int goodsNum;   // 货物数量
int capacity;   // 容量
int bestResult; // 最佳结果

// 禁忌对象
struct TabooObject
{
  int length;            // 禁忌长度（生命周期）
  int bins;              // 需要箱子数量（其实好像用不到）
  vector<int> goodsList; // 储存货物顺序的向量
};

int bestInTabooList = 0; // 这个没用上

vector<struct TabooObject> tabooList; // 禁忌列表

/**
 * 获取输入
*/
void getGoods();

/**
 * 复制 vector<int>
 * @param from - vector<int> 被复制的向量
 * @param &to - vector<int> 目的向量
*/
void copyGoods(vector<int> from, vector<int> &to);

/**
 * 首次适应算法
 * @return 返回需要的箱子
*/
int firstFit();

/**
 * 最佳适应算法
 * @return 返回需要的箱子
*/
int bestFit();

/**
 * 主要迭代步骤
*/
void iterate();

/**
 * 所有禁忌对象长度 - 1
 * 如果有变为0的，就删除掉
*/
void deleteTabooList();

/**
 * 在禁忌列表中寻找是否有对应的向量
*/
int findInTabooList(vector<int> list);

int main()
{
  time_t startTime, endTime;
  cin >> goodsNum >> capacity;
  srand((unsigned)(time(NULL)));

  startTime = clock();
  getGoods();
  copyGoods(goods, newGoods);
  int ffBins = firstFit();
  int bfBins = bestFit();
  bestResult = ffBins > bfBins ? bfBins : ffBins;
  iterate();

  for (int i = 0; i < MAX_ITERATION_TIME; i++)
  {
    iterate();
  }

  endTime = clock();

  cout << "需要背包数量为：" << bestResult
       << "\t 消耗时间："
       << (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
}

void getGoods()
{
  int good;
  for (int i = 0; i < goodsNum; i++)
  {
    cin >> good;
    goods.push_back(good);
  }

  sort(goods.begin(), goods.end(), [](int a, int b) { return a > b; });
}

void copyGoods(vector<int> from, vector<int> &to)
{
  to.clear();
  for (auto i = from.begin(); i != from.end(); i++)
  {
    to.push_back(*i);
  }
}

void getNewGoodsList()
{
  copyGoods(goods, newGoods);
  for (int i = 0; i < RAND_TIME; i++)
  {
    int a = rand() % goodsNum;
    int b = rand() % goodsNum;

    int tmp = newGoods[a];
    newGoods[a] = newGoods[b];
    newGoods[b] = tmp;
  }
}

void iterate()
{
  getNewGoodsList();
  int ffBins = firstFit();
  int bfBins = bestFit();

  // 如果没找到，就需要加入到禁忌表中
  if (findInTabooList(newGoods) == -1)
  {
    struct TabooObject tmp;
    tmp.bins = ffBins < bfBins ? ffBins : bfBins;
    // tmp.bins = sqrt(MAX_ITERATION_TIME);
    tmp.bins = sqrt(goodsNum);
    copyGoods(newGoods, tmp.goodsList);
    tabooList.push_back(tmp);
  }

  // 如果是更优解，就更新
  if (bestResult > ffBins || bestResult > bfBins)
  {
    bestResult = ffBins < bfBins ? ffBins : bfBins;
    copyGoods(newGoods, goods);
  }

  // 更新禁忌表
  deleteTabooList();
}

int findInTabooList(vector<int> list)
{
  for (int i = 0; i < tabooList.size(); i++) // 遍历禁忌表
  {
    bool isSame = true;
    // 遍历当前禁忌对象，判断是否和传入向量等价
    for (int j = 0; j < tabooList[i].goodsList.size(); j++)
    {
      if (tabooList[i].goodsList[j] != list[j])
      {
        isSame = false;
        break;
      }
    }
    if (isSame) // 如果等价，则禁忌长度加1，返回该对象的索引
    {
      tabooList[i].length++;
      return i;
    }
  }
  // 否则返回 -1
  return -1;
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

void deleteTabooList()
{
  for (auto i = tabooList.begin(); i != tabooList.end(); i++)
  {
    i->length--;
  }

  sort(tabooList.begin(), tabooList.end(), [](struct TabooObject a, struct TabooObject b) { return a.length > b.length; }); // 排序，好删掉是0的

  for (int i = tabooList.size() - 1; i >= 0; i--)
  {
    if (tabooList[i].length == 0)
    {
      tabooList.pop_back();
    }
    else // 不为0直接中断
    {
      break;
    }
  }
}