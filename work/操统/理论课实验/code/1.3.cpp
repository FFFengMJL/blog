#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
  cout << 'a' << endl;

  // 创建子进程b
  pid_t pid_b = fork();
  if (pid_b == 0) // 确认是子进程b
  {
    cout << 'b' << endl;
    pid_t pid_c = fork();

    if (pid_c == 0) // 确认是子进程c
    {
      cout << 'c' << endl;
    }
  }

  return 0;
}