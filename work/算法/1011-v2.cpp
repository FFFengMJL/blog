#include <iostream>
#include <time.h>

using namespace std;

long lotto(int i, int j, long **arr)
{
  if (i == 1)
    return arr[i][j];
  for (int k = 2; k <= i; k++)
  {
    for (int e = 1; e <= j; e++)
      arr[k][e] = arr[k][e - 1] + arr[k - 1][e / 2];
  }
  return arr[i][j];
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
          arr[i][j] = i == 1 ? j : 0;
        }
      }

      cout << "Case " << caseNum << ": n = " << N << ", m = " << M << ", # lists = "
           << lotto(N, M, arr) << endl;

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