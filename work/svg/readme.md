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
    1. 文本处理  
    2. svg生成  
    <del>3. 文件输出</del>
</pre>

### 2019.3.5
1. 暂时停止对模块一：文本处理 的开发与更新（摸鱼
2. 创建了 <a href="https://guthub.com/FFFengMJL/blog/blob/master/work/svg/pos_ver_1.cpp" target="_blank">pos_ver_1.cpp</a> ，可用于生成相应的 .html 文件（图

<pre>
关于 pos_ver_1.cpp:
    1. 基于 text_handle_ver_2.cpp 的使用 c++ 的字符串进行文本分析得到的数据进行进一步处理
    2. 严格按照以 level 的层级（从上到下）与序列（从左到右）进行排列（好丑哦，考虑下次搞成金字塔型
    3. 采用折线进行连接：解决了直线会覆盖到其他文本框上面的问题；并且通过偏移量解决重叠问题
    4. 加入了大量的全局常量，用于文本框、线、文本相关的布局，这些值以及字符串都是可修改的
    5. 图片像素大小采用动态生成，等级和序列的大小进行变化
    6. 删除了 Target 类中用于输出信息的 print() 函数（没用了
    7. 在 Target 类中添加了用于确定文本框大小的 to_shape() 函数；添加了用于进行坐标定位 position() 函数
    8. 使用 &lt;fstream&gt; 库中的相关对象 ostream 进行文件生成及输入
    9. 删除了 main() 函数中原本输出 tar 信息的相关操作
</pre>

### 2019.2.27

1. 将 mode_1.cpp 更名为 text_handle_ver_1.cpp  
2. 创建了 <a href="https://github.com/FFFengMJL/blog/blob/master/work/svg/text_handle_ver_2.cpp" target="_blank">text_handle_ver_2.cpp</a>  
3. 加入样例 <a href="https://github.com/FFFengMJL/blog/blob/master/work/svg/input.txt#L1" target="_blank">input.txt</a> 

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