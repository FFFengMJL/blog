#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import requests
from bs4 import BeautifulSoup
import datetime



url_lib='http://sdcs.sysu.edu.cn/news/notice' #网址
#获取网页内容
html = requests.get(url_lib)
#开始时间
start = datetime.date(2018,1,1)
#截止时间
end = datetime.date(2018,12,31)
#间隔时间
delta = datetime.timedelta(days=1)

while start <= end: #循环
    date=start.strftime("%Y-%m-%d") #将时间转换成字符串
    data = {'begin':date ,'end': date} #要发送的内容
    html=requests.post(url_lib,data=data) #发送请求
    soup=BeautifulSoup(html.content) #用bs解析代码
    soup=soup.find('div') #找到指定tag及注释的内容
    print(date,end, '') #输出日期
    print(soup.get_text()) #输出soup的文本内容
    start+=delta #天数+1
#end