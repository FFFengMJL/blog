#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

typedef int buffer_item;
#define BUFFER_SIZE 5
#define MAX_THREAD 10

buffer_item buffer[BUFFER_SIZE];

typedef struct
{
  int thread_id; // 线程 id
  char role;     // P 生产者， C 消费者
  int startTime; // 线程创建后开始行动的时间
  int lastTime;  // 生产/消费持续时间
  int products;  // 产品（只有生产者才有）
} ThreadArgs;    // 线程的参数

pthread_mutex_t mutex;
sem_t full, empty;

int pBufferIndex = 0, cBufferIndex = 0; // 分别作为生产者/消费者在缓冲区上面的索引

int insertItem(buffer_item item);
int removeItem(int threadId);
void *producer(void *param);
void *consumer(void *param);

int main(int argc, char *argv[])
{
  // 1. 运行可执行文件时需要三个参数
  printf("step 1： 获取参数\n");
  ThreadArgs cmds[MAX_THREAD + 1];
  int threadId, threadNum = 0;
  char role;
  while (scanf("%d %c", &threadId, &role) != EOF)
  {
    // 默认角色是 C
    // printf("%c", role);
    if (role == 'P' || role == 'C')
    {
      cmds[threadNum].thread_id = threadId;
      cmds[threadNum].role = role;
      int startTime, lastTime;
      scanf("%d %d", &startTime, &lastTime);
      cmds[threadNum].startTime = startTime;
      cmds[threadNum].lastTime = lastTime;
    }
    if (role == 'P') // 生产者多一个参数
    {
      int products;
      scanf("%d", &products);
      cmds[threadNum].products = products;
    }
    threadNum++;
  }

  for (int i = 0; i < threadNum; i++)
  {
    if (cmds[i].role == 'P')
      printf("命令：%d %c %d %d %d\n",
             cmds[i].thread_id, cmds[i].role,
             cmds[i].startTime, cmds[i].lastTime, cmds[i].products);
    else
      printf("命令：%d %c %d %d\n",
             cmds[i].thread_id, cmds[i].role,
             cmds[i].startTime, cmds[i].lastTime);
  }

  // 2. 初始化缓冲区 buffer
  printf("\nstep 2：初始化\n");
  pthread_mutex_init(&mutex, NULL);
  sem_init(&full, 0, 0);
  sem_init(&empty, 0, BUFFER_SIZE);
  pthread_t threads[MAX_THREAD + 1];
  for (int i = 0; i < 5; i++)
    buffer[i] = 0;

  // 3. 创建线程

  printf("\nstep 3：创建线程\n");
  for (int i = 0; i < threadNum; i++)
  {
    if (cmds[i].role == 'P')
    {
      pthread_create(&threads[i], NULL, producer, &cmds[i]);
      printf("创建进程 %d ，是生产者\n", cmds[i].thread_id);
    }
    else if (cmds[i].role == 'C')
    {
      pthread_create(&threads[i], NULL, consumer, &cmds[i]);
      printf("创建进程 %d ，是消费者\n", cmds[i].thread_id);
    }
  }

  // 4. 等待结束
  printf("\nstep 4：等待线程结束\n");

  for (int i = 0; i < threadNum; i++)
  {
    pthread_join(threads[i], NULL);
  }

  // 6. 退出
  printf("\nstep 6：销毁信号量\n");
  pthread_mutex_destroy(&mutex);
  sem_destroy(&full);
  sem_destroy(&empty);
  // exit(0);
  return 0;
}

/**
 * 插入对象到缓冲区中
 * @param item buffer_item（本质上是 int）
 * @return 0成功，1失败
*/
int insertItem(buffer_item item)
{
  // printf("尝试插入元素\n");

  if (buffer[pBufferIndex] == 0)
  {
    buffer[pBufferIndex] = item;
    pBufferIndex = (pBufferIndex + 1) % BUFFER_SIZE;
    return 0;
  }
  return 1;
}

/**
 * @todo
 * 从缓冲区中删除对应的对象
 * @param threadId int ，代表线程 id
 * @return 0成功，1失败
*/
int removeItem(int threadId)
{
  if (buffer[cBufferIndex] != 0)
  {
    printf("线程 %d （消费者）：消耗 %d\n", threadId, buffer[cBufferIndex]);
    buffer[cBufferIndex] = 0;
    cBufferIndex = (cBufferIndex + 1) % BUFFER_SIZE;
    return 0;
  }
  return 1;
}

/**
 * 生产者函数
 * @param threadArg ThreadArg ，代表命令
*/
void *producer(void *param)
{
  ThreadArgs *cmd = (ThreadArgs *)param;
  sleep(cmd->startTime); // 创建后的延迟

  while (1)
  {
    sem_wait(&empty);
    pthread_mutex_lock(&mutex); // 锁了

    if (insertItem(cmd->products))
      printf("线程 %d （生产者）：插入失败\n", cmd->thread_id);
    else
    {
      printf("线程 %d （生产者）：生产 %d\n", cmd->thread_id, cmd->products);
      sleep(cmd->lastTime);
    }
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    pthread_exit(0);
  }
}

/**
 * 消费者函数
 * @param threadArg ThreadArg ，代表命令
*/
void *consumer(void *param)
{
  ThreadArgs *cmd = (ThreadArgs *)param;
  sleep(cmd->startTime);

  while (1)
  {
    sem_wait(&full);
    pthread_mutex_lock(&mutex); // 锁了

    if (removeItem(cmd->thread_id))
      printf("线程 %d （消费者）：消耗失败\n", cmd->thread_id);
    else
      sleep(cmd->lastTime);

    pthread_mutex_unlock(&mutex); // 解锁
    sem_post(&empty);
    pthread_exit(0);
  }
}