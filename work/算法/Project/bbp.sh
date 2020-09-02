#!/bin/bash
# ScriptName: bbp.sh
cppFile=$@;           # 获取参数
DataPath="./Data";    # 测试文件路径
compiler="g++";       # 编译器
txt=$(ls $DataPath);  # 获取测试文件列表

rm "./a.out";

# 如果输入为空，就提示
if [ ! -n "$cppFile" ]; then
  echo "请输入代码文件";
  exit 0;
fi

# echo $cppFile;
$($compiler $cppFile);

for file in $txt
do
  echo "测试文件为 $file";
  "./a.out" < $DataPath/$file;
  echo ;
done

