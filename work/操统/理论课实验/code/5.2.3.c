#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * 职能
 * @param Reader 代表读者
 * @param Writer 代表写者
*/
typedef enum
{
  Reader,
  Writer
} Role;

/**
 * 线程命令
 * @param threadId int 代表线程 id
 * @param role Role 代表职能
 * @param startTime int 创建线程之后的延迟
 * @param lastTime int 读/写操作持续时间
*/
typedef struct
{
  int threadId;
  Role role;
  int startTime;
  int lastTime;
} ThreadArgs;

#define MAX_THREAD 15

sem_t writing;      // 正在写，写-写互斥
sem_t reading;      // 正在读
sem_t readingCount; // 阅读队列
sem_t writingCount; // 写队列

int writerCount = 0; // 读者数量
int readerCount = 0; // 写者数量
int buffer = 0;

/**
 * 读者函数
 * @param threadArg ThreadArg
*/
void *reader(void *param);

/**
 * 写者函数
 * @param threadArg ThreadArg
*/
void *writer(void *param);

int main(int argc, char *argv[])
{
  // 1. 获取命令
  printf("step 1: 获取命令\n");
  int threadNum = 0;
  int threadId, startTime, lastTime;
  char role;
  ThreadArgs cmds[MAX_THREAD + 1];
  while (scanf("%d %c %d %d", &threadId, &role, &startTime, &lastTime) != EOF)
  {
    cmds[threadNum].threadId = threadId;
    cmds[threadNum].startTime = startTime;
    cmds[threadNum].lastTime = lastTime;
    cmds[threadNum].role = role == 'W' ? Writer : (role == 'R' ? Reader : ' ');
    threadNum++;
  }

  for (int i = 0; i < threadNum; i++)
    printf("命令：%d %c %d %d\n",
           cmds[i].threadId,
           cmds[i].role == Writer ? 'W' : (cmds[i].role == Reader ? 'R' : 'E'),
           cmds[i].startTime, cmds[i].lastTime);

  // 2. 初始化
  printf("\nstep 2: 初始化\n");
  sem_init(&reading, 0, 1);
  sem_init(&writing, 0, 1);
  sem_init(&writingCount, 0, 1);
  sem_init(&readingCount, 0, 1);

  // 3. 创建线程
  printf("\nstep 3: 创建线程\n");
  pthread_t threads[MAX_THREAD + 1];
  for (int i = 0; i < threadNum; i++)
  {
    if (cmds[i].role == Reader)
    {
      pthread_create(&threads[i], NULL, reader, &cmds[i]);
      printf("创建进程 %d ，是读者\n", cmds[i].threadId);
    }
    else if (cmds[i].role == Writer)
    {
      pthread_create(&threads[i], NULL, writer, &cmds[i]);
      printf("创建进程 %d ，是写者\n", cmds[i].threadId);
    }
  }

  // 4. 等待线程结束
  printf("\nstep 4: 等待线程结束\n");
  for (int i = 0; i < threadNum; i++)
    pthread_join(threads[i], NULL);

  // 5. 销毁信号量
  printf("\nstep 5: 销毁信号量\n");

  sem_destroy(&reading);
  sem_destroy(&writing);
  sem_destroy(&writingCount);
  sem_destroy(&readingCount);

  exit(1);
  return 1;
}

void *writer(void *param)
{
  ThreadArgs *cmd = (ThreadArgs *)param;
  sleep(cmd->startTime);
  while (1)
  {
    // 申请资源
    printf("线程 %d （写者）：申请资源\n", cmd->threadId);
    sem_wait(&writingCount);
    writerCount++;
    if (writerCount == 1)
      sem_wait(&reading);
    sem_post(&writingCount);
    sem_wait(&writing); // 写者优先

    // 正式开始写
    buffer = rand() % 65535; // 写入的数据
    printf("线程 %d （写者）：写数据 %d\n", cmd->threadId, buffer);
    sleep(cmd->lastTime);
    printf("线程 %d （写者）：写数据完成\n", cmd->threadId);

    // 释放资源
    sem_wait(&writingCount);
    writerCount--;
    if (writerCount == 0)
      sem_post(&reading);
    sem_post(&writing);
    sem_post(&writingCount);
    pthread_exit(0);
  }
}

void *reader(void *param)
{
  ThreadArgs *cmd = (ThreadArgs *)param;
  sleep(cmd->startTime);
  while (1)
  {
    // 申请资源
    printf("线程 %d （读者）：申请资源\n", cmd->threadId);
    sem_wait(&readingCount);
    readerCount++;
    if (readerCount == 1)
      sem_wait(&writing);
    sem_post(&readingCount);
    sem_wait(&reading);

    // 正式开读
    printf("线程 %d （读者）：读数据 %d\n", cmd->threadId, buffer);
    sleep(cmd->lastTime);
    printf("线程 %d （读者）：读数据完成\n", cmd->threadId);

    // 回收资源
    sem_post(&reading);
    sem_wait(&readingCount);
    readerCount--;
    // if (readerCount == 0)
    sem_post(&writing); // 没有读者时，释放可写信号
    sem_post(&readingCount);

    pthread_exit(0);
  }
}