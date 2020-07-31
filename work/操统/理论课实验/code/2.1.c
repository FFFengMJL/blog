#include <sys/types.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

#define PERMS (S_IRUSR | S_IWUSR) // 定义权限
#define MAX_SEQUEENCE 10          // 定义队列长度

typedef struct
{
  long fib_squenece[MAX_SEQUEENCE];
  int sequence_size;
} shared_data;

int main(int argc, char **argv)
{
  int seq_size;
  pid_t pid;
  int seg_id;              // 共享内存段的 id
  shared_data *shared_mem; // 共享内存段的指针

  if (argc != 2) // 参数不够
  {
    fprintf(stderr, "Usage: ./shm-fib <int sequence size>\n");
    return -1;
  }

  seq_size = atoi(argv[1]);
  if (seq_size > MAX_SEQUEENCE) // 超出长度
  {
    fprintf(stderr, "队列长度需要小于 %d\n", MAX_SEQUEENCE);
    return -1;
  }

  // 创建内存段
  if (seg_id = shmget(IPC_PRIVATE, sizeof(shared_data), PERMS) == -1)
  {
    fprintf(stderr, "无法创建合适的内存段\n");
    return 1;
  }

  printf("创建共享内存，id 为%d\n", seg_id);

  // 创建共享内存
  if ((shared_mem = (shared_data *)shmat(seg_id, 0, 0)) == (shared_data *)-1)
  {
    fprintf(stderr, "无法绑定到段 %d\n", seg_id);
    return 0;
  }
  shared_mem->sequence_size = seq_size;

  if ((pid = fork()) == (pid_t)-1) // 创建线程失败
    return 1;

  if (pid == 0) // 如果是子进程
  {
    printf("子进程：共享内存绑定到地址 %p\n", shared_mem);

    shared_mem->fib_squenece[0] = 0;
    shared_mem->fib_squenece[1] = 1;

    for (int i = 2; i < shared_mem->sequence_size; i++)
      shared_mem->fib_squenece[i] =
          shared_mem->fib_squenece[i - 1] + shared_mem->fib_squenece[i - 2];

    // 清空
    shmdt((void *)shared_mem);
  }
  else
  {
    wait(NULL);

    for (int i = 0; i < shared_mem->sequence_size; i++)
      printf("第%d位为%ld\n", i, shared_mem->fib_squenece[i]);

    // 清空
    shmdt((void *)shared_mem);
    shmctl(seg_id, IPC_RMID, NULL);
  }

  return 0;
}