/*
本项目是
        中山大学
      2018~2019学年
数据科学与计算机学院（软件学院）
         2018级
   软件工程教务2班svg项目

模块分成：
    1. 文本识别
    2. svg 生成

此次将尝试：
    1. 删除 <fstream> 库相关操作，使用重定向进行文本输入输出
    2. 修改算法，使得文本框靠近中间

思路：
    1. 先按照 pos_ver_1.cpp 的方式计算出坐标，同时找到图片的宽
    2. 除了最长的那一个 level，对其他每一个 level 进行重新计算

*/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int max_len = 20;//tar 二维类数组最大 len
const int max_level = 20;//tar 二维类数组最大 level
const int letter_px = 6;//每个字符长度
const int letter_add = 18;//每个边框增加的长度
const int border = 1;//边框
const int next_lv_distance = 100;//距离下一个 level 的距离
const int next_horizon_distance = 60;//距离下一个序列的水平距离
const string color_1 = "#67C23A";//title fill 的颜色
const string color_2 = "#FFFFFF";//words fill 的颜色
const string color_border = "#000000";//边框的颜色
const string color_title = "#FFFFFF";//title 文本的颜色
const string color_words = "#000000";//words 文本的颜色
const string color_line = "#000000";//折线颜色
const string fill_opacity = "0.9";//填充程度
const string font_family = "consolas";//字体选择
const double rect_height = 20;//矩形长度
const double rect_stroke = 1;//边框大小
const double line_width = 2;//线的宽度
const double line_vector = 4;//线的偏移量
const double move_px = 20;//偏移量
const int font_size = 12;//字体大小
const double title_pos[2] = {5, 14};//title 的相对定位
const double words_pos[2] = {5, 34};//words 的相对定位
double pic_width;//图片宽度
double pic_height;//图片大小

//二维类数组的使用是过于浪费资源，需要改进
//什么？你问我为什么不用链表？我不会啊5555
//使用类进行类结构体储存数据
class Target
{
public:
    string title, words;
    int blg;//表示从属的上一 level 的序列
    double pos[2];//代表页面上的坐标，[0] 是横坐标，[1] 是纵坐标
    double width;//矩形宽度

    //计算矩形的长宽
    void to_shape()
    {
        this->width = this->words.length() > this->title.length() ? this->words.length() : this->title.length();
        this->width *= letter_px;
        this->width += letter_add;
    }

    /*
    计算坐标
    a 代表同等级前一序列,用于计算水平坐标
    b 代表前一等级最初的那一个，用于计算垂直坐标
    */
    void postion(Target a, Target b)
    {
        this->pos[0] = a.pos[0] + a.width + next_horizon_distance;
        this->pos[1] = b.pos[1] + next_lv_distance;
    }
};

int t_in(string &a, string b, int b_start)//复制字符串用函数
{
    int i = b_start;
    while(b[b_start] != ' ' && b[b_start] != ')')
    {
        b_start ++;
    }
    a += b.substr(i, b_start - i);
    return b_start;
}

