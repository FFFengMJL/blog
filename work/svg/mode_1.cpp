/*
本项目是
        中山大学
      2018~2019学年
数据科学与计算机学院（软件学院）
         2018级
   软件工程教务2班svg项目

模块分成：
    1. 文本识别
    2. svg生成
    3. 文件输出

此次将尝试：
    1. 文本分析

思路：
    1. 读取整行
    2. 进行分级
    3. 进行步骤 2 的同时判断分支归属
    4. 储存数据
*/

#include<iostream>
#include<string.h>
#include<string>
using namespace std;

const int title_len = 20;//Target 类的 title 的最大程度
const int words_len = 20;//Target 类的 words 的最大程度
const int max_len = 5;//tar 二维类数组最大 len
const int max_level = 10;//tar 二维类数组最大 level
const int max_text_len = 500;//字符串 text 所能读取最大字符数量

//使用类进行类结构体储存数据
class Target
{
public:
    bool title_exist;//表明是否有 title 存在
    char title[title_len];
    bool words_exist;//表明是否有 words 存在
    char words[words_len];
    int blg;//表示从属的上一 level 的序列

    void ini()//所有数据初始化
    {
        title_exist = words_exist = 0;
        title[0] = words[0] = blg = 0;
    }

    void print()//输出
    {
        if(title_exist)//存在 title 则输出 title
        {
            cout << this->title << ' ';
        }
        if(words_exist)//存在 words 则输出 words
        {
            cout << this->words << ' ';
        }
        cout << this->blg << endl;//输出从属的上一 level
    }
};

int t_in(char a[], char b[], int b_start, int len)//复制字符串用函数
{
    int i;
    for(i = 0; b[b_start] != ' ' && b[b_start] != ')' && i < len; i ++, b_start ++)
    {
        a[i] = b[b_start];
    }
    a[i] = 0;
    return b_start;
}

void In(Target tar[][max_level], int start, int end, char text[])
{
    int level = -1;//因为从字符串的第0项开始，所以初始化为 -1 来保证第一项为 0
    int last_len_1 = 0, last_len_2 = 0;//表示从属序列
    int last_lv_1 = 0;//表示上一个 tar 的 level
    for(int i = start; i < end && text[i] != 0; i ++)
    {
        //出现左括号，等级上升，并同时准备进行文本输入
        if(text[i] == '(')
        {
            level ++;
            //选择该等级未读入部分
            for(int t = 0; t < max_len; t ++)
            {
                last_len_1 = t;//读取此次序列
                //此时开始输入文本
                if(tar[t][level].title_exist == 0)
                {
                    i = t_in(tar[t][level].title, text, i + 1, sizeof(tar[t][level].title)/sizeof(char));
                    tar[t][level].title_exist = 1;
                    //如果 title 后面存在 words，则选择读入 words
                    if(text[i + 1] != ' ' && text[i + 1] != '(')
                    {
                        i = t_in(tar[t][level].words, text, i + 1, sizeof(tar[t][level].words)/sizeof(char));
                        tar[t][level].words_exist = 1;
                    }
                    //储存序列
                    if(last_lv_1 == level)//与上一个 tar 同 level 的情况
                    {
                        tar[t][level].blg = tar[t - 1][level].blg;
                    }
                    else//与上一个 tar 不同 level 的情况
                    {
                        tar[t][level].blg = last_len_2;
                    }  
                    last_len_2 = last_len_1;
                    break;
                }
            }
        }
        //出现右括号，表示该 tar 读取结束，同时等级下降
        if(text[i] == ')')
        {
            last_lv_1 = level;
            level --;
        }
        else if(text[i] == '(')//避免 i 自增过头
        {
            continue;
        }
    }
}

int main()
{
    //创建字符串，用于读取整行
    char text[max_text_len] = {0};
    //string test_text;

    //读取整行
    cin.getline(text, max_text_len);
    //getline(cin, test_text);

    //创建类数组，第一个数字代表序列，第二个代表等级
    Target tar[max_len][max_level];

    //对 tar 进行初始化
    for(int i = 0; i < max_level; i ++)
    {
        for(int t = 0; t < max_len; t ++)
        {
            tar[t][i].ini();
        }
    }

    //正式开始文本解析
    In(tar, 0, strlen(text), text);

    //对解析完成的文本通过 tar 来有序输出
    for(int i = 0; i < max_level; i ++)
    {
        for(int t = 0; t < max_len; t ++)
        {
            if(tar[t][i].title_exist)
            {
                cout << "Level " << i << ' ';
                tar[t][i].print();
            }
        }
        cout << endl;
    }

    cout << text << endl;//验证文本是否读取完整
}