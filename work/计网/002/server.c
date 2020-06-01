#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <unistd.h> // 必须，因为 close() 在这个库里面

const int MAX_LINE = 4096; // 默认缓冲区大小 4M
int port = 443;            // 默认端口

// 处理 udp 信息
int handle_udp_msg(int socket)
{
  printf("func start\n");
  char recv_buff[MAX_LINE]; // 接受缓冲区
  char send_buff[MAX_LINE]; // 发送缓冲区
  int count;
  socklen_t len;
  struct sockaddr_in client_addr;

  while (1)
  {
    memset(recv_buff, 0, MAX_LINE);
    len = sizeof(client_addr);
    if (recvfrom(socket, recv_buff, MAX_LINE, 0, (struct sockaddr *)&client_addr, &len) == -1)
    {
      printf("receive data fail! error: %s(errno: %d)\n", strerror(errno), errno);
      return 0;
    }

    printf("client msg: %s\n", recv_buff);

    // 回复 client
    memset(send_buff, 0, MAX_LINE);
    sprintf(send_buff, "receive %s\n", recv_buff);
    sendto(socket, send_buff, MAX_LINE, 0, (struct sockaddr *)&client_addr, len);
    printf("server: has response %s\n", recv_buff);

    count++; // 计数，看丢包
  }

  return count;
}

int main(int argc, char **argv)
{
  int connfd;
  struct sockaddr_in servaddr;
  int n;

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

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(port);

  // bind IP and protocol
  if (bind(serverSock, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
  {
    printf("bind socket error: %s(errno: %d)\n", strerror(errno), errno);
    exit(0);
  }
  printf("bind IP(%d) and port(%d) success!\n", servaddr.sin_addr.s_addr, port);

  int num = handle_udp_msg(serverSock);

  close(serverSock);

  printf("has receive %d msgs, loss = %.2lf\n", num, (double)num / 100);
  return 0;
}
