#include <stdio.h>

int main()
{
  char test[5];
  sprintf(test, "%2x%2x%2x", "123456");
  for (int i = 0; i < 4; i++)
  {
    printf("%x\n", test[i]);
  }
}