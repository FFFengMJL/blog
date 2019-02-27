---
layout: default
title: 程序设计
---

# 程序设计项目

## svg 项目

<blockquote style="text-align: center; ">
本项目是<br>
中山大学<br>
2018~2019学年<br>
数据科学与计算机学院（软件学院）<br>
2018级<br>
软件工程教务2班svg项目<br>
</blockquote>

<pre>
模块分成：
    1. 文本识别  
    2. svg生成  
    3. 文件输出
</pre>

### 2019.2.27

1. 将 mode_1.cpp 更名为 text_handle_ver_1.cpp  
2. 创建了 <a href="text_handle_ver_2.cpp">text_handle_ver_2.cpp</a>  
3. 加入样例 <a href="input.txt">input.txt</a> 

<pre>
关于 text_handle_ver_2.cpp :
    1. 抛弃了 text_handle_ver_1.cpp 中使用 C 风格字符串的算法
    2. 删除了全局常量 max_len_text, title_len, words_len
    3. 删除了类 Target 中 public 中的 title_exist, words_exist，通过判断 title 与 words 的长度来代替前两者原本的作用
    4. 删除了类 Target 中用于初始化变量的 ini() 函数
    5. 修改了类 Target 中用于输出文本的 print() 函数，使之更加严谨
    6. 修改 t_in() 函数，使用 string 类中的 substr() 函数来代替原本字符串的复制
    7. 删除 In() 函数中与 title_exist 与 words_exist 有关的操作
    8. 删除 main() 函数中关于 C 风格字符串的创建、输入，用 string 类进行代替
    9. 删除 main() 函数中关于 Target 中关于 ini() 的操作
</pre>

### 2019.2.26

天天吃鸡吃不胖，天天摸鱼身体棒.gif