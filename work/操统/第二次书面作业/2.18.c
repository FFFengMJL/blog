// 在 linux 上写
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFLENGTH 8192

int main(int argc, char **argv)
{
  if (argc != 3) // 参数不够
  {
    printf("usage: copy src dst\n");
    return -1;
  }
  int src, dst;
  char buffer[BUFFLENGTH];
  src = open(argv[1], O_RDONLY);
  dst = open(argv[2],
             O_RDWR | O_CREAT | O_TRUNC,   // 设置权限
             S_IRUSR | S_IWUSR | S_IXUSR); // 设置用户权限
  int tmp;
  while ((tmp = read(src, buffer, BUFFLENGTH)) > 0) // 不断读取
  {
    if (write(dst, buffer, tmp) != tmp) // 写入失败
      printf("ERROR in writing\n");
  }
  if (tmp < 0) // 读取失败
    printf("ERROR in reading\n");

  // 关闭文件
  close(src);
  close(dst);
  return 0;
}