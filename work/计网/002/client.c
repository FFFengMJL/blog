#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>

int MAX_LINE = 4096;                 // 默认缓冲区大小
char server[] = "112.124.24.191";    // 默认地址
int port = 443;                      // 默认端口
int send_times = 100;                // 默认发包次数
static volatile int keeprunning = 1; // 与处理 ctrl + c 信号相关，用于维持循环

// 处理 ctrl + c 信号
void handler(int num)
{
  keeprunning = 0;
}

// 发送信息
int send_msg(int socket, struct sockaddr *dst, int send_times)
{
  struct sockaddr_in src;
  int count = 0, sum = 0;
  socklen_t dst_len, src_len;

  // 设置超时时间
  struct timeval tv;
  tv.tv_sec = 1;
  tv.tv_usec = 0;
  setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

  // 设置中断信号
  signal(SIGINT, handler);

  for (int i = 0; i < send_times && keeprunning; i++)
  {
    char send_buff[MAX_LINE]; // 发送缓冲区
    char recv_buff[MAX_LINE]; // 接受缓冲区

    dst_len = sizeof(*dst);
    src_len = sizeof(src);

    memset(send_buff, 0, MAX_LINE);
    sprintf(send_buff, "No.%d msg\n", i);

    // 发送消息给 server
    printf("sending: %s", send_buff);
    // sendto(socket, send_buff, MAX_LINE, 0, dst, len);
    if (sendto(socket, send_buff, MAX_LINE, 0, dst, dst_len) <= 0)
    {
      printf("send msg error: %s(errno: %d)\n\n", strerror(errno), errno);
      continue;
    }
    else
      sum++;

    // 接受来自 server 的消息
    memset(recv_buff, 0, MAX_LINE);
    printf("waiting for server response\n");
    if (recvfrom(socket, recv_buff, MAX_LINE, 0, (struct sockaddr *)&src, &src_len) <= 0)
    {
      printf("receive msg from server error: %s(errno: %d)\n\n", strerror(errno), errno);
      // continue;
      continue;
    }
    else
    {
      printf("receive response success, server: %s", recv_buff);
      count++;
    }

    printf("\n");

    // sleep(1);
  }

  printf("send %d msgs, response %d msgs\n", sum, count);

  return 0;
}

int main(int argc, char **argv)
{
  int clientSock;
  struct sockaddr_in servaddr;

  printf("%d", argc);

  // 查看是否带参数
  if (argc == 3) // 参数完整时
  {
    memset(server, 0, sizeof(argv[1]));
    sprintf(server, "%s", argv[1]);
    port = atoi(argv[2]);
  }
  else if (argc == 2) // 参数只有一个，必须是 ip
  {
    memset(server, 0, sizeof(argv[1]));
    sprintf(server, "%s", argv[1]);
  }
  printf("use server: %s and port: %d\n", server, port);

  // create socket
  clientSock = socket(AF_INET, SOCK_DGRAM, 0);
  if (clientSock == -1)
  {
    printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
    exit(0);
  }
  printf("create socket success!\n");

  // 设置 servaddr
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  servaddr.sin_addr.s_addr = inet_addr(server);
  printf("server: %s, port: %d\n", server, port);

  send_msg(clientSock, (struct sockaddr *)&servaddr, send_times);

  return 0;
}