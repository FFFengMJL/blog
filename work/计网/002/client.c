#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>

int MAX_LINE = 4096;
char server[] = "112.124.24.191";
int port = 443;
int send_times = 100;

int send_msg(int socket, struct sockaddr *dst, int send_times)
{
  printf("func start\n");
  socklen_t len;
  struct sockaddr_in src;
  for (int i = 0; i < send_times; i++)
  {
    char send_buff[MAX_LINE]; // 发送缓冲区
    char recv_buff[MAX_LINE]; // 接受缓冲区

    len = sizeof(*dst);
    memset(send_buff, 0, MAX_LINE);
    sprintf(send_buff, "No.%d msg\n", i);

    // 发送消息给 server
    printf("sending: %s", send_buff);
    sendto(socket, send_buff, MAX_LINE, 0, dst, len);

    // 接受来自 server 的消息
    memset(recv_buff, 0, MAX_LINE);
    printf("waiting for server response");
    recvfrom(socket, recv_buff, MAX_LINE, 0, (struct sockaddr *)&src, &len);

    printf("send success, server: %s\n", recv_buff);

    // sleep(1);
  }

  return 0;
}

int main(int argc, char **argv)
{
  int clientSock;
  struct sockaddr_in servaddr;

  printf("%d", argc);

  // need targer server ip
  if (argc != 3)
  {
    printf("use default server: %s and port: %d\n", server, port);
  }
  else
  {
    memset(server, 0, sizeof(argv[1]));
    sprintf(server, "%s", argv[1]);
    port = atoi(argv[2]);
  }

  // create socket
  clientSock = socket(AF_INET, SOCK_DGRAM, 0);
  if (clientSock == -1)
  {
    printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
    exit(0);
  }
  printf("create socket success!\n");

  // inet_pton
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  // printf("start inet_pton\n");
  // if (inet_pton(AF_INET, server, &servaddr.sin_addr) <= 0)
  // {
  //   printf("inet_pton error for %s\n", server);
  //   exit(0);
  // }
  servaddr.sin_addr.s_addr = inet_addr(server);
  printf("server: %s, port: %d\n", server, port);

  send_msg(clientSock, (struct sockaddr *)&servaddr, send_times);

  return 0;
}