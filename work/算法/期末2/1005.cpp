#include <iostream>
#include <cstdio>

using namespace std;

int res = 0;

void mergeSort(int *num, int begin, int end, int length)
{
  cout << "b: " << begin << " e: " << end << " len: " << length << endl;
  for (int i = begin; i <= end; i++)
    cout << num[i];
  cout << endl;

  if (end - begin == 1 && num[begin] > num[end])
  {
    res++;
    int tmp = num[begin];
    num[begin] = num[end];
    num[end] = tmp;

    cout << "l2 " << res << endl;
    return;
  }
  else if (length == 1)
  {
    cout << "l1 " << res << endl;
    return;
  }
  mergeSort(num, begin, (end + begin) / 2, length / 2 + length % 2);
  mergeSort(num, (end + begin) / 2 + 1, end, length / 2);

  int l = begin, r = (end + begin) / 2 + 1;
  int tmpList[length];
  // while (l != (end + begin) / 2 + 1 || r != r == end + 1)
  // {
  // }
  for (int i = 0; i < length; i++)
  {
    if (l != (end + begin) / 2 + 1 && r != end + 1)
    {
      if (num[l] > num[r])
      {
        tmpList[i] = num[r++];
        res++;
      }
      else
      {
        tmpList[i] = num[l++];
      }
    }
    else
    {
      if (l == (end + begin) / 2 + 1)
        tmpList[i] = num[r++];
      else
      {
        // cout << l << endl;
        tmpList[i] = num[l++];
        res++;
      }
    }
    //   if (l == (end + begin) / 2 + 1 || num[l] > num[r])
    //   {
    //     tmpList[i] = num[r];
    //     r++;
    //     if (l != (end + begin) / 2 + 1)
    //       res++;
    //   }
    //   else if (r == end + 1 || num[l] <= num[r])
    //   {
    //     if (r == end + 1)
    //       res++;
    //     tmpList[i] = num[l];
    //     l++;
    //   }
  }

  for (int i = 0; i < length; i++)
    num[i + begin] = tmpList[i];
  for (int i = begin; i <= end; i++)
    cout << num[i];
  cout << " res: " << res << endl;
}

int main()
{
  int n;
  while (cin >> n)
  {
    res = 0;
    int num[n];
    for (int i = 0; i < n; i++)
    {
      cin >> num[i];
    }
    for (int i = 0; i < n; i++)
      cout << num[i];
    cout << endl;

    mergeSort(num, 0, n - 1, n);
    cout << res << endl;

    for (int i = 0; i < n; i++)
      cout << num[i];
    cout << endl;
  }
}