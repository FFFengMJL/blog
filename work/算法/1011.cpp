#include <iostream>
#include <time.h>

using namespace std;

// 这函数没用了
int lotto(int i, int j, int **arr)
{
  if (i == 1)
    return arr[i][j];
  int res = 0;
  for (int e = 1; e <= (j / 2); e++)
  {
    res += lotto(i - 1, e, arr);
  }
  arr[i][j] = res;
  return arr[i][j];
}

void lotto_loop(int N, int M, long **arr)
{
  if (N == 1)
    return;

  // 从长度为 2 开始
  for (int i = 2; i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
    {
      for (int k = 1; k <= j / 2; k++)
        arr[i][j] += arr[i - 1][k];
    }
  }
}

int main()
{
  int n = 0, caseNum = 0;
  cin >> n;
  while (n--)
  {
    caseNum++;
    int N, M;
    cin >> N >> M;
    int startTime = clock();
    // 算法代码
    {
      // 初始化二维数组
      long **arr = new long *[N + 1];
      for (int i = 0; i < N + 1; i++)
      {
        arr[i] = new long[M + 1];
        for (int j = 0; j < M + 1; j++)
        {
          arr[i][j] = i == 1 ? 1 : 0;
          if (i == 0 || j == 0)
            arr[i][j] = i == 0 ? j : i;
        }
      }
      // 需要进行累加
      long res = 0;
      lotto_loop(N, M, arr);
      for (int i = 1; i < M + 1; i++)
        res += arr[N][i];
      cout << "Case " << caseNum << ": n = " << N << ", m = " << M << ", # lists = "
           << res << endl;

      // for (int i = 0; i < N + 1; i++)
      // {
      //   for (int j = 0; j < M + 1; j++)
      //     cout << arr[i][j] << '\t';
      //   cout << endl;
      // }
    }
    int endTime = clock();
    cout << "process time = " << (double)(endTime - startTime) / CLOCKS_PER_SEC << endl;
  }
  return 0;
}