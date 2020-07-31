#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
  int pid1 = fork();
  printf("**1**\n");
  // printf("%d**1**\n", pid1);
  int pid2 = fork();
  printf("%d**2**\n", pid1);
  if (pid1 == 0)
  {
    int pid3 = fork();
    printf("**3**\n");
  }
  else
    printf("**4**\n");
  return 0;
}
