#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

const int maxt = 24;                                                                                                                                 // 好像没什么用
double tarX, tarY;                                                                                                                                   // 代表目标位置
double betweenMin;                                                                                                                                   // 结果
const double fourFive = sqrt(2) / 2;                                                                                                                 // 45度计算用
const double angles[][2] = {{0, 1}, {fourFive, fourFive}, {1, 0}, {fourFive, -fourFive}, {0, -1}, {-fourFive, fourFive}, {-1, 0}, {-1, fourFive}};   // 定义角度，0~7
const double angles_opt[][4] = {{0, 1, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, -1}, {0, -1, 0, 0}, {0, 0, -1, 0}, {-1, 0, 0, 0}, {0, 0, 0, 1}}; // 定义角度，0~7 优化后

void prop(double x, double y, int angle, int leftTime)
{
  if (leftTime == 0)
  {
    double res = sqrt(pow(abs(x - tarX), 2) + pow(abs(y - tarY), 2));
    // printf("x = %.6lf y = %.6lf between = %.6lf\n", x, y, res);
    betweenMin = betweenMin < res ? betweenMin : res;
    // return sqrt(pow(abs(x - tarX), 2) + pow(abs(y - tarY), 2));
  }
  // return sqrt(pow(abs(x - tarX), 2) + pow(abs(y - tarY), 2));
  else
  {
    double newX = x + 10 * angles[angle][0];
    double newY = y + 10 * angles[angle][1];
    prop(newX, newY, angle, leftTime - 1);
    prop(x, y, (angle + 1) % 8, leftTime - 1);
    // return goAhead < anglePlus ? goAhead : anglePlus;
  }
}

void prop_opt(double x, double y, int a, int b, int angle, int leftTime)
{
  if (leftTime == 0)
  {
    double finalX = (x + (a - b) * fourFive) * 10; // 最终的横坐标
    double finalY = (y + (b + a) * fourFive) * 10; // 最终的纵坐标
    double res = sqrt(pow(abs(finalX - tarX), 2) + pow(abs(finalY - tarY), 2));
    betweenMin = betweenMin < res ? betweenMin : res;
  }
  // return sqrt(pow(abs(x - tarX), 2) + pow(abs(y - tarY), 2));
  else
  {
    double newX = x + angles_opt[angle][0];
    double newY = y + angles_opt[angle][1];
    double newA = a + angles_opt[angle][2];
    double newB = b + angles_opt[angle][3];
    prop_opt(newX, newY, newA, newB, angle, leftTime - 1);
    prop_opt(x, y, a, b, (angle + 1) % 8, leftTime - 1);
    // return goAhead < anglePlus ? goAhead : anglePlus;
  }
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int leftTime;
    cin >> leftTime >> tarX >> tarY;
    betweenMin = sqrt(pow(abs(tarX), 2) + pow(abs(tarY), 2));
    // bfs(0, 0, leftTime);
    // printf("%.6lf\n", betweenMin);
    prop_opt(0, 0, 0, 0, 2, leftTime);
    printf("%.6lf\n", betweenMin);
  }
}

/*
2
24 5.0 5.0
9 7.0 17.0

0.502525
0.100505
*/