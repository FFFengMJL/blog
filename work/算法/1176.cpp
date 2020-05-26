#include <iostream>

using namespace std;

class unit
{
private:
  int res;
  bool hasCal;

public:
  unit()
  {
    this->res = 0;
    this->hasCal = false;
  }

  unit(int res, bool hasCal)
  {
    this->res = res;
    this->hasCal = hasCal;
  }

  bool getCal()
  {
    return this->hasCal;
  }

  void setHasCal(bool newHasCal)
  {
    this->hasCal = newHasCal;
  }

  int getRes()
  {
    return this->res;
  }

  void setRes(int newRes)
  {
    this->res = newRes;
  }

  void reset()
  {
    this->res = 0;
    this->hasCal = false;
  }
};

const int MAX = 1000;
unit matrix[MAX][MAX];

int twoEnd(int begin, int end, int arr[])
{
  // 终止递归
  if (begin == end - 1)
  {
    matrix[begin][end].setHasCal(true);
    matrix[begin][end].setRes(arr[begin] > arr[end] ? arr[begin] - arr[end] : arr[end] - arr[begin]);
    return matrix[begin][end].getRes();
  }

  // 如果已经存在结果
  if (matrix[begin][end].getCal())
    return matrix[begin][end].getRes();

  // 先手选前
  bool nextChooseFront = arr[begin + 1] >= arr[end];
  int frontChoose = arr[begin] - arr[nextChooseFront ? begin + 1 : end] + twoEnd(nextChooseFront ? begin + 2 : begin + 1, nextChooseFront ? end : end - 1, arr);

  // 先手选后
  nextChooseFront = arr[begin] >= arr[end - 1];
  int endChoose = arr[end] - arr[nextChooseFront ? begin : end - 1] + twoEnd(nextChooseFront ? begin + 1 : begin, nextChooseFront ? end - 1 : end - 2, arr);

  matrix[begin][end].setHasCal(true);
  matrix[begin][end].setRes(frontChoose > endChoose ? frontChoose : endChoose);
  return matrix[begin][end].getRes();
}

int main()
{
  int n = INT32_MIN;
  int game = 0;
  while (1)
  {
    cin >> n;
    if (n != 0)
    {
      game++; // 表示第几个游戏
      int arr[n] = {0};
      for (int i = 0; i < n; i++)
      {
        cin >> arr[i];
      }

      // 重置矩阵
      for (int i = 0; i < MAX; i++)
      {
        for (int j = 0; j < MAX; j++)
        {
          matrix[i][j].reset();
        }
      }

      cout << "In game " << game << ", the greedy strategy might lose by as many as " << twoEnd(0, n - 1, arr)
           << " points." << endl;
    }
    else
      break;
  }

  return 0;
}