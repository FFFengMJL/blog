#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <unistd.h> // 必须，因为 close() 在这个库里面
#include <arpa/inet.h>
#include <time.h>
#include <signal.h>

const int MAX_LINE = 4096;           // 默认缓冲区大小 4M
int port = 443;                      // 默认端口
static volatile int keeprunning = 1; // 与处理 ctrl + c 信号相关，用于维持循环

// 处理 ctrl + c 信号
void handler(int num)
{
  keeprunning = 0;
}

// 处理 udp 信息
int handle_udp_msg(int socket)
{
  char recv_buff[MAX_LINE]; // 接受缓冲区
  char send_buff[MAX_LINE]; // 发送缓冲区
  int count = 0;
  socklen_t len;
  struct sockaddr_in client_addr;

  // 设置超时时间
  struct timeval tv;
  tv.tv_sec = 5;
  tv.tv_usec = 0;
  setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

  // 设置中断信号
  signal(SIGINT, handler);

  while (keeprunning)
  {
    memset(recv_buff, 0, MAX_LINE);
    len = sizeof(client_addr);
    if (recvfrom(socket, recv_buff, MAX_LINE, 0, (struct sockaddr *)&client_addr, &len) <= 0)
    {
      printf("receive data fail! error: %s(errno: %d)\n", strerror(errno), errno);
      continue;
      // return count;
    }

    printf("client msg: %s", recv_buff);

    // 回复 client
    memset(send_buff, 0, MAX_LINE);
    sprintf(send_buff, "receive %s", recv_buff);
    sendto(socket, send_buff, MAX_LINE, 0, (struct sockaddr *)&client_addr, len);
    printf("server: has response %s\n", recv_buff);

    count++; // 计数，看丢包
  }

  return count;
}

int main(int argc, char **argv)
{
  struct sockaddr_in servaddr;
  int n, num;

  if (argc == 2)
  {
    port = atoi(argv[1]);
  }

  // create a Socket
  int serverSock = socket(AF_INET, SOCK_DGRAM, 0);
  if (serverSock == -1)
  {
    printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
    exit(0);
  }
  printf("create socket success!\n");

  // 设置地址
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(port);

  // 绑定 IP 和端口
  if (bind(serverSock, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
  {
    printf("bind socket error: %s(errno: %d)\n", strerror(errno), errno);
    exit(0);
  }
  printf("bind IP(%d) and port(%d) success!\n", servaddr.sin_addr.s_addr, port);

  num = handle_udp_msg(serverSock);

  close(serverSock);

  printf("has receive %d msgs, loss = %.2lf%c\n", num, 100 - (double)num, '%');
  return 0;
}
