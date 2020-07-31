#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 256

long fib[MAX_SIZE]; // 储存用的数组

void *run(void *arg)
{
  int upper = atoi(arg); // 上限

  if (upper == 0)
    pthread_exit(0);
  else
  {
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < upper; i++)
      fib[i] = fib[i - 1] + fib[i - 2];
  }

  pthread_exit(0);
}

int main(int argc, char **argv[])
{
  pthread_t tid;        // 线程 id
  pthread_attr_t tattr; // 线程属性

  if (argc != 2) // 参数不够
  {
    fprintf(stderr, "Usage: ./a.out <int value>\n");
    return -1;
  }

  int parem = atoi(argv[1]);
  if (parem < 0)
  {
    fprintf(stderr, "参数为%d，需要大于0", parem);
    return -1;
  }

  pthread_attr_init(&tattr);                  // 初始化属性
  pthread_create(&tid, &tattr, run, argv[1]); // 创建线程

  pthread_join(tid, NULL); // 等待结束

  for (int i = 0; i < parem; i++)
    printf("第%d位为%ld\n", i, fib[i]);
  // printf("%d is %d\n", i, fib[i]);

  return 0;
}