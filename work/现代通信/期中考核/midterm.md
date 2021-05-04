# 《现代通信技术概论》期中考核

- [《现代通信技术概论》期中考核](#现代通信技术概论期中考核)
  - [一、信号带宽与信道带宽的匹配主要考虑什么因素？如果二者不匹配会产生什么影响？（20分）](#一信号带宽与信道带宽的匹配主要考虑什么因素如果二者不匹配会产生什么影响20分)
  - [二、调制的目的是什么？简述调制和解调的概念。（20分）](#二调制的目的是什么简述调制和解调的概念20分)
  - [三、在脉冲编码调制（PCM）系统中，若采用13折线A律编码，设最小量化间隔为1单位，已知抽样脉冲值为 -118 个单位，试求：此时编码器输出码组，并计算量化误差（段内码采用自然二进制码）。（20分）](#三在脉冲编码调制pcm系统中若采用13折线a律编码设最小量化间隔为1单位已知抽样脉冲值为--118-个单位试求此时编码器输出码组并计算量化误差段内码采用自然二进制码20分)
  - [四、若消息代码序列为110000010100001，画出对应的全占空双极性码波形；画出对应的AMI码波形；画出对应的HDB3码波形。（20分）](#四若消息代码序列为110000010100001画出对应的全占空双极性码波形画出对应的ami码波形画出对应的hdb3码波形20分)
  - [五、在对微波通信频率进行配置时应考虑哪些因素？（20分）](#五在对微波通信频率进行配置时应考虑哪些因素20分)

## 一、信号带宽与信道带宽的匹配主要考虑什么因素？如果二者不匹配会产生什么影响？（20分）

- 考虑因素：两者匹配最主要考虑的是频率范围（或频带）的匹配
- 不匹配的影响：信号传输失真

## 二、调制的目的是什么？简述调制和解调的概念。（20分）

- 调制的目的：
  - 把消息信号调制成适合在信道中传输的信号
  - 信道的多路复用
- 调制和解调：“携带”消息的信号称为载波信号，而被“携带”的消息称为调制信号，调制就是让消息被载波信号“携带”，解调就是从载波信号中检测出消息

## 三、在脉冲编码调制（PCM）系统中，若采用13折线A律编码，设最小量化间隔为1单位，已知抽样脉冲值为 -118 个单位，试求：此时编码器输出码组，并计算量化误差（段内码采用自然二进制码）。（20分）

结果：

```bash
____________________________________________
因为抽样脉冲值小于零，所以极性码为0
因为抽样脉冲值在[64，128)之间，所以段落码为011
该抽样脉冲值位于第(118-64)/4=13段，所以段内码为1101
根据上述分析，该抽样脉冲的编码输出为：
0  0  1  1  1  1  0  1
____________________________________________
译码输出为：64+13*4+0.5*4=118
量化误差为：
118-118=0
____________________________________________
对应于该7位码的均匀量化11位码为：
00001110110

ans =

     0     0     1     1     1     1     0     1
```

代码：

```matlab
function [coded_output,quantization_error,Uniform_quantization]=A13(Sampling_pulse_val)
%输入：抽样脉冲值
%输出：coded_output：A律13折线码编码输出；
%       quantization_error：量化误差；
%       Uniform_quantization：对应于7位码（不包含极性码）的均匀量化11位码

%dec2bin()可以将十进制转换为二进制
if abs(Sampling_pulse_val)>=2048
    error('抽样脉冲值应在0到2047之间')
end
coded_output=zeros(1,8);%定义一个1*8的矩阵，每一个元素表示量化输出的一位，分别为C0C1……C7
%C0表示极性码，C1C2C3表示段落码，C4C5C6C7表示段内码
disp('____________________________________________')
if Sampling_pulse_val>0
    disp('因为抽样脉冲值大于零，所以极性码为1')
    coded_output(1)=1;%如果抽样脉冲值为正，则极性码为1
else
    disp('因为抽样脉冲值小于零，所以极性码为0')
    coded_output(1)=0;%否则，极性码为0
end
Sampling_pulse_val=abs(Sampling_pulse_val);

%根据抽样脉冲值确定段落码
%第一段
if Sampling_pulse_val>=0 && Sampling_pulse_val<16
    start=0;%该段的起始电平
    step=1;%该段的量化间隔
    coded_output(2:4)=[0 0 0];%该段的段落码
    disp('因为抽样脉冲值在[0,16)之间，所以段落码为000')
    %第二段
else if Sampling_pulse_val>=16 && Sampling_pulse_val<32
        start=16;%该段的起始电平
        step=1;%该段的量化间隔
        coded_output(2:4)=[0 0 1];%该段的段落码
        disp('因为抽样脉冲值在[16,32)之间，所以段落码为001')
        %第三段
    else if Sampling_pulse_val>=32 && Sampling_pulse_val<64
            start=32;%该段的起始电平
            step=2;%该段的量化间隔
            coded_output(2:4)=[0 1 0];%该段的段落码
            disp('因为抽样脉冲值在[32,64)之间，所以段落码为010')
            %第四段
        else if Sampling_pulse_val>=64 && Sampling_pulse_val<128
                start=64;%该段的起始电平
                step=4;%该段的量化间隔
                coded_output(2:4)=[0 1 1];%该段的段落码
                disp('因为抽样脉冲值在[64，128)之间，所以段落码为011')
                %第五段
            else if Sampling_pulse_val>=128 && Sampling_pulse_val<256
                    start=128;%该段的起始电平
                    step=8;%该段的量化间隔
                    coded_output(2:4)=[1 0 0];%该段的段落码
                    disp('因为抽样脉冲值在[128,256)之间，所以段落码为100')
                    %第六段
                else if Sampling_pulse_val>=256 && Sampling_pulse_val<512
                        start=256;%该段的起始电平
                        step=16;%该段的量化间隔
                        coded_output(2:4)=[1 0 1];%该段的段落码
                        disp('因为抽样脉冲值在[256,512)之间，所以段落码为101')
                        %第七段
                    else if Sampling_pulse_val>=512 && Sampling_pulse_val<1024
                            start=512;%该段的起始电平
                            step=32;%该段的量化间隔
                            coded_output(2:4)=[1 1 0];%该段的段落码
                            disp('因为抽样脉冲值在[512,1024)之间，所以段落码为110')
                            %第八段
                        else if Sampling_pulse_val>=1024 && Sampling_pulse_val<2048
                                start=1024;%该段的起始电平
                                step=64;%该段的量化间隔
                                coded_output(2:4)=[1 1 1];%该段的段落码
                                disp('因为抽样脉冲值在[1024,2048)之间，所以段落码为111')
                            end
                        end
                    end
                end
            end
        end
    end
end

position=floor((Sampling_pulse_val-start)/step);%得到该抽样脉冲在段内的位置，确定段内码
switch position
    case 0
        str=['该抽样脉冲值位于第','(',num2str(Sampling_pulse_val),'-',num2str(start),')/',num2str(step),'=',num2str(position),'段，所以段内码为0000'];
        coded_output(5:8)=[0 0 0 0];
    case 1
        str=['该抽样脉冲值位于第','(',num2str(Sampling_pulse_val),'-',num2str(start),')/',num2str(step),'=',num2str(position),'段，所以段内码为0001'];
        coded_output(5:8)=[0 0 0 1];
    case 2
        str=['该抽样脉冲值位于第','(',num2str(Sampling_pulse_val),'-',num2str(start),')/',num2str(step),'=',num2str(position),'段，所以段内码为0010'];
        coded_output(5:8)=[0 0 1 0];
    case 3
        str=['该抽样脉冲值位于第','(',num2str(Sampling_pulse_val),'-',num2str(start),')/',num2str(step),'=',num2str(position),'段，所以段内码为0011'];
        coded_output(5:8)=[0 0 1 1];
    case 4
        str=['该抽样脉冲值位于第','(',num2str(Sampling_pulse_val),'-',num2str(start),')/',num2str(step),'=',num2str(position),'段，所以段内码为0100'];
        coded_output(5:8)=[0 1 0 0];
    case 5
        str=['该抽样脉冲值位于第','(',num2str(Sampling_pulse_val),'-',num2str(start),')/',num2str(step),'=',num2str(position),'段，所以段内码为0101'];
        coded_output(5:8)=[0 1 0 1];
    case 6
        str=['该抽样脉冲值位于第','(',num2str(Sampling_pulse_val),'-',num2str(start),')/',num2str(step),'=',num2str(position),'段，所以段内码为0110'];
        coded_output(5:8)=[0 1 1 0];
    case 7
        str=['该抽样脉冲值位于第','(',num2str(Sampling_pulse_val),'-',num2str(start),')/',num2str(step),'=',num2str(position),'段，所以段内码为0111'];
        coded_output(5:8)=[0 1 1 1];
    case 8
        str=['该抽样脉冲值位于第','(',num2str(Sampling_pulse_val),'-',num2str(start),')/',num2str(step),'=',num2str(position),'段，所以段内码为1000'];
        coded_output(5:8)=[1 0 0 0];
    case 9
        str=['该抽样脉冲值位于第','(',num2str(Sampling_pulse_val),'-',num2str(start),')/',num2str(step),'=',num2str(position),'段，所以段内码为1001'];
        coded_output(5:8)=[1 0 0 1];
    case 10
        str=['该抽样脉冲值位于第','(',num2str(Sampling_pulse_val),'-',num2str(start),')/',num2str(step),'=',num2str(position),'段，所以段内码为1010'];
        coded_output(5:8)=[1 0 1 0];
    case 11
        str=['该抽样脉冲值位于第','(',num2str(Sampling_pulse_val),'-',num2str(start),')/',num2str(step),'=',num2str(position),'段，所以段内码为1011'];
        coded_output(5:8)=[1 0 1 1];
    case 12
        str=['该抽样脉冲值位于第','(',num2str(Sampling_pulse_val),'-',num2str(start),')/',num2str(step),'=',num2str(position),'段，所以段内码为1100'];
        coded_output(5:8)=[1 1 0 0];
    case 13
        str=['该抽样脉冲值位于第','(',num2str(Sampling_pulse_val),'-',num2str(start),')/',num2str(step),'=',num2str(position),'段，所以段内码为1101'];
        coded_output(5:8)=[1 1 0 1];
    case 14
        str=['该抽样脉冲值位于第','(',num2str(Sampling_pulse_val),'-',num2str(start),')/',num2str(step),'=',num2str(position),'段，所以段内码为1110'];
        coded_output(5:8)=[1 1 1 0];
    case 15
        str=['该抽样脉冲值位于第','(',num2str(Sampling_pulse_val),'-',num2str(start),')/',num2str(step),'=',num2str(position),'段，所以段内码为1111'];
        coded_output(5:8)=[1 1 1 1];
end
disp(str)
disp('根据上述分析，该抽样脉冲的编码输出为：')
disp(num2str(coded_output))

%计算量化误差
%首先计算译码输出
out = start+position*step+0.5*step;%一定是正的
% if Sampling_pulse_val<0
%     out=-out;%译码输出
% end
quantization_error=Sampling_pulse_val-out;%计算量化误差
disp('____________________________________________')
str_=['译码输出为：',num2str(start),'+',num2str(position),'*',num2str(step),'+0.5*',num2str(step),'=',num2str(out)];
disp(str_)
disp('量化误差为：')
str_=[num2str(Sampling_pulse_val),'-',num2str(out),'=',num2str(quantization_error)];
disp(str_)

%计算对应的均匀量化11位码
disp('____________________________________________')
Uniform_quantization=dec2bin(abs(out),11);
disp('对应于该7位码的均匀量化11位码为：')
str_=num2str(Uniform_quantization);
disp(str_)
```

## 四、若消息代码序列为110000010100001，画出对应的全占空双极性码波形；画出对应的AMI码波形；画出对应的HDB3码波形。（20分）

$$
\begin{array}{lrrrrrrrrrrrrrrr}
    \text{消息代码} & 1 & 1 & 0 & 0 & 0 & 0 & 0 & 1 & 0 & 1 & 0 & 0 & 0 & 0 & 1 \\
    \text{全占空双极性码} & 1 & 1 & 0 & 0 & 0 & 0 & 0 & 1 & 0 & 1 & 0 & 0 & 0 & 0 & 1 \\
    \text{ami 码} & -1 & +1 & 0 & 0 & 0 & 0 & 0 & -1 & 0 & +1 & 0 & 0 & 0 & 0 & -1 \\
    \text{HDB3 中间码} & -1 & +1 & 0 & 0 & 0 & +V & 0 & -1 & 0 & +1 & -B & 0 & 0 & -V & +1 \\
    \text{HDB3 码} & -1 & +1 & 0 & 0 & 0 & +1 & 0 & -1 & 0 & +1 & -1 & 0 & 0 & -1 & +1
\end{array}
$$


## 五、在对微波通信频率进行配置时应考虑哪些因素？（20分）

- 整个频率的安排要紧凑，使得每个频段尽可能获得充分利用
- 在同一中继站中，一个单向传输信号的接收和发射必须使用不同的频率，以避免自调干扰
- 在多路微波信号传输频率之间必须留有足够的频率间隔以避免不同信道间的相互干扰
- 因微波天线和天线塔建设费用很高，多波道系统要设法共用天线，因此选用的频率配置方案应有利于天线共用，达到既能使天线建设费用低又能满足技术指标的目的
- 避免某一传输信道采用超外差式接收机的镜像频率传输信号