//文本处理，将文本分级并且确定从属的上一 lv 的序列
void In(Target tar[][max_level], string text)
{
    int level = -1;//因为从字符串的第0项开始，所以初始化为 -1 来保证第一项为 0
    int last_len_1 = 0, last_len_2 = 0;//表示从属序列
    int last_lv_1 = 0;//表示上一个 tar 的 level
    for(int i = 0; i < text.length(); i ++)
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
                if(tar[t][level].title.length() == 0)
                {
                    i = t_in(tar[t][level].title, text, i + 1);
                    //如果 title 后面存在 words，则选择读入 words
                    if(text[i + 1] != ' ' && text[i + 1] != '(')
                    {
                        i = t_in(tar[t][level].words, text, i + 1);
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
    string text;

    //读取整行
    getline(cin, text);

    //创建类数组，第一个数字代表序列，第二个代表等级
    Target tar[max_len][max_level];

    //正式开始文本解析
    In(tar, text);

    //坐标定位
    for(int lv = 0; lv < max_level; lv ++)
    {
        for(int t = 0; t < max_len; t ++)
        {
            if(tar[t][lv].title.length())//如果 tar 储存了信息
            {
                tar[t][lv].to_shape();
                if(lv && t)//如果 lv 大于1,并且序列不是第一个
                {
                    tar[t][lv].postion(tar[t-1][lv], tar[0][lv-1]);
                }
                else if(lv && t == 0)//如果 lv 大于1,但是序列是第一个
                {
                    tar[t][lv].postion(tar[0][lv - 1], tar[0][lv - 1]);
                    tar[t][lv].pos[0] = 0;//避免奇怪位移
                }
                //动态获取图片长宽（level 的最大宽度
                pic_width = pic_width > (tar[t][lv].pos[0] + tar[t][lv].width) ? pic_width : (tar[t][lv].pos[0] + tar[t][lv].width);
                pic_height = lv;
            }
        }
    }
    pic_height = (pic_height + 1) * next_lv_distance;//图片真正的高度

    //文件开始产生
    cout << "<svg xmlns:xlink=\"https://fffengmjl.github.io/blog/\" width=\""
             << pic_width
             << "\" height=\""
             << pic_height
             << "\">" << endl;

    for(int lv = 0; lv < max_level; lv ++)
    {
        for(int t = 0; t < max_len; t ++)
        {
            if(tar[t][lv].title.length())//如果该 tar 储存信息
            {
                //创建 group 标签
                cout << "\t<g transform=\"translate(" 
                         << tar[t][lv].pos[0] 
                         << ',' << ' ' 
                         << tar[t][lv].pos[1] 
                         << ")\">" <<endl;
                
                //创建 title 的 <rect> 标签
                cout << "\t\t<rect x=\"0\" y=\"0\" height=\""
                         << rect_height
                         << "\" fill=\""
                         << color_1 
                         << "\" fill-opacity=\""
                         << fill_opacity
                         << "\" stroke=\""
                         << color_border
                         << "\" stroke-width=\""
                         << border
                         << "\" width=\""
                         << tar[t][lv].width
                         <<"\"></rect>" << endl;
                
                //创建 title 的 <text> 标签
                cout << "\t\t<text font-size=\""
                         << font_size
                         << "\" x=\""
                         << title_pos[0]
                         << "\" y=\""
                         << title_pos[1]
                         << "\" fill=\""
                         << color_title
                         << "\" font-family=\""
                         << font_family
                         << "\">"
                         << tar[t][lv].title
                         << "</text>" << endl;
                
                //如果 tar 的 word 储存信息
                if(tar[t][lv].words.length())
                {
                    //创建 words 的 <rect> 标签
                    cout << "\t\t<rect x=\"0\" y=\""
                             << rect_height
                             << "\" height=\""
                             << rect_height
                             << "\" fill=\""
                             << color_2 
                             << "\" fill-opacity=\""
                             << fill_opacity
                             << "\" stroke=\""
                             << color_border
                             << "\" stroke-width=\""
                             << border
                             << "\" width=\""
                             << tar[t][lv].width
                             <<"\"></rect>" << endl;
                    
                    //创建 words 的 <text> 标签
                    cout << "\t\t<text font-size=\""
                             << font_size
                             << "\" x=\""
                             << words_pos[0]
                             << "\" y=\""
                             << words_pos[1]
                             << "\" fill=\""
                             << color_words
                             << "\" font-family=\""
                             << font_family
                             << "\">"
                             << tar[t][lv].words
                             << "</text>" << endl;
                }

                //结束 group 标签
                cout << "\t</g>" << endl << endl;
            }

            //开始生成折线
            if(lv && tar[t][lv].title.length())
            {
                cout << "\t<path d=\"M " 
                        //第一个点
                         << tar[t][lv].pos[0] + tar[t][lv].width / 2
                         << " "
                         << tar[t][lv].pos[1]
                         << " L "
                        //第二个点
                         << tar[t][lv].pos[0] + tar[t][lv].width / 2
                         << " "
                         << (tar[0][lv - 1].pos[1] + rect_height + tar[t][lv].pos[1]) / 2 + move_px
                         << " L "
                        //第三个点
                         << tar[tar[t][lv].blg][lv - 1].pos[0] + tar[tar[t][lv].blg][lv - 1].width / 2
                         << " "
                         << (tar[0][lv - 1].pos[1] + rect_height + tar[t][lv].pos[1]) / 2 - move_px
                         << " L "
                        //第四个点
                         << tar[tar[t][lv].blg][lv - 1].pos[0] + tar[tar[t][lv].blg][lv - 1].width / 2
                         << " "
                         << tar[tar[t][lv].blg][lv - 1].pos[1] + rect_height
                         << "\" stroke=\""
                         << color_line
                         << "\"stroke-width=\""
                         << line_width
                         << "\" fill=\"none\" />" << endl <<endl;
            }
        }
    }
    cout << "</svg>" << endl;//结束

    return 0;
}