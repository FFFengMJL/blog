// 有问题，不知道为什么 matrix 会提前销毁

#include <iostream>

using namespace std;

// 利用自定义类帮助计算
class matrix
{
private:
  int **res;
  bool **hasCal;
  int size;

public:
  matrix(int n)
  {
    this->size = n;
    this->res = new int *[n];
    this->hasCal = new bool *[n];
    for (int i = 0; i < n; i++)
    {
      this->res[i] = new int[n];
      this->hasCal[i] = new bool[n];
    }
    this->reset();
  }

  void reset()
  {
    for (int i = 0; i < this->size; i++)
    {
      for (int j = 0; j < this->size; j++)
      {
        this->res[i][j] = 0;
        this->hasCal[i][j] = false;
      }
    }
  }

  int getRes(int begin, int end)
  {
    return this->res[begin][end];
  }

  bool getHasCal(int begin, int end)
  {
    return this->hasCal[begin][end];
  }

  void setRes(int begin, int end, int res)
  {
    this->res[begin][end] = res;
  }

  void setHasCal(int begin, int end, bool newHasCal)
  {
    this->hasCal[begin][end] = newHasCal;
  }

  ~matrix()
  {
    for (int i = 0; i < this->size; i++)
    {
      delete[] this->hasCal[i];
      delete[] this->res[i];
    }
    delete[] this->hasCal;
    delete[] this->res;
  }
};

int twoEnd(int begin, int end, int arr[], matrix *disk)
{
  // 终止递归
  if (begin == end - 1)
  {
    disk->setHasCal(begin, end, true);
    disk->setRes(begin, end, arr[begin] > arr[end] ? arr[begin] - arr[end] : arr[end] - arr[begin]);
    return disk->getRes(begin, end);
  }

  // 如果已经存在结果
  if (disk->getHasCal(begin, end))
    return disk->getRes(begin, end);

  // 先手选前
  bool nextChooseFront = arr[begin + 1] >= arr[end];
  int frontChoose = arr[begin] - arr[nextChooseFront ? begin + 1 : end] + twoEnd(nextChooseFront ? begin + 2 : begin + 1, nextChooseFront ? end : end - 1, arr, disk);

  // 先手选后
  nextChooseFront = arr[begin] >= arr[end - 1];
  int endChoose = arr[end] - arr[nextChooseFront ? begin : end - 1] + twoEnd(nextChooseFront ? begin + 1 : begin, nextChooseFront ? end - 1 : end - 2, arr, disk);

  disk->setHasCal(begin, end, true);
  disk->setRes(begin, end, frontChoose > endChoose ? frontChoose : endChoose);
  return disk->getRes(begin, end);
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
      matrix *disk = new matrix(n);
      cout << "In game " << game << ", the greedy strategy might lose by as many as " << twoEnd(0, n - 1, arr, disk)
           << " points." << endl;
    }
    else
      break;
  }

  return 0;
}