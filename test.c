#include <stdio.h>

#define testString "this is a 测试\
<meta http-equiv=\"Content-Type\"content=\"text/html;charset=utf-8\">"
#define testString2 "测试测试测试"

#define HTML "\
<html>\
    <head>\
        <meta charset=\"utf-8\">\
    </head>\
    <body>\
        你好\
        test\
    </body>\
</html>\
"

char testString3[] = "this is a 测试";

int main()
{
  char test[5];
  printf("%s\n", testString);
}